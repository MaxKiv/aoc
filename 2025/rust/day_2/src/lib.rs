const MAX_SAFE_LEVEL_DIFF: usize = 3;

#[derive(Debug)]
struct Report {
    levels: Vec<usize>,
}

impl From<&str> for Report {
    fn from(value: &str) -> Self {
        let vec = value
            .split_whitespace()
            .fold(Vec::<usize>::new(), |mut acc, el| {
                acc.push(
                    el.parse()
                        .unwrap_or_else(|_| panic!("Cant parse this level to usize: {el}")),
                );
                acc
            });

        Report { levels: vec }
    }
}

impl Report {
    // I tried :(
    fn is_safe_unreadable_slower(&self) -> bool {
        let levels = &self.levels;

        let mut sequence_is_ascending = None;
        let mut previous_level = levels[0];
        for level in levels[1..].iter() {
            match (*level).cmp(&previous_level) {
                std::cmp::Ordering::Less => {
                    if sequence_is_ascending.is_none() {
                        sequence_is_ascending = Some(false);
                    } else if sequence_is_ascending.is_some_and(|ascending| !ascending) {
                        if previous_level - level > MAX_SAFE_LEVEL_DIFF {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
                std::cmp::Ordering::Greater => {
                    if sequence_is_ascending.is_none() {
                        sequence_is_ascending = Some(true);
                    } else if sequence_is_ascending.is_some_and(|ascending| ascending) {
                        if level - previous_level > MAX_SAFE_LEVEL_DIFF {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }

                std::cmp::Ordering::Equal => {
                    return false;
                }
            }

            previous_level = *level;
        }
        true
    }
}

fn level_is_safe(level: &[usize]) -> bool {
    let all_decreasing = level
        .iter()
        .zip(level.iter().skip(1))
        .all(|(current, next)| current > next);
    let all_increasing = level
        .iter()
        .zip(level.iter().skip(1))
        .all(|(current, next)| current < next);
    let all_level_safe = level
        .iter()
        .zip(level.iter().skip(1))
        .all(|(current, next)| current.abs_diff(*next) <= MAX_SAFE_LEVEL_DIFF);
    all_level_safe && (all_increasing || all_decreasing)
}

pub fn solve(input: &str) -> (usize, usize) {
    let p1 = input
        .lines()
        .map(Report::from)
        .filter(|report| level_is_safe(&report.levels))
        .count();

    let p2 = input
        .lines()
        .map(Report::from)
        .filter(|report| {
            level_is_safe(&report.levels)
                || 
            // check all permutations with 1 level removed
            (0..report.levels.len())
                    .map(|idx| {
                        let mut level = report.levels.clone();
                        level.remove(idx);
                        level
                    })
                    .any(|level| level_is_safe(&level))
        })
        .count();

    (p1, p2)
}
