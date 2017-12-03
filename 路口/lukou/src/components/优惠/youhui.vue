<template>
  <div class="container">
    <div class="header">
      <div class="left">
        <img :src="categories[0].imageUrl" alt="">
        <span>{{categories[0].name}}</span>
      </div>
      <div class="right">
        <ul>
          <li><img :src="categories[1].imageUrl" alt=""><span>
            {{categories[1].name}}
          </span></li>
          <li><img :src="categories[2].imageUrl" alt=""><span>
            {{categories[2].name}}
          </span></li>
          <li><img :src="categories[3].imageUrl" alt=""><span>
            {{categories[3].name}}
          </span></li>
          <li><img :src="categories[4].imageUrl" alt=""><span>
            {{categories[4].name}}
          </span></li>
        </ul>
      </div>
      </div>
    <div class="border"></div>
    <ul class="smallnav">
        <li :class="{curren:indexNumber==0}" @click=zuixin()>最新发布</li><li :class="{curren:indexNumber==1}"  @click=xiaoliang()>销量最高</li>
      </ul>
    <div class="list">
      <ul v-show="indexNumber==0">
        <li v-for="item in youhuilist">
          <img :src=item.feed.commodity.imageUrl alt="">
          <div class="text">
            <div class="title">
              {{item.feed.commodity.title}}
            </div>
            <div class="showTitle">
            <span>{{item.feed.commodity.showTitle}}<span v-if="item.feed.commodity.text" class="tx">|{{item.feed.commodity.text}}</span></span>
            </div>
            <div class="price">￥{{item.feed.commodity.price}}</div>
          </div>
        </li>
      </ul>
      <ul v-show="indexNumber==1">
        <li v-for="item in youhuilistano">
          <img :src=item.feed.commodity.imageUrl alt="">
          <div class="text">
            <div class="title">
              {{item.feed.commodity.title}}
            </div>
            <div class="showTitle">
              <span>{{item.feed.commodity.showTitle}}<span v-if="item.feed.commodity.text" class="tx">|{{item.feed.commodity.text}}</span></span>
            </div>
            <div class="price">￥{{item.feed.commodity.price}}</div>
          </div>
        </li>
      </ul>
    </div>
  </div>
</template>

<script>
  export default {
    data() {
      return {
        categories:[],
        youhuilist:[],
        youhuilistano:[],
        indexNumber:0
      }
    },
    methods:{
      zuixin(){
        this.indexNumber=0
      },
      xiaoliang(){
        this.indexNumber=1
      }
    },
    created () {
      this.$axios.get('/api/categories')
        .then((res) =>{
          res = res.data
          if(res.error === 0){
            this.categories = res.data
          }
        })
        .catch((error) =>{
          alert(error)
        })

      this.$axios.get('/api/youhuilist')
        .then((res) =>{
          res = res.data
          if(res.error === 0){
            this.youhuilist = res.data
          }
        })
        .catch((error) =>{
          alert(error)
        })

      this.$axios.get('/api/youhuilistano')
        .then((res) =>{
          res = res.data
          if(res.error === 0){
            this.youhuilistano = res.data
          }
        })
        .catch((error) =>{
          alert(error)
        })

    }
  }
</script>

<style lang="less" scoped>
  .container {
    position: absolute;
    top: 86px;
    bottom: 58px;
    overflow: auto;
    width: 100%;
    .header {
      display: flex;
      width: 100%;
      .left {
        flex: 0 0 40%;
        text-align: center;
        padding-top: 16px;
        box-sizing: border-box;
        img {
          width: 100%;
        }
      }
      .right {
        flex: 0 0 60%;
        ul {
          width: 100%;
          float: left;
          li {
            width: 49%;
            float: left;
            text-align: center;
            img {
              width: 100%;
              height: 75px;
            }
          }
        }
      }
    }
    .border {
      margin-top: 10px;
      height: 12px;
      background: #e2e2e2;
    }
    .smallnav {
      height: 38px;
      width: 100%;
      border-bottom: 1px solid #ccc;
      li {
        height: 38px;
        line-height: 38px;
        text-align: center;
        float: left;
        font-size: 16px;
        width: 50%;
        &.curren {
          color: #ff3645;
          border-bottom: 1px solid #ff3645;
        }
      }
    }
    .list {
      ul {
        width: 100%;
        background: #e2e2e2;
        li {
          position: relative;
          float: left;
          width: 46%;
          margin: 2%;
          height: 264px;
          img {
            height: 150px;
            width: 164px;
          }
          .text{
            padding: 2px;
            .title {
              font-size: 16px;
              font-weight: 600;
              white-space: nowrap;
              overflow: hidden;
              text-overflow: ellipsis;
              margin-top: 4px;
              margin-bottom: 6px;
            }
            .showTitle {
              color: red;
              font-size: 13px;
              height: 46px;
              overflow: hidden;
              line-height: 1.3;
              .tx{
                font-size: 13px;
                color: black;
              }
            }
            .price {
              position: absolute;
              bottom: 2px;
              color: red;
              font-size: 17px;
              font-weight: 700;
            }
          }
        }
      }
    }
  }
</style>
