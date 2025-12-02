use tracing::info;

#[derive(Debug)]
pub enum Command {
    R(isize),
    L(isize),
}

impl TryFrom<&str> for Command {
    type Error = anyhow::Error;

    fn try_from(value: &str) -> Result<Self, Self::Error> {
        use Command::*;
        if let Some((c, n)) = value.split_at_checked(1) {
            match c.chars().next() {
                Some('R') => Ok(R(n.parse()?)),
                Some('L') => Ok(L(n.parse()?)),
                bad => anyhow::bail!("Wrong input: {bad:?}"),
            }
        } else {
            anyhow::bail!("wrong input: {value:?}");
        }
    }
}

pub fn run(input: &str) -> anyhow::Result<(usize, usize)> {
    let mut dial: isize = 50;
    let mut cnt_p1 = 0;

    let mut prev = 0;
    let mut cnt_p2 = 0;

    for (idx, line) in input.lines().enumerate() {
        let cmd: Command = Command::try_from(line)?;

        dial = match cmd {
            Command::R(r) => dial.checked_add(r).unwrap(),
            Command::L(l) => dial.checked_sub(l).unwrap(),
        };

        if dial % 100 == 0 {
            cnt_p1 += 1;
        }

        let reduce = dial / 100;
        if prev != reduce {
            cnt_p2 += prev.abs_diff(reduce)
        }
        info!("{idx} - {cmd:?} prev {prev} dial {dial} reduce {reduce} -> p1 {cnt_p1} p2 {cnt_p2}");

        prev = reduce;
    }

    Ok((cnt_p1, cnt_p1 + cnt_p2))
}
