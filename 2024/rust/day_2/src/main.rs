use day_2::solve;
use std::fs;

fn main() {
    let input = fs::read_to_string("day_2/input").unwrap();
    let (p1, p2) = solve(&input);
    println!("part 1: {}", p1);
    println!("part 2: {}", p2);
}

#[test]
fn p1_example() {
    let example = fs::read_to_string("example").unwrap();
    let (p1, _) = solve(&example);
    assert_eq!(p1, 2);
}

#[test]
fn p2_example() {
    let example = fs::read_to_string("example").unwrap();
    let (_, p2) = solve(&example);
    assert_eq!(p2, 4);
}

#[test]
fn p1() {
    let string = fs::read_to_string("input").unwrap();
    let (p1, _) = solve(&string);
    assert_eq!(p1, 483);
}

#[test]
fn p2() {
    let string = fs::read_to_string("input").unwrap();
    let (_, p2) = solve(&string);
    assert_eq!(p2, 483);
}
