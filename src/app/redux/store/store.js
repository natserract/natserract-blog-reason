

var React = require('react');
var { Provider } = require('react-redux');
var { store } = require('../helpers/functions');

function AppProvider({ children }) {
    return (
        <Provider store={store}>
            { children }
        </Provider>
    );
};


module.exports = AppProvider;