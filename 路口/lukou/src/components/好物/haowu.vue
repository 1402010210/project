<template>
    <div class="container">
     <div class="hot">热门品类</div>
     <div class="cang">
       <div class="group">
         <ul>
         <li class="big" v-for="item in categories"><img :src="item.imageUrl" alt=""><div class="name">{{item.name}}</div></li></ul>
       </div>
     </div>
      <div class="border"></div>
      <div class="list" v-for="item in haowulist">
        <div class="list-s">
          <div class="lists-l">
            <div class="title">{{item.feed.commodity.title}}</div>
            <div class="price">
              <span class="new">￥{{item.feed.commodity.price}}</span>
            </div>
          </div>
          <div class="lists-r">
            <img :src="item.feed.commodity.shareImage" alt="">
          </div>
        </div>
        <div class="text"><div>"&nbsp;&nbsp;&nbsp;</div><div>{{item.feed.commodity.shortText}}</div></div>
        <div class="list-x">
          <span  class="smallAvatar"><img :src="item.feed.author.smallAvatar" alt=""></span>
          <span class="name">{{item.feed.author.name}}</span>
          <span class="name">|</span>
          <span class="commentCount">{{item.feed.commentCount}}</span>
          <span class="name">评论</span>
          <span class="like" ><i class="icon iconfont icon-shoucang"></i> <span class="likeCount name">{{item.feed.likeCount}}</span></span>
        </div>
      </div>
    </div>
</template>

<script>
    export default {
       data() {
            return {
              categories:[],
              haowulist:[]
            }
        },
      created () {
        this.$axios.get('/api/haowucategories')
          .then((res) =>{
            res = res.data
            if(res.error === 0){
              this.categories = res.data
            }
          })
          .catch((error) =>{
            alert(error)
          })

        this.$axios.get('/api/haowulist')
          .then((res) =>{
            res = res.data
            if(res.error === 0){
              this.haowulist = res.data
            }
          })
          .catch((error) =>{
            alert(error)
          })
      }
    }
</script>

<style lang="less" scoped>
  .container{
    position: absolute;
    top: 85px;
    bottom: 58px;
    overflow: auto;
    width: 100%;
    .hot{
      padding: 0 20px;
      height: 36px;
      box-sizing: border-box;
      width: 100%;
      line-height: 36px;
      background: #e2e2e2;
      color: #8a999a;}
    .cang{
      height: 102px;
      overflow: hidden;
      .group{
        height: 120px;
        width: 100%;
        overflow-x: auto;
        ul{
          height: 120px;
          /*line-height:80px;*/
          width:224%;
          li{
            margin-top: 8px;
            float: left;
            margin-right: 7px;
            &:first-child{
              margin-left: 7px;

            }
            img{
              height: 76px;
            }
            .name{
              margin-top: 0;
              text-align: center;
            }
          }
        }

      }
    }
    .border {
      margin-top: 10px;
      height: 16px;
      background: #e2e2e2;
    }
    .list{
      border-bottom: 1px solid #ccc;
      padding: 14px;
      width: 100%;
      box-sizing: border-box;
      &:last-child{
        border-bottom:none;
      }
      .list-s {
        display: flex;
        height: 100px;
        margin-bottom: 10px;
        .lists-l{
          flex:0 0 60%;
          margin-right: 14px;
          .title{
            line-height: 1.5;
            font-size: 17px;
            font-weight: 400;
            overflow: hidden;
            text-overflow: ellipsis;
            word-break: break-all;
            display: -webkit-box;
            -webkit-box-orient:vertical;
            -webkit-line-clamp:2;
            margin-bottom: 8px;
            .text{
              display: inline-block;
              vertical-align: top;
              line-height: 1.5;
              font-size: 17px;
              font-weight: 400;
              overflow: hidden;
              text-overflow: ellipsis;
              word-break: break-all;
              -webkit-box-orient:vertical;
              -webkit-line-clamp:2;
            }
          }
          .price{
            margin-bottom: 10px;
            .new{
              color: red;
            }
          }
        }
        .lists-r{
          flex: 0 0 34%;
          img{
            width: 120px;
            height: 100px;
          }
        }
      }
      .text{
        margin-bottom: 22px;
        font-size: 15px;
        line-height: 1.2;
      }
      .list-x{
        width: 100%;
        position: relative;
        color: #636d6e;
        font-size: 15px;
        height: 30px;
        line-height: 30px;
        .smallAvatar{
          display: inline-block;
          margin-right: 4px;
          img{
            border-radius: 50%;
            width: 28px;
            height: 28px;
          }
        }
        .name{
          display: inline-block;
          margin-right: 4px;
          vertical-align: top;
        }
        .commentCount{
          display: inline-block;
          vertical-align: top;
        }
        .like{
          position: absolute;
          right: 2px;
          .icon{
            font-size: 20px;
          }
        }
      }
    }
  }
</style>
