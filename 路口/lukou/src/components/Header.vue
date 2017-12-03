<template>
  <div>
    <div class="lu_layout">
        <div class=lu_header>
          <div class="lu_box1">
          <form action="" class="lu_header_form">
            <i class="search_icon iconfont icon-Shape"></i>
            <input type="search" placeholder="风衣">
          </form>
          <div class="qiandao">
            <i class="cart_icon iconfont icon-qiandao"></i><span class="qian">签到</span>
          </div>
          </div>
          <div class="border"></div>
          <div class="lu_box2">
            <ul>
              <li v-for="(item,index) in data.tabs" :class="{'current':indexNumber==index}" @click=dianji(index)>{{item.name}}</li>
            </ul>
          </div>
        </div>
    </div>
    <MyGoods :data="data" v-show="indexNumber==0"></MyGoods>
    <TuanGou v-show="indexNumber==1"></TuanGou>
    <YouHui  v-show="indexNumber==2"></YouHui>
    <HaoWu v-show="indexNumber==3"></HaoWu>
    <TaoLun v-show="indexNumber==4"></TaoLun>
  </div>
</template>

<script>
    import MyGoods from './Goods.vue'
    import TuanGou from './团购/tuangou.vue'
    import YouHui  from './优惠/youhui.vue'
    import HaoWu   from './好物/haowu.vue'
    import TaoLun  from './讨论/taolun.vue'
    export default {
      props:{
          data:{
            type:Object
          }
        },
      data() {
            return {
              indexNumber:0
            }
        },
      components:{
        MyGoods,
        TuanGou,
        YouHui,
        HaoWu,
        TaoLun

      },
      methods:{
        dianji(index){
          this.indexNumber=index
        }
      }
    }
</script>
<style lang="less" scoped>
.lu_layout{
  width: 100%;
  height: 85px;
  .lu_header{
    position: relative;
    top: 0;
    left: 0;
    width: 100%;
    height: 85px;
    font-size: 0;
    .lu_box1{
      width: 100%;
      height: 40px;
      max-width:640px;
      min-width: 300px;
      position: relative;
      .lu_header_form{
        /*margin-left: 5px;*/
        width: 100%;
        box-sizing: border-box;
        position: relative;
        .search_icon{
          position: absolute;
          top:14px;
          left:50%;
          z-index:4;
          color: #b6b6b6;
          font-size: 16px;
        }
        input{
          left: 24%;
          position: absolute;
          height: 30px;
          top: 5px;
          width: 74%;
          border-radius: 6px;
          background: #d6d6d6;
          border:none;
          z-index: 3;
          padding-left: 36%;
          font-size: 13px;
        }
      }
      .qiandao{
        height: 40px;
        line-height: 40px;
        width: 300px;
        font-size: 16px;
        position: relative;
        color: red;
        left: 16px;
        .cart_icon{
          display: inline-block;
          font-size: 20px;
          z-index:4;
        }
        .qian{
          display: inline-block;
          vertical-align: bottom;
          margin-left: 2px;
        }
      }
    }
    .border{
      margin-top: 4px;
      height: 1px;
      width: 100%;
      transform: scaleY(0.5);
      background: #ccc;
      margin-bottom: 0;
    }
    .lu_box2{
      margin-top: 0;
      width: 100%;
      height: 38px;
      position: absolute;
      border-bottom: 1px solid #ccc ;
      ul{
        li{
          float:left;
          text-align: center;
          width: 20%;
          height: 38px;
          line-height: 39px;
          font-size: 15px;
          &.current{
            color: red;
            border-bottom: 2px solid red;
          }
        }
      }
    }
  }
}
</style>
