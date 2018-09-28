<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_VIDEO.'bao/class.videoReplybao.inc';

$_VideoReplyBAO = new VideoReplyBAO();
$_DB = DBUtil::getInstance();

/* saving a new VideoReply account*/
if(isset($_POST['save']))
{
	 $VideoReply = new VideoReply();	
	 $VideoReply->setReplyID(Util::getGUID());
     $VideoReply->setReply($_DB->secureInput($_POST['txtReply']));
     $VideoReply->setCommentID($_DB->secureInput($_POST['txtComment']));
     
	 $_VideoReplyBAO->createVideoReply($VideoReply);		 
}


/* deleting an existing VideoReply */
if(isset($_GET['del']))
{

	$VideoReply = new VideoReply();	
	$VideoReply->setReplyID($_GET['del']);	
	$_VideoReplyBAO->deleteVideoReply($VideoReply); //reading the VideoReply object from the result object

	header("Location:".PageUtil::$VIDEO_Reply);
}

/* reading an existing VideoReply information */
if(isset($_GET['edit']))
{
	$VideoReply = new VideoReply();	
	$VideoReply->setReplyID($_GET['edit']);	
	$getROW = $_VideoReplyBAO->readVideoReply($VideoReply)->getResultObject(); //reading the VideoReply object from the result object
}

/*updating an existing VideoReply information*/
if(isset($_POST['update']))
{
	$VideoReply = new VideoReply();	

    $VideoReply->setReplyID ($_GET['edit']);
    $VideoReply->setReply( $_POST['txtAns'] );
	
	$_VideoReplyBAO->updateVideoReply($VideoReply);

	header("Location:".PageUtil::$VIDEO_Reply);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.videoReply.inc");

?>