<template>
    <div class="container">
      <div class="banner">
        <div class="cang">
          <div class="cang2">
            <ul>
              <li v-for="item in banner"><img :src=item.imageUrl alt=""></li>
            </ul>
          </div>
        </div>
      </div>
      <ul class="smallnav">
        <li :class="{curren:indexNumber==0}" @click=zuixin()>最新发布</li>
        <li :class="{curren:indexNumber==1}" @click=jijiang()>即将截团</li>
        <li :class="{curren:indexNumber==2}" @click=canyu()>参与最多</li>
      </ul>
      <div class="list" v-for="item in list" v-show="indexNumber==0||indexNumber==2">
        <div class="list-s">
          <div class="lists-l">
            <div class="title"><div class="jing">精</div>{{item.feed.deal.shareText}}</div>
            <div class="price">
              <span class="new">￥<span>{{item.feed.deal.price}}</span>包邮</span>
              <span class="old">￥<span>{{item.feed.deal.originPrice}}</span></span>
            </div>
            <div class="many">
              <i class="iconfont icon-cshy-shizhong"></i>{{item.feed.deal.state}}
              <i class="iconfont icon-gouwuche"></i>{{item.feed.deal.itemCount}}件团品
            </div>
          </div>
          <div class="lists-r">
            <img :src="item.feed.deal.shareImage" alt="">
          </div>
        </div>
        <div class="list-x">
            <span  class="smallAvatar"><img :src="item.feed.author.smallAvatar" alt=""></span>
            <span class="name">{{item.feed.author.name}}</span>
            <span class="name">|</span>
            <span class="commentCount">{{item.feed.commentCount}}</span>
            <span class="name">评论</span>
            <span class="like"><i class="icon iconfont icon-shoucang"></i> <span class="likeCount name">{{item.feed.likeCount}}</span></span>
        </div>
      </div>
      <div class="list" v-for="item in listano" v-show="indexNumber==1">
        <div class="list-s">
          <div class="lists-l">
            <div class="title"><div class="jing">精</div>{{item.feed.deal.shareText}}</div>
            <div class="price">
              <span class="new">￥<span>{{item.feed.deal.price}}</span>包邮</span>
              <span class="old">￥<span>{{item.feed.deal.originPrice}}</span></span>
            </div>
            <div class="many">
              <i class="iconfont icon-cshy-shizhong"></i>{{item.feed.deal.state}}
              <i class="iconfont icon-gouwuche"></i>{{item.feed.deal.itemCount}}件团品
            </div>
          </div>
          <div class="lists-r">
            <img :src="item.feed.deal.shareImage" alt="">
          </div>
        </div>
        <div class="list-x">
            <span  class="smallAvatar"><img :src="item.feed.author.smallAvatar" alt=""></span>
            <span class="name">{{item.feed.author.name}}</span>
            <span class="name">|</span>
            <span class="commentCount">{{item.feed.commentCount}}</span>
            <span class="name">评论</span>
            <span class="like"><i class="icon iconfont icon-shoucang"></i> <span class="likeCount name">{{item.feed.likeCount}}</span></span>
        </div>
      </div>
    </div>
</template>

<script>
    export default {
        data() {
            return {
              banner:[],
              list:[],
              listano:[],
              indexNumber:0
            }
        },
        methods:{
          zuixin(){
            this.indexNumber=0
          },
          jijiang(){
            this.indexNumber=1
          },
          canyu(){
            this.indexNumber=2
          }
        },
        created () {
          this.$axios.get('/api/tuanbanner')
            .then((res) =>{
              res = res.data
              if(res.error === 0){
                this.banner = res.data
              }
            })
            .catch((error) =>{
            alert(error)
            })

          this.$axios.get('/api/tuanlist')
            .then((res) =>{
              res = res.data
              if(res.error === 0){
                this.list = res.data
              }
            })
            .catch((error) =>{
              alert(error)
            })

          this.$axios.get('/api/tuanlistano')
            .then((res) =>{
              res = res.data
              if(res.error === 0){
                this.listano = res.data
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
    .banner{
        width: 100%;
        height: 130px;
        box-sizing: border-box;
        padding-top: 15px;
        background: #e5e5e5;
        .cang{
          height: 100px;
          overflow: hidden;
          .cang2{
            overflow-x: auto;
            width: 100%;
            height: 120px;
            ul{
              width: 130%;
              li{
                margin-left: 10px;
                width: 46%;
                float: left;
                img{
                  height: 100px;
                  width: 100%;
                  border-radius: 12px;
                }
              }
            }
          }
        }
      }
    .smallnav{
      height: 38px;
      width: 100%;
      border-bottom: 1px solid #ccc;
      li{
        height: 26px;
        margin-top: 6px;
        text-align: center;
        padding-top: 5px;
        margin-left: 10px;
        box-sizing: border-box;
        border-radius: 6px;
        float: left;
        width: 30%;
        background: #cccccc;
        color: #525252;
        font-size: 15px;
        &.curren{
          color: #ff3645;
        }

      }
    }
    .list{
      height: 200px;
      border-bottom: 1px solid #ccc;
      padding: 14px;
      width: 100%;
      box-sizing: border-box;
      &:last-child{
        border-bottom:none;
      }
      .list-s
      {
        display: flex;
        height: 100px;
        margin-bottom: 42px;
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
            .jing{
              vertical-align: top;
              display: inline-block;
              font-size: 14px;
              border: 1px solid orangered;
              color: orangered;
            }
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
            .old{
              font-size: 13px;
              text-decoration: line-through;
              margin-left: 6px;
              color: #888888;
            }
          }
          .many{
            font-size: 14px;
            color: #949494;
            .iconfont{

            }
          }

        }
        .lists-r{
          flex: 0 0 34%;
          img{
            width: 120px;
            height: 114px;
          }
        }
      }
      .list-x{
        width: 100%;
        position: relative;
        color: #8a999a;
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
