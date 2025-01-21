const MAX_SAFE_LEVEL_DIFF: usize = 3;

#[derive(Debug)]
struct Report {
    levels: Vec<usize>,
}

impl From<&str> for Report {
    fn from(value: &str) -> Self {
        // 7 6 4 2 1
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
    fn is_safe(&self) -> bool {
        let levels = &self.levels;
        let is_descending = levels.iter().is_sorted_by(|lhs, rhs| lhs > rhs);

        for (current, next) in levels.iter().zip(levels.iter().skip(1)) {
            let diff = if is_descending {
                current.checked_sub(*next)
            } else {
                next.checked_sub(*current)
            };

            if diff.is_none_or(|diff| diff == 0 || diff > MAX_SAFE_LEVEL_DIFF) {
                return false;
            }
        }
        true
    }
}

pub fn run(input: &str) -> (usize, usize) {
    let mut p1 = 0;
    for line in input.lines() {
        let report = Report::from(line);
        if report.is_safe() {
            p1 += 1;
        }
    }

    (p1, 0)
}
