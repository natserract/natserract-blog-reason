
export async function findDirectory(
    path: string,
) {
    const regex = /title=\"[^\"]*?\"[^>]*?/g;
    const regex_sec = /\"[^\"]*\"[^]*?/g;
    const regex_third = /\"[^\"]*?/g;

    let empty_str = "";

    return fetch(path, { mode: 'no-cors' })
        .then(res => res.text())
        .then(data => {
            empty_str = data;

            let match_1 = empty_str.match(regex);
            let match_2 = match_1.join("").match(regex_sec).join(",");
            let result = match_2.replace(regex_third, '').split(",").slice(1);

            return result
        })
};

export async function findMDFile(path: string[]): Promise<any> {
    var empty_arr = [];
    var empty_str = "";
    
    const regex_md = /(?=<!--)([\s\S]*?)-->/g;
    const regex_md_sec = /[<!-->]/g;
    const regex_md_third = /((?:|[^:]+[:])*)/g;

    for (let entry of path) {
        const path_dir = `../../../posts/${entry}/index.md`;

        await fetch(path_dir, { mode: 'no-cors' })
            .then(res => res.text())
            .then(data => {
                empty_str = data;
                let match_1 = empty_str.match(regex_md).join("");
                let match_2 = match_1.replace(regex_md_sec, '');
                let result = match_2.replace(regex_md_third, '');
    
                empty_arr.push(result);
    
            })
    
        .catch(err => {
            console.error(err);
        });
    }


    return empty_arr
}