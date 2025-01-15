use day_1::run;
use divan::black_box;
use std::fs;

fn main() {
    let input = fs::read_to_string("day_1/input").unwrap();
    let (p1, p2) = run(&input);
    println!("part 1: {}", p1);
    println!("part 2: {}", p2);
}

#[test]
fn example() {
    let example = fs::read_to_string("example").unwrap();
    let (p1, _) = run(&example);
    assert_eq!(p1, 11);
}

#[divan::bench]
fn bench(bencher: divan::Bencher) {
    bencher.bench(|| {
        let input = fs::read_to_string("day_1/input").unwrap();
        day_1::run(black_box(&input));
    });
}
