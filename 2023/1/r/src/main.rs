use std::fs::read_to_string;

use parseline::pars_cal_val;
mod parseline;

fn main() {
    let running_sum: u32 = read_to_string("../input.txt")
        .unwrap()
        .lines()
        .map(|x| pars_cal_val(x))
        .sum();

    println!("{}", running_sum);
}
