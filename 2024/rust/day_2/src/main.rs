use day_2::run;
use std::fs;

fn main() {
    let input = fs::read_to_string("day_2/input").unwrap();
    let (p1, p2) = run(&input);
    println!("part 1: {}", p1);
    println!("part 2: {}", p2);
}

#[test]
fn example() {
    let example = fs::read_to_string("example").unwrap();
    let (p1, _) = run(&example);
    assert_eq!(p1, 2);
}

#[test]
fn p1() {
    let string = fs::read_to_string("input").unwrap();
    let (p1, _) = run(&string);
    assert_eq!(p1, 2);
}
