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
    let mut prev_dial: isize = 50;
    let mut p1 = 0;
    let mut p2 = 0;

    for (idx, line) in input.lines().enumerate() {
        let cmd: Command = Command::try_from(line)?;

        dial = match cmd {
            Command::R(r) => dial.checked_add(r).unwrap(),
            Command::L(l) => dial.checked_sub(l).unwrap(),
        };

        if dial > 99 {
            dial -= 100 * (dial / 100);
        }
        if dial < 0 {
            dial += 100 * ((-dial + 100) / 100);
        }

        if dial == 0 {
            p1 += 1;
        }

        info!(
            "{idx} - {prev_dial} {} = {dial} -> p1 {p1} p2 {p2}",
            match cmd {
                Command::R(n) => format!("+{n}"),
                Command::L(n) => format!("-{n}"),
            }
        );

        prev_dial = dial;
    }

    Ok((p1, p1 + p2))
}
