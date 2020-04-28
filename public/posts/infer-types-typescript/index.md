<!-- Description: Using infer in TypeScript -->

# Infer Types - TypeScript

Ini ceritanya mau buat catatan episode berlanjut tentang TS mulai dari beginner sampai advanced hehe, untuk first time lagi coba latihan [infer types](https://www.typescriptlang.org/docs/handbook/release-notes/typescript-2-8.html), iseng2 liat dokumentasi Rust, ada tipe data [`Result`](https://doc.rust-lang.org/std/result/index.html) dan [`Option`](https://doc.rust-lang.org/std/option/index.html).

### Result
Singkatnya, tipe data `Result` adalah tipe data yang mewakili 2 result yaitu `Ok()` sama `Err()` artinya resultnya ada 2, berhasil sama tidak. Jadi tipe data ini sangat useful untuk masalah menghandle error di `expression/function` kamu, contoh casenya mirip seperti `try catch` pada javascript.

Berikut kodenya (Rust):
```rust
#[derive(Debug)]
enum Version { Version1, Version2 }

fn parse_version(header: &[u8]) -> Result<Version, &'static str> {
    match header.get(0) {
        None => Err("invalid header length"),
        Some(&1) => Ok(Version::Version1),
        Some(&2) => Ok(Version::Version2),
        Some(_) => Err("invalid version"),
    }
}

let version = parse_version(&[1, 2, 3, 4]);
match version {
    Ok(v) => println!("working with version: {:?}", v),
    Err(e) => println!("error parsing header: {:?}", e),
}
```

### Option
Nah kalo `Option`, sebenernya ini ibarat `null/undefined` di javascript, jadi merupakan data opsional alias (datanya bisa ada bisa engga), karena di Rust ga ada yg namanya tipe data null, *because it's not safe* hehe.

Berikut kodenya (Rust):

```rust
let optional = None;
check_optional(optional);

let optional = Some(Box::new(9000));
check_optional(optional);

fn check_optional(optional: Option<Box<i32>>) {
    match optional {
        Some(p) => println!("has value {}", p),
        None => println!("has no value"),
    }
}
```
Eh, wait artikelnya belum kelar, masi ada dibawahnya..................................................................................................................................................................................................................................................................

## TypeScript
Nah dibagian ini kita coba ngimplementasiin kode diatas pake TypeScript, sebelumnya bisa baca ini dulu pake refreshing [ts handbook, infer types](https://www.typescriptlang.org/docs/handbook/release-notes/typescript-2-8.html). 

Kali ini saya akan menjelaskan bagian terpentingnya saja, sisanya bisa dicari di docnya, atau discuss langsung di komentar yaaa;). Mulai dari `Result`, berikut kodenya:

### Result (TS)

```ts
type Err = Error;

type Result<A, B> = 
    A extends Err ? B : A | B; 

type TypeOfReturn<T> = ReturnType<() => T>;

function Ok<T>(callable: () => T): TypeOfReturn<T> {
    return callable()
}
function Err( callable: () => any): Error {
    throw new Error(callable())
}
function guess(t: number): Result<boolean, Error>{
   switch (t<1 || t > 10) {
       case true: {
           return Ok<boolean>(() => true)
       }
       case false: {
           return Err(() => "This is a terrible mistake!")
       }
   }
};
```

```ts
type Result<A, B> = 
    A extends Err ? B : A | B; 
```
Tipe data `Result` punya 2 parameter, `A, B`, isinya berupa conditional types bahwa jika parameter A punya tipe data `Error`, jika `!true` make isi tipe data ini adalah sebuah union types `A | B`. 

Note: sebelumnya kalian baca ini juga yaa [generic types](https://www.typescriptlang.org/docs/handbook/generics.html).



### Option (TS)
```ts

type Option<A, B> =
    A extends (infer A) ? A | B | undefined : never;

type TypeOfReturn<T> = ReturnType<() => T>;
type TypeOfReturnUndefined<T> = ReturnType<() => T> | ReturnType<() => undefined>;

function Some<T>(callable: () => T): TypeOfReturn<T> {
    return callable()
}
function None<T>(optionalCallable?: () => T | undefined): TypeOfReturnUndefined<T> {
    return (optionalCallable === undefined) ? undefined : optionalCallable();
}

function check(n: number): Option<number, boolean> {
    if (n > 25) {
        return Some<number>(() => n)
    } else {
        return None<boolean>(() => false)
    }
}
```
Kalo option, karena sifatnya *nullable* maka perlu tambahan `undefined`, jadi ini digunain ketika function `None()` dipanggil, sifatnya ada 2, bisa `undefined` ataupun ada sebuah nilai, ataupun expression didalamnya.

Okay, semoga bermanfaat. Kalo mau coba2 kalian bisa rebuild code ini menjadi lebih singkat ya, atau mungkin ada yg bisa diperbaiki *feel free to discuss* ;)

Gist github:  [Challenge_01](https://gist.github.com/alfinsuryaS/81b6808eef4fbf9dab5f80212898aded) | [Challenge_01_1](https://gist.github.com/alfinsuryaS/ff8e12ac5e9eca7ac3e186d3deb8f980)