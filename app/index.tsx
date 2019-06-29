import React from 'react';
import { AppRegistry } from 'react-native';
import { Provider } from 'react-redux';
import { applyMiddleware, createStore, Store } from 'redux';
import thunk from 'redux-thunk';
import { name as appName } from './app.json';
import { AppNavigator } from './navigation/mainNavigation';
import rootReducer from './reducers/todoApp';
import { State } from './types/globalTypes.js';
import { Actions } from './types/index.js';

const store: Store<State, Actions> = createStore(
  rootReducer,
  applyMiddleware(thunk)
);

const App = () => (
  <Provider store={store}>
    <AppNavigator />
  </Provider>
);

AppRegistry.registerComponent(appName, () => App);
