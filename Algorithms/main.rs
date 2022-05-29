use std::io;

fn main() {
    let s: String = get();
    let s: i32 = recursive_digit_sum(s);
    println!("{}", s);
}

fn get() -> String {
    println!("Insira os dados:");
    let mut n: String = String::new();
    io::stdin().read_line(&mut n).unwrap();
    n
}

fn recursive_digit_sum(s: String) -> i32 {
    let vec: Vec<&str> = s.split(" ").collect();
    let mut n: String = vec[0].to_string();
    let k: i32 = vec[1].trim().parse().unwrap();
    let mut nn: i32 = 0;

    for _i in 0..k {
        nn += n
            .chars()
            .into_iter()
            .map(|x| x.to_string().parse::<i32>().unwrap())
            .fold(0, |a, b| a + b);
    }

    n = nn.to_string();

    let mut total: i32 = 10;
    while total >= 10 {
        total = n
            .chars()
            .into_iter()
            .map(|x| x.to_string().parse::<i32>().unwrap())
            .fold(0, |a, b| a + b);
        n = total.to_string();
    }
    total
}
