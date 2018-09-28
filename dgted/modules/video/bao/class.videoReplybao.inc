<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_VIDEO.'dao/class.videoReplydao.inc';

Class VideoReplyBAO{

	private $_DB;
	private $_VideoReplyDAO;

	public function __construct(){

		$this->_VideoReplyDAO = new VideoReplyDAO();

	}

	//get all Terms value
	public function getAllVideoReplys(){

		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->getAllVideoReplys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.getAllVideoReplys()");		

		return $Result;
	}
	public function createVideoReply($VideoReply){

		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->createVideoReply($VideoReply);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.createVideoReply()");		

		return $Result;

	
	}

	public function readCreator($VideoReply){

		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->readCreator($VideoReply);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.readCreator()");		

		return $Result;

	
	}

	//create Term funtion with the Term object
	public function searchVideoReply($VideoReply){

		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->searchVideoReply($VideoReply);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.searchVideoReply()");		

		return $Result;

	
	}


	//reply
	//read an Term object based on its id form Term object
	public function readVideoReply($VideoReply){


		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->readVideoReply($VideoReply);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.readVideoReply()");		

		return $Result;


	}

	public function readcomment($Video){


		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->readvideo($Video);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.readcomment()");		

		return $Result;


	}

	//update an Term object based on its current information
	public function updateVideoReply($VideoReply){

		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->updateVideoReply($VideoReply);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.updateVideoReply()");		

		return $Result;
	}

	//delete an existing Term
	public function deleteVideoReply($VideoReply){

		$Result = new Result();	
		$Result = $this->_VideoReplyDAO->deleteVideoReply($VideoReply);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoReplyDAO.deleteVideoReply()");		

		return $Result;

	}

}

////$_Log->log(LogUtil::$DEBUG," exit the class.videoReplybao.inc");

?>