use std::fs::read_to_string;

mod dial;
use dial::*;

fn parse_dial_rotation(line: &str) -> (Direction, u16) {
    let dir: &char = &line.chars().nth(0).unwrap();
    let num = &line[1..];
    match dir {
        'R' => (Direction::Right, num.parse().unwrap()),
        'L' => (Direction::Left, num.parse().unwrap()),
        _ => (Direction::Right, 0),
    }
}

fn main() {
    let mut dial = Dial {
        position: 50,
        zero_position: 0,
    };
    let content = read_to_string("../input.txt").unwrap();
    let lines = content.lines();
    for line in lines {
        let mov = parse_dial_rotation(line);
        rot_dial(&mut dial, mov.0, mov.1);
    }

    println!("{}", dial.zero_position);
}
