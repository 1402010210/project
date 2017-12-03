<template>
    <div class="container">
      <div class="goods">
        <div class="lu_banner">
          <ul class="lunbo" ref="supports" >
            <li v-for="item in data.banner.concat([data.banner[0]])"><a href="#"><img :src="item.imageUrl" alt=""></a></li><!--<li><a href="#"><img src="http://img1.lukou.com/static/p/blog/large/0015/82/15/02/15821502.jpg" alt=""></a></li>--><!--<li><a href="#"><img src="http://img1.lukou.com/static/p/blog/large/0015/73/51/61/15735161.jpg" alt=""></a></li>--><!--<li><a href="#"><img src="http://img1.lukou.com/static/p/blog/large/0015/32/82/83/15328283.jpg" alt=""></a></li>--><!--<li><a href="#"><img src="http://img1.lukou.com/static/p/blog/large/0015/82/15/02/15821502.jpg" alt=""></a></li>-->
          </ul>
          <ul class="point" ref="points">
            <li class="now"></li>
            <li></li>
            <li></li>
          </ul>
        </div>
        <div class=group><span class="ls">热门小组</span><span class="more"><a href="">更多 ></a></span></div>
        <div class="hudong">
          <div  v-for="item in data.grids" class="huitem">
            <div class="iteml">
              <div class="hutitle">{{item.title}}</div>
              <div class="hutext">{{item.label}}</div>
            </div>
            <div class="itemr">
              <img :src="item.imageUrl" >
            </div>
          </div>
        </div>
        <div class=group><span class="ls">今日精选</span><span class="more"><a href="">更多 ></a></span></div>
        <div class="lu_list">
          <div class="list" v-for="item in data.list" >
            <div class="stamp">{{item.stamp}}</div>
            <div class="listitem">
              <div class="listl">
                <div class="title">{{item.feed.blog.title}}</div>
                <div class="shortText">{{item.feed.blog.shortText}}</div>
              </div>
              <div class="listr"><img :src="item.feed.blog.shareImage" alt=""></div>
            </div>
            <div class="author">
              <span  class="smallAvatar"><img :src="item.feed.author.smallAvatar" alt=""></span>
              <span class="name">{{item.feed.author.name}}</span>
              <span class="name">|</span>
              <span class="commentCount">{{item.feed.commentCount}}</span>
              <span class="name">评论</span>
              <span class="like"><i class="icon iconfont icon-shoucang"></i> <span class="likeCount name">{{item.feed.likeCount}}</span></span>
            </div>
          </div>
        </div>
      </div>
    </div>
</template>

<script>
    import {mapActions, mapMutations} from 'vuex'
    export default {
      props:{
        data:{
          type:Object
        }
      },
      data() {
          return {}
        },
      methods: {
        ...mapActions(['startHeaderTransition','linstenTranstionEnd', 'transitionAgain']),
        ...mapMutations(['RECEIVE_LENGTH']),
        callback() {
          this.transitionAgain({obj: this.$refs.supports, modules: 'header'})
        }
      },
      watch: {
        data (val) {
          if (val.banner) {
            this.$nextTick(() =>{
              this.RECEIVE_LENGTH(val.banner.length)
              let obj = this.$refs.supports
              let bj = this.$refs.points
              this.startHeaderTransition({obj,bj})
              this.linstenTranstionEnd({obj, callback: this.callback})
            })
          }
        }
      }
    }
</script>

<style lang="less" scoped>
  .container{
    width: 100%;
    margin-left: 0;
    .goods {
      position: absolute;
      top: 85px;
      bottom: 58px;
      overflow: auto;
      width: 100%;
      .lu_banner {
        width: 100%;
        overflow: hidden;
        position: relative;
        .lunbo{
          width: 400%;
          li{
            float: left;
            width: 25%;
            a{
              width: 100%;
              display: block;
              img{
                height: 147px;
                width: 100%;
                display: block;
              }
            }
          }
        }
        .point{
          position: absolute;
          bottom: 6px;
          left: 50%;
          width: 50px;
          margin-bottom: 0;
          margin-left: -25px;
          height: 6px;
          li{
            float: left;
            width: 6px;
            height: 6px;
            background: #fff;
            border-radius: 50%;
            margin-left: 7px;
            &:first-child{
              margin-left: 0;
            }
          }
          .now{
            background: #19ffae;
          }
        }
      }
      .group{
        padding: 0 20px;
        height: 36px;
        line-height: 36px;
        background: #e2e2e2;
        color: #8a999a;
        .ls{
          float: left;
          font-size: 14px;
        }
        .more{
          float: right;
          font-size: 13px;
        }
      }
      .hudong{
        display: flex;
        .huitem{
          flex: 1;
          padding: 15px 5px 8px 12px;
          width: 100%;
          &:first-child{
            border-right: 1px solid #ccc;
          }
          .iteml{
            display: inline-block;
            width: 72%;
            .hutitle{
              font-size: 14px;
              font-weight: 600;
              margin-bottom: 6px;
            }
            .hutext{
              line-height: 1.4;
              font-size: 10px;
              height: 32px;
              overflow: hidden;
              text-overflow: ellipsis;
              /*white-space: nowrap;*/
              word-break: break-all;
              display: -webkit-box;
              -webkit-box-orient:vertical;
              -webkit-line-clamp:2;
              color: #8a999a;
            }
          }
          .itemr{
            vertical-align: top;
            display: inline-block;
            img{
              width: 40px;
              height: 40px;
            }
          }
        }
      }
      .list{
        padding: 0 12px 10px 14px;
        box-sizing: border-box;
        width: 100%;
        border-bottom: 1px solid #dfdfdf;
        &:last-child{
          border-bottom:none;
        }
        .stamp{
          width: 80px;
          height: 22px;
          line-height: 22px;
          background: #a5a5a5;
          font-size: 13px;
          color: #f7f7f7;
          text-align: center;
          margin-bottom: 12px;
        }
        .listitem{
          position: relative;
          height: 120px;
          .listl{
            display: inline-block;
            width: 62%;
            .title{
              margin-top: 4px;
              font-size: 17px;
              margin-bottom: 8px;
              line-height: 1.4;
              color: black;
            }
            .shortText{
              line-height: 1.5;
              font-size: 14px;
              height: 40px;
              overflow: hidden;
              text-overflow: ellipsis;
              /*white-space: nowrap;*/
              word-break: break-all;
              display: -webkit-box;
              -webkit-box-orient:vertical;
              -webkit-line-clamp:2;
              color: #949494;
            }
          }
          .listr{
            position: absolute;
            right: 0px;
            display: inline-block;
            width: 36%;
            height: 100px;
            vertical-align: top;
            img{
              width: 126px;
              height: 100px;
            }
          }
        }
        .author{
          color: #8a999a;
          font-size: 13px;
          height: 30px;
          line-height: 30px;
          position: relative;
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
  }
</style>
