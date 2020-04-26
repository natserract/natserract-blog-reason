

let globalStyles = {j|
    body {
        margin: 0 auto;
        padding: 0;
        max-width: 50%;
        font-family: sans-serif;
        font-weight: 300;
        font-size: 16px;
        font-family: serif;
        height: 100%;
        background: #dcf1d5;
    }
    html:before {
        content: '';
        position: absolute;
        left: 0;
        bottom: 0;
        width: 100%;
        height: 100%;
        background: url(../../assets/img/bg-dots.png);
        opacity: .4;
    }
    html {
        height: 100%;
    }
|j};