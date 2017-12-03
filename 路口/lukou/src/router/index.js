import Vue from 'vue'
import Router from 'vue-router'

import  MyJingxuan from "../components/Header.vue"
import MyFaxian from "../components/faxian.vue"
import MyQuan from "../components/luyouquan.vue"
import Me from "../components/me.vue"

Vue.use(Router)

export default new Router({
  linkActiveClass: 'active',
  routes: [
    {path: '/jingxuan',name:'MyJingxuan',component:MyJingxuan},
    {path: '/faxian',name:'MyFaxian',component:MyFaxian},
    {path: '/myquan',name:'MyQuan',component:MyQuan},
    {path: '/me',name:'Me',component:Me}
  ]
})
