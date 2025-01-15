pub fn run(input: &str) -> (usize, usize) {
    let mut c1: Vec<usize> = Vec::with_capacity(1000);
    let mut c2: Vec<usize> = Vec::with_capacity(1000);

    for line in input.lines() {
        let mut tokens = line.split_whitespace();
        c1.push(tokens.next().unwrap().parse().unwrap());
        c2.push(tokens.next().unwrap().parse().unwrap());
    }

    c1.sort();
    c2.sort();

    let out = c1.into_iter().zip(c2).map(|(c1, c2)| c1.abs_diff(c2)).sum();
    (out, 0)
}
