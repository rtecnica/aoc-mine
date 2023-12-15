use std::fs::read_to_string;

mod parseline;
use parseline::pars_cal_val;

mod replaceline;
use replaceline::replaceline;

fn main() {
    let running_sum: u32 = read_to_string("../input.txt")
        .unwrap()
        .lines()
        .map(|x| replaceline(x.to_string()))
        .map(|x| pars_cal_val(&x))
        .sum();
    println!("{}", running_sum);
}
