
module PostTypes = {
    type t = {
        title: string,
        source: string,
        abstract: string,
        url: string,
        multimedia: string
    }
};

type post = {
    t: array(PostTypes.t),
};


