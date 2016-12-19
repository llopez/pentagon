import { createStore, applyMiddleware } from 'redux';
import listReducer from './reducers/ListReducer';
import thunk from 'redux-thunk';

const middleware = applyMiddleware(thunk);
const store = createStore(listReducer, middleware);


export default store;
