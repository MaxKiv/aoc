use std::fs;

use day_3::solve;

fn main() {}

#[test]
fn p1_example() {
    let input = fs::read_to_string("example").unwrap();
    let (p1, _) = solve(&input);
    assert_eq!(p1, 161);
}
