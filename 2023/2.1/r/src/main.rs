use std::fs::read_to_string;

mod game;
use game::*;

fn main() {
    let ref_bag = Bag {
        red: 12,
        blue: 14,
        green: 13,
    };

    let mut running_sum: u32 = 0;
    for line in read_to_string("../input.txt").unwrap().lines() {
        let curr_game = from_string(line);
        if is_game_possible(&ref_bag, &curr_game) {
            running_sum += curr_game.id as u32;
        }
    }
    println!("{}", running_sum);
}
