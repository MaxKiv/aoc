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
    // let mut c1: Vec<usize> = Vec::with_capacity(1000);
    // let mut c2: Vec<usize> = Vec::with_capacity(1000);

    let mut dial = 50isize;
    let mut cnt = 0;

    for line in input.lines() {
        let cmd: Command = Command::try_from(line)?;

        dial = match cmd {
            Command::R(r) => dial + r,
            Command::L(l) => dial - l,
        };

        if dial < 0 {
            dial += 100;
        }
        if dial > 99 {
            dial -= 100;
        }
        if dial == 0 {
            cnt += 1;
        }
    }

    Ok((cnt, 0))
}
