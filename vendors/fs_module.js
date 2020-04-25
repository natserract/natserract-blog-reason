/*
  Script for readDir in posts/, before i'm using fs from node
  It's getting error, because server script can't run on browser

  So, I'm using fetch from scanning local directory
  And filter that's using regex, ånd finally 
  save to localstorage
*/

const regex = /title=\"[^\"]*?\"[^>]*?/g;
const regex_sec = /\"[^\"]*\"[^]*?/g;
let empty_str = "";

fetch('posts/', { mode: 'no-cors' })
    .then(res => res.text())
    .then(data => {
        empty_str = data;

        let res_str = empty_str.match(regex);
        let regex_result_str = res_str.join("").match(regex_sec).join(",");
        let final_result = regex_result_str.replace(/\"[^\"]*?/g, '').split(",").slice(1);

        localStorage.setItem("dirs", JSON.stringify(final_result));

    })
    .catch(err => console.error(err));

