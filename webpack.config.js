module.exports = {
  entry: './app/frontend/src/js/app.js',
  output: {
    path: './app/assets/javascripts/',
    filename: 'bundle.js',
    publicPath: "/assets/"
  },
  module: {
    loaders: [{
      test: /\.js$/,
      exclude: /node_modules/,
      loader: 'babel',
      query: {
        presets:['react', 'es2015']
      }
    }]
  }
};
