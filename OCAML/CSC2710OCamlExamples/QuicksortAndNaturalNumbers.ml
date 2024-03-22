open List;; (* like import List.*; in Java *)
(* quicksort in OCaml *)
let neg f x = not (f x);;

let gt5 x = (x > 5);;

neg gt5;;

let partition f l = (filter f l, filter (neg f) l);;

partition gt5 [4;6;7;8;5;1;2;3];;

let rec sort xs =
  match xs with 
    | [] -> []
    | (pivot::t) -> let (l, r) = partition ((>) pivot) t in
          (sort l)@(pivot::(sort r));;

(* quicksort is polymorphic *)
		  
sort [1;4;8;2;6;5;3;7];;

sort ["Wallace";"Briana";"Max";"Dulce";"Elias";"Mariah";"Cory";"Kalynn"];;

sort ["Wallace";"Briana";"Max";"Dulce";"Elias";"Mariah";"Cory";"Jenny"];;

sort [1.2;4.5;8.3;2.1;6.7;5.4;3.8;7.6];;

3 + 5;;

3.2 +. 5.7;;
(* 3 +. 5;; *) (* gives an error *)

(* Although OCaml does type inference to determine many type definitions
 * automatically, you can define your own types. *)

(* Natural numbers defined recursively *)
type nat =  | Zero | Succ of nat;;

(* convert from natural number to its corresponding integer *)
(* pattern matching is used *)
let rec to_int n = match n with 
  | Zero -> 0
  | Succ m -> 1 + to_int m;;

to_int(Zero);;
to_int(Succ(Zero));;
to_int(Succ(Succ(Zero)));;
to_int (Succ(Succ(Succ(Zero))));;

(* convert from integer to its corresponding natural number *)
let rec int_to_nat i = match i with
  | 0 -> Zero
  | x -> Succ(int_to_nat(x-1));;

int_to_nat 0;;
int_to_nat 1;;
int_to_nat 2;;
int_to_nat 3;;

(* fails for negative integers *)
int_to_nat (-1);;

(* negative integers will correspond to zero here *)
let rec int_to_nat_fixed i = if i <= 0 then Zero else Succ(int_to_nat_fixed (i-1));;

int_to_nat_fixed (-1);;

int_to_nat_fixed (-1000);;



