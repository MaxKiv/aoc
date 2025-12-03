use day_1::run;
use std::fs;
use tracing_subscriber::FmtSubscriber;

fn main() {
    let subscriber = FmtSubscriber::builder()
        // all spans/events with a level higher than TRACE (e.g, debug, info, warn, etc.)
        // will be written to stdout.
        .with_max_level(tracing::Level::INFO)
        .without_time()
        .finish();

    tracing::subscriber::set_global_default(subscriber)
        .expect("setting default tracing subscriber failed");

    let input = fs::read_to_string("day_1/input").unwrap();
    match run(&input) {
        Ok((p1, p2)) => {
            println!("part 1: {}", p1);
            println!("part 2: {}", p2);
        }
        Err(err) => println!("run error: {err}"),
    }
}

#[test]
fn p1() -> anyhow::Result<()> {
    let example = fs::read_to_string("example").unwrap();
    let (p1, _) = run(&example)?;
    assert_eq!(p1, 3);
    Ok(())
}
#[test]
fn p2() -> anyhow::Result<()> {
    let example = fs::read_to_string("example").unwrap();
    let (_, p2) = run(&example)?;
    assert_eq!(p2, 6);
    Ok(())
}
