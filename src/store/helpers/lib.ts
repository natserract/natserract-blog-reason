
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

            let match_1 = empty_str.match(regex),
                match_2 = match_1.join("").match(regex_sec).join(","),
                result = match_2.replace(regex_third, '').split(",").slice(1);

            return result
        })
};

export async function findMarkdownPath(path: string[]): Promise<any> {
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

                // Checking if md file has decription 
                if(empty_str !== "") {
                    let match_1 = empty_str.match(regex_md).join(""),
                        match_2 = match_1.replace(regex_md_sec, ''),
                        result = match_2.replace(regex_md_third, '');
        
                    empty_arr.push(result);
                } else {
                    empty_arr.push("");
                }
    
            })
    
        .catch(err => {
            console.error(err);
        });
    }


    return empty_arr
}