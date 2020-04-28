const TARGET = process.env.npm_lifecycle_event;

if (TARGET === 'build:dev' || TARGET === 'dev' || !TARGET) {
    module.exports = require('./config/webpack.config.dev.js');
} else {
    module.exports = require('./config/webpack.config.prod.js');
}