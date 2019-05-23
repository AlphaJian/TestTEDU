//
//  ViewController.swift
//  TestTEDU
//
//  Created by ken.zhang on 2019/5/23.
//  Copyright © 2019 ken.zhang. All rights reserved.
//

import UIKit
import TEduBoard

class ViewController: UIViewController, TEduBoardDelegate {

    var boardController: TEduBoardController!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.

        let authParam = TEduBoardAuthParam()
        authParam.sdkAppId = 0
        authParam.userId = ""
        authParam.userSig = ""

        let initParam = TEduBoardInitParam()
        boardController = TEduBoardController(authParam: authParam, roomId: 0, initParam: initParam)
        boardController.add(self)
    }

    func onTEBInit() {
        let boardView = boardController.getBoardRenderView()
        boardView?.frame = self.view.bounds
        self.view.addSubview(boardView!)
    }

    func onTEBError(_ code: TEduBoardErrorCode, msg: String!) {

    }

    func onTEBWarning(_ code: TEduBoardWarningCode, msg: String!) {

    }

    func onTEBHistroyDataSyncCompleted() {

    }

    func onTEBSyncData(_ data: String!) {

    }

    func onTEBUndoStatusChanged(_ canUndo: Bool) {

    }

    func onTEBRedoStatusChanged(_ canRedo: Bool) {

    }

    func onTEBImageStatusChanged(_ boardId: String!, url: String!, status: TEduBoardImageStatus) {

    }

    func onTEBSetBackgroundImage(_ url: String!) {

    }

    func onTEBBackgroundH5StatusChanged(_ boardId: String!, url: String!, status: TEduBoardBackgroundH5Status) {

    }

    func onTEBAddBoard(_ boardId: String!, fileId: String!) {

    }

    func onTEBDeleteBoard(_ boardId: String!, fileId: String!) {

    }

    func onTEBGotoBoard(_ boardId: String!, fileId: String!) {

    }

    func onTEBAddFile(_ fileId: String!) {

    }

    func onTEBAddH5PPTFile(_ fileId: String!) {

    }

    func onTEBDeleteFile(_ fileId: String!) {

    }

    func onTEBSwitchFile(_ fileId: String!) {

    }

    func onTEBFileUploadProgress(_ path: String!, currentBytes: Int32, totalBytes: Int32, uploadSpeed: Int32) {

    }

    func onTEBFileUploadStatus(_ path: String!, status: TEduBoardUploadStatus, statusMsg: String!) {

    }

}

