const path = require('path');
const HtmlWebPackPlugin = require("html-webpack-plugin");

module.exports = {
  entry: './src/index.bs.js',
  // If you ever want to use webpack during development, change 'production'
  // to 'development' as per webpack documentation. Again, you don't have to
  // use webpack or any other bundler during development! Recheck README if
  // you didn't know this
  mode: 'development',
  output: {
    path: path.join(__dirname, "dist"),
    filename: 'index.production.js',
  },
  devServer: {
    contentBase: path.join(__dirname, '/'),
    compress: true,
    port: 9000
  },
  performance: {
    maxAssetSize: 400000
  },
  devtool: 'inline-source-map',
  resolve: {
    // Add `.ts` and `.tsx` as a resolvable extension.
    extensions: [".ts", ".tsx", ".js"]
  },
  module: {
    rules: [
      {
        test: /\.md$/,
        use: [
            {
                loader: "html-loader"
            },
            {
                loader: "markdown-loader",
            }
        ]
    },
    {
      test: /\.(js|jsx)$/,
      exclude: /node_modules/,
      use: {
        loader: "babel-loader"
      }
    },
    {
      test: /\.(png|jpe?g|gif|svg)$/i,
      use: [
        {
          loader: 'file-loader',
        },
      ],
    },
    {test: /\.ts$/, exclude: /node_modules/, loader: 'ts-loader'}
  ]
  },
  plugins: [
    new HtmlWebPackPlugin({
      template: "./index.html",
      filename: "./index.html"
    }),
  ],
  node: { fs: 'empty' },
  target: 'web',
};