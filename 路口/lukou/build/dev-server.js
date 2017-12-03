require('./check-versions')()

var config = require('../config')
if (!process.env.NODE_ENV) {
  process.env.NODE_ENV = JSON.parse(config.dev.env.NODE_ENV)
}

var opn = require('opn')
var path = require('path')
var express = require('express')
var webpack = require('webpack')
var proxyMiddleware = require('http-proxy-middleware')
var webpackConfig = require('./webpack.dev.conf')

// default port where dev server listens for incoming traffic
var port = process.env.PORT || config.dev.port
// automatically open browser, if not set will be false
var autoOpenBrowser = !!config.dev.autoOpenBrowser
// Define HTTP proxies to your custom API backend
// https://github.com/chimurai/http-proxy-middleware
var proxyTable = config.dev.proxyTable

const app = express()

var lukouData = require("../data/data.json")

var tuanData = require("../data/tuangou.json")

var youhuiData = require("../data/youhui.json")

var haowuData = require("../data/haowu.json")

var taolunData = require("../data/taolun.json")

var data = lukouData.data

var banner = tuanData.banner

var list = tuanData.list

var listano = tuanData.listano

var categories=youhuiData.categories

var youhuilist=youhuiData.list

var youhuilistano=youhuiData.listano

var haowulist=haowuData.list

var haowucategories=haowuData.categories

var taolunlist=taolunData.list

var apiRouter = express.Router()

app.use('/api',apiRouter)

apiRouter.get('/data',function (req,res) {
  res.json({
    error:0,
    data:data
  })
})

apiRouter.get('/tuanbanner',function (req,res) {
  res.json({
    error:0,
    data:banner
  })
})

apiRouter.get('/categories',function (req,res) {
  res.json({
    error:0,
    data:categories
  })
})

apiRouter.get('/youhuilist',function (req,res) {
  res.json({
    error:0,
    data:youhuilist
  })
})

apiRouter.get('/tuanlist',function (req,res) {
  res.json({
    error:0,
    data:list
  })
})

apiRouter.get('/tuanlistano',function (req,res) {
  res.json({
    error:0,
    data:listano
  })
})

apiRouter.get('/youhuilistano',function (req,res) {
  res.json({
    error:0,
    data:youhuilistano
  })
})

apiRouter.get('/haowulist',function (req,res) {
  res.json({
    error:0,
    data:haowulist
  })
})

apiRouter.get('/haowucategories',function (req,res) {
  res.json({
    error:0,
    data:haowucategories
  })
})

apiRouter.get('/taolunlist',function (req,res) {
  res.json({
    error:0,
    data:taolunlist
  })
})

var compiler = webpack(webpackConfig)

var devMiddleware = require('webpack-dev-middleware')(compiler, {
  publicPath: webpackConfig.output.publicPath,
  quiet: true
})

var hotMiddleware = require('webpack-hot-middleware')(compiler, {
  log: false,
  heartbeat: 2000
})
// force page reload when html-webpack-plugin template changes
compiler.plugin('compilation', function (compilation) {
  compilation.plugin('html-webpack-plugin-after-emit', function (data, cb) {
    hotMiddleware.publish({ action: 'reload' })
    cb()
  })
})

// proxy api requests
Object.keys(proxyTable).forEach(function (context) {
  var options = proxyTable[context]
  if (typeof options === 'string') {
    options = { target: options }
  }
  app.use(proxyMiddleware(options.filter || context, options))
})

// handle fallback for HTML5 history API
app.use(require('connect-history-api-fallback')())

// serve webpack bundle output
app.use(devMiddleware)

// enable hot-reload and state-preserving
// compilation error display
app.use(hotMiddleware)

// serve pure static assets
var staticPath = path.posix.join(config.dev.assetsPublicPath, config.dev.assetsSubDirectory)
app.use(staticPath, express.static('./static'))

var uri = 'http://localhost:' + port

var _resolve
var readyPromise = new Promise(resolve => {
  _resolve = resolve
})

console.log('> Starting dev server...')
devMiddleware.waitUntilValid(() => {
  console.log('> Listening at ' + uri + '\n')
  // when env is testing, don't need open it
  if (autoOpenBrowser && process.env.NODE_ENV !== 'testing') {
    opn(uri)
  }
  _resolve()
})

var server = app.listen(port)

module.exports = {
  ready: readyPromise,
  close: () => {
    server.close()
  }
}
