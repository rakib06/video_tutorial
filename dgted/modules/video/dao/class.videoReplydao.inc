<?php
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';
include_once UTILITY.'class.util.inc';

Class VideoReplyDAO{

	private $_DB;
	private $_Cat;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Cat = new VideoReply();

	}

	// get all the VideoReplys from the database using the database query
	public function getAllVideoReplys(){

		$VideoReplyList = array();

		$this->_DB->doQuery("SELECT * FROM vtms_video_Reply");
		$rows = $this->_DB->getAllRows();


		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_VideoReply = new VideoReply();

		    $this->_VideoReply->setReplyID ( $row['ReplyID']);
		    $this->_VideoReply->setReply( $row['Reply'] );
		    $this->_VideoReply->setCreator( $row['CreatorID'] );
		    $this->_VideoReply->setVideo( $row['CommentID'] );
		    


		    $VideoReplyList[]=$this->_VideoReply;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($VideoReplyList);

		return $Result;
	}

	//create VideoReply funtion with the VideoReply object
	public function createVideoReply($VideoReply){

		$VideoReplyID=$VideoReply->getReplyID();
		$VideoID=$VideoReply->getCommentID();
		$VideoReply=$VideoReply->getReply();
		
		$Creator=$_SESSION["globalUser"]->getID ();

		$SQL = "INSERT INTO vtms_video_Reply(ReplyID,CommentID,Reply,CreatorID) 
				VALUES('$VideoReplyID,'CommentID','$VideoReply','$,'$Creator')";

		//echo $SQL;

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	public function readCreator($CreatorID){

		$SQL = "SELECT * FROM ums_user
				WHERE ID ='".$CreatorID."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_useradd = new User();

		$this->_useradd->setID ( $row['ID']);
		$this->_useradd->setUniversityID( $row['UniversityID'] );
		$this->_useradd->setEmail ( $row['Email']);
		$this->_useradd->setPassword( $row['Password'] );
		$this->_useradd->setFirstName ( $row['FirstName']);
		$this->_useradd->setLastName( $row['LastName'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_useradd);

		return $Result;
	}
	
	public function readcomment($comment){
		
		//$Dis = $video->getID();
		$SQL = "SELECT * FROM vtms_video_comment WHERE ID='".$comment."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this video from the database
		$row = $this->_DB->getTopRow();

		$this->_Comment= new Comment();

		//preparing the video object
	    $this->_Comment->setID ( $row['CommentID']);
		$this->_Comment->setComment( $row['Comment'] );
		$this->_Comment->setCreatorID( $row['CreatorID'] );
	    $this->_Comment->setVideoID( $row['VideoID'] );
	    




	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Comment);

		return $Result;
	}

	//read an VideoReply object based on its id form VideoReply object
	public function readVideoReply($comment){
		
		
		$VideoReplyList = array();

		$this->_DB->doQuery("SELECT * FROM vtms_video_Reply WHERE CommentID = '".$comment."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_VideoReply = new VideoReply();

		    $this->_VideoReply->setReplyID ( $row['ReplyID']);
		    $this->_VideoReply->setVideoID( $row['CommentID'] );
		    $this->_VideoReply->setReply( $row['Reply'] );
		    $this->_VideoReply->setCreator( $row['CreatorID'] );
		   


		    $VideoReplyList[]=$this->_VideoReply;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($VideoReplyList);

		return $Result;
	}

	//update an VideoReply object based on its 
	public function updateVideoReply($VideoReply){

		$SQL = "UPDATE vtms_video_Reply SET VideoReply='".$VideoReply->getVideoReply()."'
				WHERE ReplyID='".$VideoReply->getReplyID()."'";

		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an VideoReply based on its id of the database
	public function deleteVideoReply($VideoReply){


		$SQL = "DELETE from vtms_video_Reply where ReplyID ='".$VideoReply->getReplyID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

////$_Log->log(LogUtil::$DEBUG," exit the class.videoReplydao.inc");

?>