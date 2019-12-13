const Koa = require('koa');
const Router = require('koa-router');
const send = require('koa-send');

const app = new Koa();
const router =  new Router();

function timeout(timestamp) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(true)
    }, timestamp)
  })
}

router.get('/', async (ctx, next) => {
  await send(ctx, './index-async-timeout-css.html')
});

router.get('/normal-js', async (ctx, next) => {
  await send(ctx, './defer-js.js')
})

router.get('/timeout-js', async(ctx, next) => {
  await timeout(3000);
  await send(ctx, './defer-js.js');
})

router.get('/timeout.css', async(ctx, next) => {
  await timeout(3000);
  await send(ctx, './index.css')
})

router.get('/add-onload-js', async(ctx, next) => {
  await send(ctx, './add-onload.js')
})

app.use(router.routes());

app.listen(3333);
