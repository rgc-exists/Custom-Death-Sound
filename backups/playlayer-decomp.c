int PlayLayer::activateEndTrigger(int param_1,bool param_2,bool param_3) {
  return param_1;
}

void PlayLayer::activatePlatformerEndTrigger(PlayLayer *this,EndTriggerGameObject *param_1,vector *param_2) {
  int iVar1;
  UILayer *this_00;
  long *plVar2;
  CCPoint CStack_18;
  CCPoint CStack_10;
  long lStack_8;
  
  lStack_8 = ___stack_chk_guard;
  if ((*(char *)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pParent == '\0') &&
     (*(char *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start == '\0')) {
    iVar1 = *(int *)(param_1 + 0x5a8);
    this[1].CCNode_data.m_pGrid = (CCGridBase *)param_1;
    if (0 < iVar1) {
      (**(code **)(this->CCCopying + 0x4d8))
                (0,this,iVar1,0,param_2,*(undefined4 *)(param_1 + 900),
                 *(undefined4 *)(param_1 + 0x678));
    }
    this_00 = (UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last;
    *(undefined1 *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start = 1;
    UILayer::disableMenu(this_00);
    (**(code **)(*(long *)param_1 + 0x540))(&CStack_18,param_1);
    if ((0 < *(int *)(param_1 + 0x5ac)) &&
       (plVar2 = (long *)GJBaseGameLayer::tryGetMainObject
                                   ((GJBaseGameLayer *)this,*(int *)(param_1 + 0x5ac)),
       plVar2 != (long *)0x0)) {
      (**(code **)(*plVar2 + 0x540))(&CStack_10);
      cocos2d::CCPoint::operator=(&CStack_18,(CCPoint *)&CStack_10);
    }
    cocos2d::CCPoint::CCPoint(&CStack_10,(CCPoint *)&CStack_18);
    playPlatformerEndAnimationToPos(this,&CStack_10,param_1[0x71e]);
  }
  if (lStack_8 != ___stack_chk_guard) {
    __stack_chk_fail();
  }
  return;
}

void PlayLayer::addCircle(PlayLayer *this,CCCircleWave *param_1) {
  cocos2d::CCArray::addObject(*(CCArray **)&(this->PlayLayer_data).field_0x1d0,(CCObject *)param_1);
  return;
}

  int iVar1;
  GameObject GVar2;
  GameObject GVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  float *pfVar9;
  GameObject *pGVar10;
  CCPoint *pCVar11;
  CCNode *pCVar12;
  long lVar13;
  char *pcVar14;
  GameObject **ppGVar15;
  CCCopying *pCVar16;
  code *pcVar17;
  code *pcVar18;
  float fVar19;
  float fVar20;
  CCPoint CStack_18;
  CCPoint CStack_10;
  long lStack_8;
  
  lStack_8 = ___stack_chk_guard;
  if (param_1 == (GameObject *)0x0) goto LAB_006cc694;
  iVar6 = (**(code **)(*(long *)param_1 + 0x6f8))(param_1);
  if (iVar6 == 0x19) {
    GameObject::determineSlopeDirection((GameObject *)param_1);
  }
  else {
    GameObject::updateIsOriented((GameObject *)param_1);
  }
  (**(code **)(*(long *)param_1 + 0x148))(param_1,0);
  (**(code **)(*(long *)param_1 + 0x708))(&CStack_10,param_1);
  if (*(float *)((long)&(this->PlayLayer_data).m_unk38c0 + 3) < CStack_10.x) {
    (**(code **)(*(long *)param_1 + 0x708))(&CStack_10,param_1);
    *(float *)((long)&(this->PlayLayer_data).m_unk38c0 + 3) = CStack_10.x;
  }
  cVar4 = GameObject::isSettingsObject((GameObject *)param_1);
  if ((cVar4 == '\0') &&
     ((iVar6 = (**(code **)(*(long *)param_1 + 0x6f8))(param_1), iVar6 != 0x14 ||
      (((*(int *)(param_1 + 0x4d0) == 1 && (param_1[0x5b0] != (GameObject)0x0)) ||
       (*(int *)(param_1 + 0x3f4) == 0x80f)))))) {
    (**(code **)(this->CCCopying + 0x510))(this,param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0x274) = 0xffffffff;
  }
  cocos2d::CCArray::addObject
            ((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity,(CCObject *)param_1);
  GJBaseGameLayer::addToGroups((GJBaseGameLayer *)this,param_1,true);
  if (*(int *)(param_1 + 0x3f4) == 0x64f) {
    GJBaseGameLayer::addObjectCounter((GJBaseGameLayer *)this,(LabelGameObject *)param_1);
LAB_006cc52c:
    GameObject::getActiveColorForMode((GameObject *)param_1,*(int *)(param_1 + 0x290),true);
    cVar4 = GameObject::hasSecondaryColor((GameObject *)param_1);
  }
  else {
    iVar6 = (**(code **)(*(long *)param_1 + 0x6f8))(param_1);
    if ((iVar6 != 0x1e) && (iVar6 = (**(code **)(*(long *)param_1 + 0x6f8))(param_1), iVar6 != 0x1f)
       ) goto LAB_006cc52c;
    cocos2d::CCArray::addObject
              (*(CCArray **)((long)&(this->PlayLayer_data).m_unk38b0 + 3),(CCObject *)param_1);
    GameObject::getActiveColorForMode((GameObject *)param_1,*(int *)(param_1 + 0x290),true);
    cVar4 = GameObject::hasSecondaryColor((GameObject *)param_1);
  }
  if (cVar4 != '\0') {
    GameObject::getActiveColorForMode((GameObject *)param_1,*(int *)(param_1 + 0x294),false);
  }
  if ((param_1[0x4d4] != (GameObject)0x0) && (*(int *)(param_1 + 0x4d0) == 1)) {
    if ((param_1[0x5b0] == (GameObject)0x0) && (param_1[0x5b1] == (GameObject)0x0)) {
      cocos2d::CCArray::addObject
                ((CCArray *)(this->GJBaseGameLayer_data).m_disabledObjects.last,(CCObject *)param_1)
      ;
    }
    else {
      cVar4 = (**(code **)(*(long *)param_1 + 0x688))(param_1);
      if (cVar4 != '\0') {
        cocos2d::CCArray::addObject
                  ((CCArray *)(this->GJBaseGameLayer_data).m_disabledObjects.last,
                   (CCObject *)param_1);
      }
    }
  }
  if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0') {
    param_1[0x2c4] = (GameObject)0x0;
  }
  iVar6 = *(int *)(param_1 + 0x3f4);
  if (iVar6 == 0x2eb) {
    pCVar11 = (CCPoint *)(**(code **)(*(long *)param_1 + 0xc0))(param_1);
    cocos2d::CCPoint::CCPoint(&CStack_18,pCVar11);
    lVar13 = (**(code **)(*(long *)param_1 + 0xc0))(param_1);
    CStack_18.y = *(float *)(lVar13 + 4) + *(float *)(param_1 + 0x72c);
    fVar20 = (float)TeleportPortalObject::getTeleportXOff
                              ((TeleportPortalObject *)param_1,
                               (CCNode *)(this->GJBaseGameLayer_data).m_fireBlendingLayerT1);
    CStack_18.x = fVar20 + CStack_18.x;
    pGVar10 = (GameObject *)
              TeleportPortalObject::create((TeleportPortalObject *)"portal_16_front_001.png",false);
    *(GameObject **)(param_1 + 0x720) = pGVar10;
    (pGVar10->GameObject_data).m_objectID = 0x2ed;
    (**(code **)(pGVar10->CCCopying + 0x4e0))();
    pcVar18 = *(code **)(pGVar10->CCCopying + 0x548);
    cocos2d::CCPoint::CCPoint(&CStack_10,(CCPoint *)&CStack_18);
    (*pcVar18)(pGVar10,&CStack_10);
    lVar13 = *(long *)param_1;
    (pGVar10->GameObject_data).m_zOrder = *(int *)(param_1 + 0x458);
    pCVar16 = pGVar10->CCCopying;
    pcVar18 = *(code **)(lVar13 + 0x580);
    (pGVar10->GameObject_data).m_defaultZOrder = *(int *)(param_1 + 0x408);
    (pGVar10->GameObject_data).m_unk40C = true;
    pcVar17 = *(code **)(pCVar16 + 0x4c8);
    bVar5 = (*pcVar18)(param_1);
    (*pcVar17)(pGVar10,bVar5 ^ 1);
    bVar5 = (**(code **)(*(long *)param_1 + 0x580))(param_1);
    (pGVar10->GameObject_data).m_startFlipX = (bool)(bVar5 ^ 1);
    lVar13 = *(long *)param_1;
    (pGVar10->GameObject_data).m_isDontEnter = (bool)param_1[0x402];
    pcVar18 = *(code **)(lVar13 + 0x160);
    (pGVar10->GameObject_data).m_isDontFade = (bool)param_1[0x403];
    (pGVar10->GameObject_data).m_hasNoEffects = (bool)param_1[0x404];
    fVar20 = (float)(*pcVar18)(param_1);
    (**(code **)(pGVar10->CCCopying + 0x158))(pGVar10);
    (pGVar10->GameObject_data).m_startRotationX = fVar20;
    (pGVar10->GameObject_data).m_startRotationY = fVar20;
    GameObject::copyGroups(pGVar10,param_1);
    GameObject::updateCustomScaleX(pGVar10,*(float *)(param_1 + 0x470));
    GameObject::updateCustomScaleY(pGVar10,*(float *)(param_1 + 0x474));
    iVar6 = *(int *)(param_1 + 0x51c);
    GVar2 = param_1[0x4fe];
    (pGVar10->GameObject_data).m_mainColorKeyIndex = *(int *)(param_1 + 0x518);
    (pGVar10->GameObject_data).m_detailColorKeyIndex = iVar6;
    if (GVar2 != (GameObject)0x0) {
      (pGVar10->GameObject_data).m_isHide = true;
    }
    (**(code **)(pGVar10->CCCopying + 0x640))(pGVar10);
    addObject(this,(GameObject *)pGVar10);
    iVar6 = *(int *)(param_1 + 0x3f4);
  }
  if (iVar6 < 0x120) {
    if (0x11d < iVar6) goto LAB_006cc878;
    if (iVar6 == 0x24) goto LAB_006cc7fc;
    if (iVar6 < 0x25) {
      if (iVar6 < 0x12) {
        if (iVar6 < 0xf) {
          if (iVar6 - 10U < 4) goto LAB_006cc878;
        }
        else {
          pcVar14 = (char *)GameObject::getBallFrame
                                      (*(int *)((long)&(this->PlayLayer_data).m_unk38b8 + 7));
          pGVar10 = (GameObject *)GameObject::createWithFrame(pcVar14);
          pCVar16 = pGVar10->CCCopying;
          (pGVar10->GameObject_data).m_objectID = 0x25;
          (**(code **)(pCVar16 + 0x4e0))();
          if (*(int *)(param_1 + 0x290) != 0x3ec) {
            GameObject::setMainColorMode(pGVar10,*(int *)(param_1 + 0x290));
          }
          GameObject::setDefaultMainColorMode((GameObject *)param_1,0);
          (**(code **)(*(long *)param_1 + 0x640))(param_1);
          (**(code **)(pGVar10->CCCopying + 0x640))(pGVar10);
          *(undefined4 *)(param_1 + 0x518) = 0;
          fVar20 = *(float *)(param_1 + 0x1b0);
          *(undefined4 *)(param_1 + 0x51c) = 0;
          fVar19 = *(float *)(param_1 + 0x1b4);
          (pGVar10->GameObject_data).m_mainColorKeyIndex = 0;
          (pGVar10->GameObject_data).m_detailColorKeyIndex = 0;
          cocos2d::CCPoint::CCPoint(&CStack_10,fVar20 * 0.5,fVar19 + 10.0);
          cocos2d::CCNode::convertToWorldSpace((CCPoint *)param_1);
          pcVar18 = *(code **)(pGVar10->CCCopying + 0x548);
          cocos2d::CCNode::convertToNodeSpace
                    ((CCPoint *)(this->GJBaseGameLayer_data).m_pixelLayerT1);
          (*pcVar18)(pGVar10,&CStack_10);
          (**(code **)(pGVar10->CCCopying + 0xa0))(_FUN_006ccff0,pGVar10);
          (**(code **)(this->CCCopying + 0x510))(this,pGVar10);
          cocos2d::CCArray::addObject
                    ((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity,(CCObject *)pGVar10);
          (**(code **)(pGVar10->CCCopying + 0x148))(pGVar10,0);
          GameObject::copyGroups(pGVar10,param_1);
          GJBaseGameLayer::addToGroups((GJBaseGameLayer *)this,(GameObject *)pGVar10,true);
        }
      }
      else if (0x1c < iVar6) {
        if (iVar6 < 0x1f) goto LAB_006ccae0;
        if ((iVar6 == 0x1f) && (*(char *)(*(long *)(param_1 + 0x720) + 0x173) == '\0')) {
          ppGVar15 = (this->GJBaseGameLayer_data).m_hazardCollisionObjects.start;
          if (ppGVar15 == (GameObject **)0x0) {
            fVar20 = 0.0;
            iVar6 = -1;
          }
          else {
            iVar6 = *(int *)((long)&(ppGVar15[0xe4]->CCSprite_data).m_pobBatchNode + 4);
            pfVar9 = (float *)(*(code *)((*ppGVar15)->CCNode_data).m_pCamera)(ppGVar15);
            fVar20 = *pfVar9;
          }
          pfVar9 = (float *)(**(code **)(*(long *)param_1 + 0xc0))(param_1);
          iVar1 = *(int *)(*(long *)(param_1 + 0x720) + 0x174);
          bVar5 = *(byte *)(*(long *)(param_1 + 0x720) + 0x172);
          if (((iVar6 < iVar1) || ((fVar20 < *pfVar9 && (bVar5 < (iVar6 <= iVar1))))) ||
             ((*pfVar9 < fVar20 && ((bVar5 != 0 && (iVar6 <= iVar1)))))) {
            GJBaseGameLayer::setStartPosObject((GJBaseGameLayer *)this,(StartPosObject *)param_1);
            *(undefined1 *)&(this->GJBaseGameLayer_data).m_halfCameraWidth = 1;
          }
        }
      }
    }
    else {
      if (iVar6 == 99) goto LAB_006cc878;
      if (iVar6 < 100) {
        if (0x2c < iVar6) {
          if (iVar6 < 0x30) goto LAB_006cc878;
          if (iVar6 == 0x54) goto LAB_006cc7fc;
        }
      }
      else {
        if (iVar6 == 0x69) goto LAB_006ccae0;
        if (iVar6 < 0x6a) {
          if (iVar6 == 0x65) goto LAB_006cc878;
        }
        else {
          if (iVar6 == 0x6f) goto LAB_006cc878;
          if (iVar6 == 0x8d) goto LAB_006cc7fc;
        }
      }
    }
    goto LAB_006cc668;
  }
  if (iVar6 == 0x3fe) {
LAB_006cc7fc:
    GJBaseGameLayer::addGuideArt((GJBaseGameLayer *)this,param_1);
    cVar4 = GameObject::isSpeedObject((GameObject *)param_1);
    if (cVar4 != '\0') goto LAB_006cc678;
LAB_006cc818:
    if (((*(int *)(param_1 + 0x4d0) != 1) || (param_1[0x6e4] == (GameObject)0x0)) ||
       (param_1[0x6d8] == (GameObject)0x0)) goto LAB_006cc694;
  }
  else {
    if (iVar6 < 0x3ff) {
      if (iVar6 != 0x2eb) {
        if (0x2eb < iVar6) {
          if (iVar6 < 0x385) {
            if (iVar6 < 899) {
              if (iVar6 == 0x2ed) goto LAB_006cc878;
            }
            else {
LAB_006ccae0:
              if (param_1[0x5bd] == (GameObject)0x0) {
                if (param_1[0x5be] != (GameObject)0x0) {
                  pCVar12 = (this->GJBaseGameLayer_data).m_unkdd0;
                  GVar2 = *(GameObject *)
                           ((long)&pCVar12[8].CCNode_data.m_obAnchorPointInPoints.x + 1);
                  GVar3 = *(GameObject *)
                           ((long)&pCVar12[8].CCNode_data.m_obAnchorPointInPoints.x + 2);
                  param_1[0x59a] =
                       *(GameObject *)((long)&pCVar12[8].CCNode_data.m_obAnchorPointInPoints.x + 3);
                  param_1[0x598] = GVar2;
                  param_1[0x599] = GVar3;
                }
              }
              else {
                pCVar12 = (this->GJBaseGameLayer_data).m_unkdd0;
                GVar2 = *(GameObject *)((long)&pCVar12[8].CCNode_data.m_fSkewY + 2);
                GVar3 = *(GameObject *)((long)&pCVar12[8].CCNode_data.m_fSkewY + 3);
                param_1[0x59a] = *(GameObject *)&pCVar12[8].CCNode_data.m_obAnchorPointInPoints.x;
                param_1[0x598] = GVar2;
                param_1[0x599] = GVar3;
              }
            }
          }
          else if (iVar6 == 0x393) goto LAB_006ccae0;
          goto LAB_006cc668;
        }
        if (iVar6 == 0x2e8) goto LAB_006ccae0;
        if ((iVar6 != 0x2e9) && (iVar6 != 0x294)) goto LAB_006cc668;
      }
      goto LAB_006cc878;
    }
    if (iVar6 == 0x718) {
      if (param_1[0x67d] != (GameObject)0x0) {
        cocos2d::CCArray::addObject
                  ((CCArray *)(this->GJBaseGameLayer_data).m_disabledObjects.start,
                   (CCObject *)param_1);
      }
    }
    else if (iVar6 < 0x719) {
      if (iVar6 == 0x533) {
LAB_006cc878:
        if (param_1[0x4fe] == (GameObject)0x0) {
          uVar7 = GJBaseGameLayer::addGuideArt((GJBaseGameLayer *)this,param_1);
          iVar6 = *(int *)(param_1 + 0x3f4);
          if (iVar6 == 0x11e) {
            pcVar14 = "portal_11_back_001.png";
          }
          else if (iVar6 < 0x11f) {
            if (iVar6 == 0x2e) {
              pcVar14 = "portal_06_back_001.png";
            }
            else if (iVar6 < 0x2f) {
              if (iVar6 == 0xc) {
                pcVar14 = "portal_03_back_001.png";
              }
              else if (iVar6 < 0xd) {
                pcVar14 = "portal_02_back_001.png";
                if (iVar6 != 0xb) goto LAB_006cceb4;
              }
              else if (iVar6 == 0xd) {
                pcVar14 = "portal_04_back_001.png";
              }
              else {
                pcVar14 = "portal_05_back_001.png";
                if (iVar6 != 0x2d) goto LAB_006cceb4;
              }
            }
            else if (iVar6 == 99) {
              pcVar14 = "portal_08_back_001.png";
            }
            else if (iVar6 < 100) {
              pcVar14 = "portal_07_back_001.png";
              if (iVar6 != 0x2f) goto LAB_006cceb4;
            }
            else if (iVar6 == 0x65) {
              pcVar14 = "portal_09_back_001.png";
            }
            else {
              pcVar14 = "portal_10_back_001.png";
              if (iVar6 != 0x6f) goto LAB_006cceb4;
            }
          }
          else if (iVar6 == 0x2ed) {
LAB_006ccfb0:
            pcVar14 = "portal_16_back_001.png";
          }
          else if (iVar6 < 0x2ee) {
            if (iVar6 == 0x294) {
              pcVar14 = "portal_13_back_001.png";
            }
            else if (iVar6 < 0x295) {
              pcVar14 = "portal_12_back_001.png";
              if (iVar6 != 0x11f) goto LAB_006cceb4;
            }
            else if (iVar6 == 0x2e9) {
              pcVar14 = "portal_14_back_001.png";
            }
            else {
              if (iVar6 == 0x2eb) goto LAB_006ccf8c;
LAB_006cceb4:
              pcVar14 = "portal_01_back_001.png";
            }
          }
          else {
            if (iVar6 == 0x810) goto LAB_006ccfb0;
            if (iVar6 < 0x811) {
              if (iVar6 == 0x533) {
                pcVar14 = "portal_17_back_001.png";
              }
              else {
                pcVar14 = "portal_18_back_001.png";
                if (iVar6 != 0x78d) goto LAB_006cceb4;
              }
            }
            else if (iVar6 == 0xb56) {
LAB_006ccf8c:
              pcVar14 = "portal_15_back_001.png";
            }
            else {
              pcVar14 = "portal_19_back_001.png";
              if (iVar6 != 0xb6e) goto LAB_006cceb4;
            }
          }
          pGVar10 = (GameObject *)GameObject::createWithFrame(pcVar14);
          pCVar16 = pGVar10->CCCopying;
          (pGVar10->GameObject_data).m_objectID = 0x26;
          (**(code **)(pCVar16 + 0x700))(pGVar10,7);
          (pGVar10->GameObject_data).m_isDecoration2 = true;
          (**(code **)(pGVar10->CCCopying + 0x4e0))(pGVar10);
          pcVar18 = *(code **)(pGVar10->CCCopying + 0x548);
          pCVar11 = (CCPoint *)(**(code **)(*(long *)param_1 + 0xc0))(param_1);
          cocos2d::CCPoint::CCPoint(&CStack_10,pCVar11);
          (*pcVar18)(pGVar10,&CStack_10);
          (pGVar10->GameObject_data).m_unk40C = true;
          (pGVar10->GameObject_data).m_defaultZLayer = ~B5;
          iVar6 = GameObject::getObjectZOrder((GameObject *)param_1);
          pCVar16 = pGVar10->CCCopying;
          pcVar18 = *(code **)(*(long *)param_1 + 0x580);
          (pGVar10->GameObject_data).m_defaultZOrder = iVar6 + -100 + (uVar7 & 0xff);
          pcVar17 = *(code **)(pCVar16 + 0x4c8);
          uVar8 = (*pcVar18)(param_1);
          (*pcVar17)(pGVar10,uVar8);
          pcVar18 = *(code **)(pGVar10->CCCopying + 0x4d0);
          uVar8 = (**(code **)(*(long *)param_1 + 0x588))(param_1);
          (*pcVar18)(pGVar10,uVar8);
          pcVar18 = *(code **)(pGVar10->CCCopying + 0x168);
          (**(code **)(*(long *)param_1 + 0x170))(param_1);
          (*pcVar18)(pGVar10);
          pcVar18 = *(code **)(pGVar10->CCCopying + 0x178);
          (**(code **)(*(long *)param_1 + 0x180))(param_1);
          (*pcVar18)(pGVar10);
          GVar2 = param_1[0x3d4];
          (pGVar10->GameObject_data).m_startRotationX = *(float *)(param_1 + 0x3bc);
          fVar20 = *(float *)(param_1 + 0x3c0);
          (pGVar10->GameObject_data).m_startFlipX = (bool)GVar2;
          (pGVar10->GameObject_data).m_startFlipY = (bool)param_1[0x3d5];
          (pGVar10->GameObject_data).m_startRotationY = fVar20;
          GameObject::updateCustomScaleX(pGVar10,*(float *)(param_1 + 0x470));
          GameObject::updateCustomScaleY(pGVar10,*(float *)(param_1 + 0x474));
          GVar2 = param_1[0x402];
          pcVar18 = *(code **)(this->CCCopying + 0x510);
          (pGVar10->GameObject_data).m_startScaleX = *(float *)(param_1 + 0x3c4);
          fVar20 = *(float *)(param_1 + 0x3c8);
          (pGVar10->GameObject_data).m_isDontEnter = (bool)GVar2;
          (pGVar10->GameObject_data).m_isDontFade = (bool)param_1[0x403];
          (pGVar10->GameObject_data).m_startScaleY = fVar20;
          (pGVar10->GameObject_data).m_hasNoEffects = (bool)param_1[0x404];
          (*pcVar18)(this,pGVar10);
          cocos2d::CCArray::addObject
                    ((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity,(CCObject *)pGVar10);
          GameObject::copyGroups(pGVar10,param_1);
          GJBaseGameLayer::addToGroups((GJBaseGameLayer *)this,(GameObject *)pGVar10,true);
          pCVar16 = pGVar10->CCCopying;
          param_1[0x40c] = (GameObject)0x1;
          *(uint *)(param_1 + 0x408) = (uVar7 & 0xff) + 0xc;
          (**(code **)(pCVar16 + 0x640))(pGVar10);
          iVar6 = *(int *)(param_1 + 0x518);
          (pGVar10->GameObject_data).m_detailColorKeyIndex = *(int *)(param_1 + 0x51c);
          (pGVar10->GameObject_data).m_mainColorKeyIndex = iVar6;
        }
      }
      else if ((iVar6 == 0x535) || (iVar6 == 0x532)) goto LAB_006cc7fc;
    }
    else {
      if (iVar6 == 0x810) goto LAB_006cc878;
      if (iVar6 < 0x811) {
        if (iVar6 == 0x78d) goto LAB_006cc878;
      }
      else if ((iVar6 == 0xb56) || (iVar6 == 0xb6e)) goto LAB_006cc878;
    }
LAB_006cc668:
    cVar4 = GameObject::isSpeedObject((GameObject *)param_1);
    if (cVar4 == '\0') goto LAB_006cc818;
LAB_006cc678:
    if (param_1[0x6d8] == (GameObject)0x0) goto LAB_006cc818;
  }
  EffectGameObject::updateSpeedModType((EffectGameObject *)param_1);
  cocos2d::CCArray::addObject
            (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.single + 3),
             (CCObject *)param_1);
LAB_006cc694:
  if (lStack_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}




void PlayLayer::addToGroupOld(PlayLayer *this,GameObject *param_1)

{
  char cVar1;
  int iVar2;
  CCArray *pCVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(short *)(param_1 + 0x480)) {
    do {
      while( true ) {
        iVar2 = GameObject::getGroupID((GameObject *)param_1,iVar4);
        pCVar3 = (CCArray *)GJBaseGameLayer::getGroup((GJBaseGameLayer *)this,iVar2);
        cVar1 = cocos2d::CCArray::containsObject(pCVar3,(CCObject *)param_1);
        if (cVar1 != '\0') break;
        cocos2d::CCArray::addObject(pCVar3,(CCObject *)param_1);
        if (*(int *)(param_1 + 0x388) == 7) goto LAB_006cd0b4;
LAB_006cd038:
        pCVar3 = (CCArray *)GJBaseGameLayer::getStaticGroup((GJBaseGameLayer *)this,iVar2);
        cVar1 = cocos2d::CCArray::containsObject(pCVar3,(CCObject *)param_1);
        if (cVar1 != '\0') goto LAB_006cd058;
LAB_006cd0d4:
        iVar4 = iVar4 + 1;
        cocos2d::CCArray::addObject(pCVar3,(CCObject *)param_1);
        if (*(short *)(param_1 + 0x480) <= iVar4) {
          return;
        }
      }
      if (*(int *)(param_1 + 0x388) != 7) goto LAB_006cd038;
LAB_006cd0b4:
      pCVar3 = (CCArray *)GJBaseGameLayer::getOptimizedGroup((GJBaseGameLayer *)this,iVar2);
      cVar1 = cocos2d::CCArray::containsObject(pCVar3,(CCObject *)param_1);
      if (cVar1 == '\0') goto LAB_006cd0d4;
LAB_006cd058:
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(short *)(param_1 + 0x480));
  }
  return;
}






void PlayLayer::applyCustomEnterEffect(PlayLayer *this,GameObject *param_1,bool param_2)

{
  undefined1 *puVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  undefined4 uVar12;
  undefined2 *puVar13;
  long *plVar14;
  CCPoint *pCVar15;
  undefined8 *puVar16;
  cocos2d *this_00;
  long lVar17;
  int iVar18;
  long lVar19;
  long lVar20;
  float extraout_s0;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined1 auVar30 [16];
  CCPoint *local_48;
  GameToolbox local_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined5 uStack_35;
  GameToolbox local_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined5 uStack_2d;
  undefined1 local_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined5 uStack_25;
  CCPoint local_20;
  CCPoint local_18;
  undefined4 local_10;
  undefined1 local_c;
  undefined1 local_b;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  puVar1 = &(this->PlayLayer_data).field_0x1b4;
  iVar11 = -1;
  if (!param_2) {
    iVar11 = 1;
  }
  sVar2 = *(short *)(param_1 + 0x3dc);
  cocos2d::CCPoint::CCPoint(&local_20,(CCPoint *)puVar1);
  puVar13 = (undefined2 *)(**(code **)(*(long *)param_1 + 0x3a0))(param_1);
  local_38 = SUB21(*puVar13,0);
  uStack_37 = (undefined1)((ushort)*puVar13 >> 8);
  uStack_36 = *(undefined1 *)(puVar13 + 1);
  cVar9 = GameObject::hasSecondaryColor((GameObject *)param_1);
  if (cVar9 == '\0') {
    puVar16 = &DAT_00fa3590;
  }
  else {
    puVar16 = (undefined8 *)
              (**(code **)(**(long **)(param_1 + 0x368) + 0x3a0))(*(long **)(param_1 + 0x368));
  }
  fVar28 = _cameraRight;
  local_30 = SUB21(*(undefined2 *)puVar16,0);
  uStack_2f = (undefined1)((ushort)*(undefined2 *)puVar16 >> 8);
  uStack_2e = *(undefined1 *)((long)puVar16 + 2);
  if (param_2) {
    plVar14 = (long *)GJBaseGameLayer::getCustomEnterEffects
                                ((GJBaseGameLayer *)this,(int)*(short *)(param_1 + 0x3e4),param_2);
    if (plVar14 == (long *)0x0) goto LAB_006cd58c;
LAB_006cd2f8:
    lVar20 = *plVar14;
    lVar17 = plVar14[1];
    fVar24 = 1.0;
    if (lVar17 == lVar20) goto LAB_006cd58c;
    iVar18 = (int)sVar2;
    bVar4 = true;
    fVar29 = (float)iVar11;
    bVar6 = true;
    bVar5 = true;
    bVar3 = true;
    bVar7 = true;
    fVar27 = fVar24;
    fVar25 = fVar24;
    fVar26 = fVar24;
    do {
      lVar19 = *(long *)(lVar20 + 0xc0);
      fVar21 = 0.0;
      if (*(float *)(lVar20 + 0x3c) != 0.0) {
        fVar21 = *(float *)(lVar20 + 0x3c) *
                 (this->GJBaseGameLayer_data).m_varianceValues
                 [(long)(*(short *)(param_1 + 0x3dc) + 1) + 0xe];
      }
      fVar22 = 0.0;
      fVar21 = ((*(float *)&(this->PlayLayer_data).field_0x1b4 -
                (fVar28 + *(float *)(lVar20 + 0x38))) + fVar21) * fVar29;
      if (*(float *)(lVar20 + 0x34) != 0.0) {
        fVar22 = *(float *)(lVar20 + 0x34) *
                 (this->GJBaseGameLayer_data).m_varianceValues
                 [(long)*(short *)(param_1 + 0x3dc) + 0xe];
      }
      fVar23 = *(float *)(lVar20 + 0x50);
      iVar11 = (int)(*(float *)(lVar20 + 0x30) + fVar22);
      if (fVar23 == 0.0) {
        fVar21 = fVar21 / (float)iVar11;
        bVar8 = fVar21 < 1.0;
        if (!bVar8) goto LAB_006cd424;
LAB_006cd3e4:
        if (0.0 < fVar21) {
          bVar8 = false;
          if (!NAN(fVar21)) {
            bVar8 = fVar21 < 1.0;
          }
          goto LAB_006cd424;
        }
        fVar21 = 0.0;
LAB_006cd3f0:
        bVar4 = false;
        switch(*(undefined4 *)(lVar19 + 0x3f4)) {
        case 0xbc9:
          iVar11 = (int)sVar2;
          if (*(char *)(lVar19 + 0x7a0) == '\0') {
            bVar4 = false;
            fVar22 = *(float *)(lVar20 + 0x54) +
                     (this->GJBaseGameLayer_data).m_varianceValues[(long)iVar11 + 0x18] *
                     *(float *)(lVar20 + 0x58);
            if (fVar22 != 0.0) {
              bVar5 = false;
              this_00 = (cocos2d *)
                        GJBaseGameLayer::getEnterEasingValue
                                  ((GJBaseGameLayer *)this,fVar21,*(int *)(lVar19 + 0x76c),
                                   *(float *)(lVar19 + 0x770),*(int *)(lVar19 + 0x774));
              fVar22 = (1.0 - extraout_s0) * fVar22;
              cocos2d::ccpForAngle
                        (this_00,((*(float *)(lVar20 + 0x5c) +
                                  (this->GJBaseGameLayer_data).m_varianceValues[(long)iVar11 + 0x19]
                                  * *(float *)(lVar20 + 0x60)) - 90.0) * 0.017453292);
              local_20.x = local_20.x + fVar22 * local_18.x;
              local_20.y = local_20.y + fVar22 * local_18.y;
            }
          }
          else {
            fVar22 = (*(float *)(lVar20 + 0x6c) +
                     (this->GJBaseGameLayer_data).m_varianceValues[(long)iVar11 + 0x17] *
                     *(float *)(lVar20 + 0x70)) * fVar29;
            fVar23 = (*(float *)(lVar20 + 100) +
                     (this->GJBaseGameLayer_data).m_varianceValues[(long)iVar11 + 0x16] *
                     *(float *)(lVar20 + 0x68)) * fVar29;
            if ((fVar22 != 0.0) || (bVar4 = false, fVar23 != 0.0)) {
              bVar5 = false;
              bVar4 = false;
              fVar21 = (float)GJBaseGameLayer::getEnterEasingValue
                                        ((GJBaseGameLayer *)this,fVar21,*(int *)(lVar19 + 0x76c),
                                         *(float *)(lVar19 + 0x770),*(int *)(lVar19 + 0x774));
              local_20.x = local_20.x + (1.0 - fVar21) * fVar23;
              local_20.y = local_20.y + (1.0 - fVar21) * fVar22;
            }
          }
          break;
        case 0xbca:
          bVar4 = false;
          fVar22 = *(float *)(lVar20 + 0x88) +
                   (this->GJBaseGameLayer_data).m_varianceValues[(long)(iVar18 + 0x12) + 0xe] *
                   *(float *)(lVar20 + 0x8c);
          if (fVar22 != 0.0) {
            bVar6 = false;
            fVar21 = (float)GJBaseGameLayer::getEnterEasingValue
                                      ((GJBaseGameLayer *)this,fVar21,*(int *)(lVar19 + 0x76c),
                                       *(float *)(lVar19 + 0x770),*(int *)(lVar19 + 0x774));
            fVar27 = fVar27 + (1.0 - fVar21) * fVar22;
          }
          break;
        case 0xbcb:
          fVar22 = *(float *)(lVar20 + 0x80) +
                   (this->GJBaseGameLayer_data).m_varianceValues[(long)iVar18 + 0x1b] *
                   *(float *)(lVar20 + 0x84);
          fVar23 = *(float *)(lVar20 + 0x78) +
                   (this->GJBaseGameLayer_data).m_varianceValues[(long)iVar18 + 0x1a] *
                   *(float *)(lVar20 + 0x7c);
          if ((fVar22 != 0.0) || (bVar4 = false, fVar23 != 0.0)) {
            bVar7 = false;
            bVar4 = false;
            fVar21 = (float)GJBaseGameLayer::getEnterEasingValue
                                      ((GJBaseGameLayer *)this,fVar21,*(int *)(lVar19 + 0x76c),
                                       *(float *)(lVar19 + 0x770),*(int *)(lVar19 + 0x774));
            fVar26 = fVar26 * ((1.0 - fVar21) * (fVar23 - 1.0) + 1.0);
            fVar25 = fVar25 * ((1.0 - fVar21) * (fVar22 - 1.0) + 1.0);
          }
          break;
        case 0xbcc:
          bVar4 = false;
          cVar10 = GameObject::ignoreFade((GameObject *)param_1);
          if (cVar10 == '\0') {
            fVar21 = (float)GJBaseGameLayer::getEnterEasingValue
                                      ((GJBaseGameLayer *)this,fVar21,*(int *)(lVar19 + 0x76c),
                                       *(float *)(lVar19 + 0x770),*(int *)(lVar19 + 0x774));
            fVar24 = fVar24 * fVar21;
          }
          break;
        case 0xbcd:
          uVar12 = GJEffectManager::activeColorForIndex
                             ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,
                              *(int *)(lVar19 + 0x794));
          local_28 = (undefined1)uVar12;
          uStack_26 = (undefined1)((uint)uVar12 >> 0x10);
          uStack_27 = (undefined1)((uint)uVar12 >> 8);
          if (*(char *)(lVar19 + 0x7c9) == '\0') {
            fVar21 = (1.0 - *(float *)(lVar20 + 0x90)) + fVar21 * *(float *)(lVar20 + 0x90);
            if (*(char *)(lVar19 + 0x652) == '\0') {
              uVar12 = GameToolbox::multipliedColorValue
                                 (fVar21,CONCAT53(uStack_25,(int3)uVar12),
                                  CONCAT53(uStack_35,
                                           CONCAT12(uStack_36,CONCAT11(uStack_37,local_38))));
              uStack_37 = (undefined1)((uint)uVar12 >> 8);
              uStack_36 = (undefined1)((uint)uVar12 >> 0x10);
              local_38 = SUB41(uVar12,0);
            }
            if ((*(char *)(lVar19 + 0x651) == '\0') &&
               (cVar10 = GameObject::hasSecondaryColor((GameObject *)param_1), cVar10 != '\0')) {
              uVar12 = GameToolbox::multipliedColorValue
                                 (fVar21,CONCAT53(uStack_25,
                                                  CONCAT12(uStack_26,CONCAT11(uStack_27,local_28))),
                                  CONCAT53(uStack_2d,
                                           CONCAT12(uStack_2e,CONCAT11(uStack_2f,local_30))));
LAB_006cd988:
              bVar4 = false;
              uStack_2f = (undefined1)((uint)uVar12 >> 8);
              uStack_2e = (undefined1)((uint)uVar12 >> 0x10);
              local_30 = SUB41(uVar12,0);
              bVar3 = false;
              break;
            }
          }
          else {
            local_c = *(undefined1 *)(lVar20 + 0xac);
            local_18.x = *(float *)(lVar20 + 0xa0);
            local_b = *(undefined1 *)(lVar20 + 0xad);
            local_18.y = *(float *)(lVar20 + 0xa4);
            local_10 = *(undefined4 *)(lVar20 + 0xa8);
            auVar30 = GameToolbox::getMultipliedHSV((_ccHSVValue *)&local_18,1.0 - fVar21);
            if (*(char *)(lVar19 + 0x652) == '\0') {
              uVar12 = GameToolbox::transformColor(&local_38,auVar30._0_8_,auVar30._8_8_);
              uStack_37 = (undefined1)((uint)uVar12 >> 8);
              uStack_36 = (undefined1)((uint)uVar12 >> 0x10);
              local_38 = SUB41(uVar12,0);
            }
            if ((*(char *)(lVar19 + 0x651) == '\0') &&
               (cVar10 = GameObject::hasSecondaryColor((GameObject *)param_1), cVar10 != '\0')) {
              uVar12 = GameToolbox::transformColor(&local_30,auVar30._0_8_,auVar30._8_8_);
              goto LAB_006cd988;
            }
          }
          bVar4 = false;
          bVar3 = false;
        }
      }
      else {
        fVar21 = (fVar21 / (float)iVar11 - fVar23) / (1.0 - fVar23);
        bVar8 = false;
        if (fVar21 < 1.0) goto LAB_006cd3e4;
LAB_006cd424:
        if (bVar8) goto LAB_006cd3f0;
      }
      lVar20 = lVar20 + 0x108;
    } while (lVar17 != lVar20);
  }
  else {
    fVar28 = (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.x;
    plVar14 = (long *)GJBaseGameLayer::getCustomEnterEffects
                                ((GJBaseGameLayer *)this,(int)*(short *)(param_1 + 0x3e4),param_2);
    if (plVar14 != (long *)0x0) goto LAB_006cd2f8;
LAB_006cd58c:
    fVar24 = 1.0;
    bVar3 = true;
    bVar6 = true;
    bVar5 = true;
    bVar7 = true;
    fVar27 = fVar24;
    fVar25 = fVar24;
    fVar26 = fVar24;
    bVar4 = bVar3;
  }
  local_48 = &local_18;
  pCVar15 = (CCPoint *)(**(code **)(*(long *)param_1 + 0xc0))(param_1);
  cocos2d::CCPoint::CCPoint(local_48,pCVar15);
  if (param_2) {
    *(undefined2 *)(param_1 + 0x3e0) = 0xfff1;
  }
  else {
    *(undefined2 *)(param_1 + 0x3e2) = 0xfff1;
  }
  (**(code **)(*(long *)param_1 + 0x380))(param_1,(int)(fVar24 * 255.0));
  if (bVar5) {
    if ((*(float *)&(this->PlayLayer_data).field_0x1b4 != local_18.x) ||
       (*(float *)((long)&(this->PlayLayer_data).m_uncommittedJumps + 3) != local_18.y)) {
      (**(code **)(*(long *)param_1 + 0xb8))(param_1,puVar1);
    }
  }
  else if ((local_20.x != local_18.x) || (local_20.y != local_18.y)) {
    (**(code **)(*(long *)param_1 + 0xb8))(param_1,&local_20);
    lVar20 = *(long *)param_1;
    goto joined_r0x006cd5f4;
  }
  lVar20 = *(long *)param_1;
joined_r0x006cd5f4:
  if (bVar6) {
    (**(code **)(lVar20 + 0x5b8))(0,param_1);
    lVar20 = *(long *)param_1;
  }
  else {
    (**(code **)(lVar20 + 0x5b8))(fVar27,param_1);
    lVar20 = *(long *)param_1;
  }
  if (bVar7) {
    (**(code **)(lVar20 + 0x590))(0x3f800000,param_1);
    (**(code **)(*(long *)param_1 + 0x598))(0x3f800000,param_1);
  }
  else {
    (**(code **)(lVar20 + 0x590))(fVar26,param_1);
    (**(code **)(*(long *)param_1 + 0x598))(fVar25,param_1);
  }
  if ((!bVar3) && ((**(code **)(*(long *)param_1 + 0x620))(param_1,&local_38), cVar9 != '\0')) {
    (**(code **)(*(long *)param_1 + 0x628))(param_1,&local_30);
  }
  if (bVar4) {
    if (param_2) {
      *(undefined2 *)(param_1 + 0x3e0) = 0xffff;
    }
    else {
      *(undefined2 *)(param_1 + 0x3e2) = 0xffff;
    }
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void
PlayLayer::applyEnterEffect(PlayLayer *this,GameObject *param_1,int param_2,bool param_3)

{
  undefined1 *this_00;
  short sVar1;
  char cVar2;
  int iVar3;
  CCPoint *pCVar4;
  code *pcVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_20;
  float local_1c;
  CCPoint CStack_18;
  CCPoint local_10;
  long local_8;
  
  this_00 = &(this->PlayLayer_data).field_0x1b4;
  local_8 = ___stack_chk_guard;
  cocos2d::CCPoint::CCPoint(&local_10,(CCPoint *)this_00);
  fVar6 = (float)getRelativeModNew((PlayLayer *)0x428c0000,0,this,&local_10,0,param_3);
  cVar2 = GameObject::ignoreEnter((GameObject *)param_1);
  if (param_3) {
    sVar1 = *(short *)(param_1 + 0x3e0);
  }
  else {
    sVar1 = *(short *)(param_1 + 0x3e2);
  }
  if ((sVar1 == -1) || ((sVar1 != -0xe && (param_2 == -0xe)))) {
    if (cVar2 != '\0' || fVar6 == 1.0) {
      pCVar4 = (CCPoint *)(**(code **)(*(long *)param_1 + 0xc0))(param_1);
      cocos2d::CCPoint::CCPoint(&local_10,pCVar4);
      if ((*(float *)&(this->PlayLayer_data).field_0x1b4 != local_10.x) ||
         (*(float *)((long)&(this->PlayLayer_data).m_uncommittedJumps + 3) != local_10.y)) {
        (**(code **)(*(long *)param_1 + 0xb8))(param_1,this_00);
      }
      if ((param_1[1000] != (GameObject)0x0) &&
         ((param_1[1000] = (GameObject)0x0, param_1[0x3b8] == (GameObject)0x0 ||
          (param_1[0x3b9] != (GameObject)0x0)))) {
        (**(code **)(*(long *)param_1 + 0x590))(0x3f800000,param_1);
        (**(code **)(*(long *)param_1 + 0x598))(0x3f800000,param_1);
      }
      goto LAB_006cdc2c;
    }
    if (param_3) {
      *(short *)(param_1 + 0x3e0) = (short)param_2;
    }
    else {
      *(short *)(param_1 + 0x3e2) = (short)param_2;
    }
    switch(param_2) {
    case -0xd:
    case -0xc:
      cocos2d::CCDirector::sharedDirector();
      cocos2d::CCDirector::getWinSize();
      if ((this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.y + local_10.y * 0.5 <
          *(float *)((long)&(this->PlayLayer_data).m_uncommittedJumps + 3)) {
        fVar7 = 180.0;
      }
      else {
        fVar7 = 0.0;
      }
      if (param_2 == -0xd) {
        *(float *)(param_1 + 0x3d8) = fVar7 + 180.0;
      }
      else {
        *(float *)(param_1 + 0x3d8) = fVar7;
      }
      break;
    case -0xb:
      iVar3 = rand();
      *(float *)(param_1 + 0x3d8) = ((float)iVar3 * 4.656613e-10 * 2.0 + -1.0) * 180.0;
      break;
    case -10:
    case -9:
      cocos2d::CCDirector::sharedDirector();
      cocos2d::CCDirector::getWinSize();
      fVar8 = *(float *)((long)&(this->PlayLayer_data).m_uncommittedJumps + 3);
      fVar7 = (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.y + local_10.y * 0.5;
      if (param_2 == -10) {
        if (fVar8 <= fVar7) {
          *(undefined4 *)(param_1 + 0x3d8) = 0xc2340000;
        }
        else {
          *(undefined4 *)(param_1 + 0x3d8) = 0xc3070000;
        }
      }
      else if (fVar8 <= fVar7) {
        *(undefined4 *)(param_1 + 0x3d8) = 0x42340000;
      }
      else {
        *(undefined4 *)(param_1 + 0x3d8) = 0x43070000;
      }
    }
switchD_006cdbb8_default:
    if (param_3) {
      iVar3 = (int)*(short *)(param_1 + 0x3e0);
    }
    else {
      iVar3 = (int)*(short *)(param_1 + 0x3e2);
    }
  }
  else {
    if (cVar2 == '\0' && fVar6 != 1.0) goto switchD_006cdbb8_default;
    param_1[1000] = (GameObject)0x1;
    iVar3 = -1;
    if (param_3) {
      *(undefined2 *)(param_1 + 0x3e0) = 0xffff;
    }
    else {
      *(undefined2 *)(param_1 + 0x3e2) = 0xffff;
    }
  }
  if (10 < iVar3 + 0xdU) {
    (**(code **)(*(long *)param_1 + 0xb8))(param_1,this_00);
    goto LAB_006cdc00;
  }
  switch(iVar3) {
  default:
    cocos2d::ccpForAngle
              ((cocos2d *)
               ((long)(short)(&switchD_006cdc9c::switchdataD_00fa3574)[iVar3 + 0xdU] * 4 + 0x6cdca0)
               ,(*(float *)(param_1 + 0x3d8) - 90.0) * 0.017453292);
    pcVar5 = *(code **)(*(long *)param_1 + 0xb8);
    fVar8 = (1.0 - fVar6) * 100.0;
    fVar7 = fVar8 * local_20;
    break;
  case -8:
    fVar8 = 0.0;
    pcVar5 = *(code **)(*(long *)param_1 + 0xb8);
    fVar7 = (1.0 - fVar6) * 100.0;
    goto LAB_006cde98;
  case -7:
    fVar8 = 0.0;
    pcVar5 = *(code **)(*(long *)param_1 + 0xb8);
    fVar7 = (1.0 - fVar6) * -100.0;
    goto LAB_006cde98;
  case -6:
    fVar8 = 1.0 - fVar6;
    pcVar5 = *(code **)(*(long *)param_1 + 0xb8);
    fVar7 = 0.0;
    local_1c = -100.0;
    break;
  case -5:
    fVar7 = 0.0;
    fVar8 = 1.0 - fVar6;
    pcVar5 = *(code **)(*(long *)param_1 + 0xb8);
    local_1c = 100.0;
    break;
  case -4:
    if ((param_1[0x3b8] == (GameObject)0x0) || (param_1[0x3b9] != (GameObject)0x0)) {
      fVar7 = (1.0 - fVar6) * 0.75 + 1.0;
      (**(code **)(*(long *)param_1 + 0x590))(fVar7,param_1);
      (**(code **)(*(long *)param_1 + 0x598))(fVar7,param_1);
    }
    goto LAB_006cde58;
  case -3:
    if ((param_1[0x3b8] == (GameObject)0x0) || (param_1[0x3b9] != (GameObject)0x0)) {
      (**(code **)(*(long *)param_1 + 0x590))(fVar6,param_1);
      (**(code **)(*(long *)param_1 + 0x598))(fVar6,param_1);
    }
LAB_006cde58:
    (**(code **)(*(long *)param_1 + 0xb8))(param_1,this_00);
    goto LAB_006cdc10;
  }
  fVar8 = fVar8 * local_1c;
LAB_006cde98:
  cocos2d::CCPoint::CCPoint(&CStack_18,fVar7,fVar8);
  cocos2d::CCPoint::operator+((CCPoint *)this_00,(CCPoint *)&CStack_18);
  (*pcVar5)(param_1,&local_10);
LAB_006cdc00:
  if ((param_1[0x3b8] == (GameObject)0x0) || (param_1[0x3b9] != (GameObject)0x0)) {
    (**(code **)(*(long *)param_1 + 0x590))(0x3f800000,param_1);
    (**(code **)(*(long *)param_1 + 0x598))(0x3f800000,param_1);
  }
LAB_006cdc10:
  if (fVar6 == 0.0) {
    param_1[1000] = (GameObject)0x1;
    if (param_3) {
      *(undefined2 *)(param_1 + 0x3e0) = 0xffff;
    }
    else {
      *(undefined2 *)(param_1 + 0x3e2) = 0xffff;
    }
  }
LAB_006cdc2c:
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




byte PlayLayer::canPauseGame(PlayLayer *this)

{
  byte bVar1;
  
  bVar1 = 0;
  if (*(char *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start == '\0') {
    bVar1 = *(byte *)&(this->PlayLayer_data).m_keyPulses.m_bits.last ^ 1;
  }
  return bVar1;
}





void PlayLayer::checkForEnd(PlayLayer *this)

{
  long lVar1;
  long lVar2;
  float *pfVar3;
  CCNode *pCVar4;
  float fVar5;
  float local_18;
  float local_10;
  
  lVar1 = ___stack_chk_guard;
  lVar2 = *(long *)&(this->GJBaseGameLayer_data).m_cameraHeight;
  if ((lVar2 == 0) || (*(char *)((long)&(this->PlayLayer_data).m_blendingColors.size + 3) != '\0'))
  goto LAB_006c9228;
  if (*(char *)(lVar2 + 0x540) == '\0') {
                    
    EndPortalObject::getSpawnPos();
    pCVar4 = (this->GJBaseGameLayer_data).m_unkdd0;
                    
    pfVar3 = (float *)(**(code **)(pCVar4->CCCopying + 0xc0))(pCVar4);
    if (*pfVar3 < local_18) {
      if (*(char *)(*(long *)&(this->GJBaseGameLayer_data).m_cameraHeight + 0x540) == '\0')
      goto LAB_006c9228;
      goto LAB_006c91dc;
    }
  }
  else {
LAB_006c91dc:
                    
    EndPortalObject::getSpawnPos();
    pCVar4 = (this->GJBaseGameLayer_data).m_unkdd0;
                    
    pfVar3 = (float *)(**(code **)(pCVar4->CCCopying + 0xc0))(pCVar4);
    if (local_10 < *pfVar3) goto LAB_006c9228;
  }
  fVar5 = *(float *)((long)&(this->GJBaseGameLayer_data).m_debugDrawPoints + 4);
  *(undefined1 *)((long)&(this->PlayLayer_data).m_blendingColors.size + 3) = 1;
  if (fVar5 != 0.0) {
    EndPortalObject::updateEndPos
              (*(EndPortalObject **)&(this->GJBaseGameLayer_data).m_cameraHeight,false);
    GJBaseGameLayer::reorderObjectSection
              ((GJBaseGameLayer *)this,*(GameObject **)&(this->GJBaseGameLayer_data).m_cameraHeight)
    ;
  }
  EndPortalObject::triggerObject(*(GJBaseGameLayer **)&(this->GJBaseGameLayer_data).m_cameraHeight);
LAB_006c9228:
  if (lVar1 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::checkpointActivated(PlayLayer *this,CheckpointGameObject *param_1)

{
  if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0') {
    *(CheckpointGameObject **)&this[1].CCNode_data.m_sInverse.d = param_1;
  }
  GJBaseGameLayer::checkpointActivated((GJBaseGameLayer *)this,param_1);
  return;
}




long PlayLayer::checkpointWithID(PlayLayer *this,int param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = cocos2d::CCArray::count
                      (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
    if (uVar1 <= uVar3) {
      return 0;
    }
    lVar2 = cocos2d::CCArray::objectAtIndex
                      (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3),
                       uVar3);
    uVar3 = uVar3 + 1;
  } while (*(int *)(lVar2 + 0xe90) != param_1);
  return lVar2;
}




void PlayLayer::checkSnapshot(void)

{
  return;
}




void PlayLayer::circleWaveWillBeRemoved(PlayLayer *this,CCCircleWave *param_1)

{
  cocos2d::CCArray::removeObject
            (*(CCArray **)&(this->PlayLayer_data).field_0x1d0,(CCObject *)param_1,true);
  return;
}




void PlayLayer::circleWaveWillBeRemoved(PlayLayer *this,CCCircleWave *param_1)

{
  circleWaveWillBeRemoved
            ((PlayLayer *)&this[-1].GJBaseGameLayer_data.m_gameState.m_unkPoint12,param_1);
  return;
}




void PlayLayer::colorObject(void)

{
  return;
}




void PlayLayer::commitJumps(PlayLayer *this)

{
  GameStatsManager *this_00;
  
  this_00 = (GameStatsManager *)GameStatsManager::sharedState((GameStatsManager *)this);
  GameStatsManager::incrementStat
            (this_00,"1",*(int *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.start + 3));
  *(undefined4 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.start + 3) = 0;
  return;
}




void PlayLayer::compareStateSnapshot(void)

{
  return;
}






void PlayLayer::create(GJGameLevel *param_1,bool param_2,bool param_3)

{
  GJGameState *this;
  float *pfVar1;
  float **ppfVar2;
  int iVar3;
  bool bVar4;
  char cVar5;
  PlayLayer *this_00;
  ulong uVar6;
  unordered_map_node<> *puVar7;
  CCSpriteBatchNode *pCVar8;
  GJEffectManager *pGVar9;
  GameObject **ppGVar10;
  GameObject ***pppGVar11;
  CCDictionary *pCVar12;
  unordered_map_node<> *__s;
  bool *__s_00;
  long lVar13;
  CCArray *pCVar14;
  void **ppvVar15;
  int **__s_01;
  ulong *__s_02;
  vector<> **ppvVar16;
  vector<> ***__s_03;
  double dVar17;
  GameObject *pGVar18;
  undefined1 *puVar19;
  PlayerButtonCommand *pPVar20;
  CCObject *pCVar21;
  SequenceTriggerGameObject **ppSVar22;
  unordered_map_node<> *puVar23;
  CCArray **ppCVar24;
  undefined8 uVar25;
  CCNode *pCVar26;
  UILayer *pUVar27;
  undefined8 *puVar28;
  unordered_map_node<int,int> *puVar29;
  void *pvVar30;
  int *piVar31;
  SFXTriggerGameObject **ppSVar32;
  unordered_map_node<int,int> *puVar33;
  void *pvVar34;
  unordered_set_node<int> *puVar35;
  CCNode *pCVar36;
  GameObject *pGVar37;
  unordered_map<int,int> *puVar38;
  unordered_map_node<> *puVar39;
  unordered_map<int,int> *puVar40;
  unordered_set_node<int> *puVar41;
  undefined1 auStack_10 [8];
  long local_8;
  
  local_8 = ___stack_chk_guard;
  this_00 = operator.new((void *)0x3a60);
                    
  cocos2d::CCLayer::CCLayer((CCLayer *)this_00);
  this = &(this_00->GJBaseGameLayer_data).m_gameState;
  this_00->CCCopying = (CCCopying *)GJBaseGameLayer::vftable;
  this_00->CCTouchDelegate = (CCTouchDelegate *)GJBaseGameLayer::internal_vftable;
  this_00->CCAccelerometerDelegate = (CCAccelerometerDelegate *)GJBaseGameLayer::internal_vftable;
  this_00->CCKeypadDelegate = (CCKeypadDelegate *)GJBaseGameLayer::internal_vftable;
  this_00->CCKeyboardDelegate = (CCKeyboardDelegate *)GJBaseGameLayer::internal_vftable;
  this_00->CCMouseDelegate = (CCMouseDelegate *)GJBaseGameLayer::internal_vftable;
  this_00->TriggerEffectDelegate = (TriggerEffectDelegate *)GJBaseGameLayer::internal_vftable;
                    
  GJGameState::GJGameState(this);
  (this_00->GJBaseGameLayer_data).m_level = (GJGameLevel *)0x0;
  (this_00->GJBaseGameLayer_data).m_playbackMode = Not;
  (this_00->GJBaseGameLayer_data).m_lowDetailMode = false;
  (this_00->GJBaseGameLayer_data).m_extraLDM = false;
  (this_00->GJBaseGameLayer_data).m_ignoreDamage = false;
  (this_00->GJBaseGameLayer_data).m_enable22Changes = false;
  (this_00->GJBaseGameLayer_data).m_allowStaticRotate = false;
  (this_00->GJBaseGameLayer_data).m_fixNegativeScale = false;
  (this_00->GJBaseGameLayer_data).m_startingFromBeginning = false;
  (this_00->GJBaseGameLayer_data).m_activeSfxTriggers.start = (SFXTriggerGameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_activeSfxTriggers.last = (SFXTriggerGameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_activeSfxTriggers.capacity = (SFXTriggerGameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_unk8a0.start = (void **)0x0;
  (this_00->GJBaseGameLayer_data).m_unk8a0.last = (void **)0x0;
  (this_00->GJBaseGameLayer_data).m_unk8a0.capacity = (void **)0x0;
  (this_00->GJBaseGameLayer_data).m_hoverNode = (CCNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_areaTransformNode = (CCNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_areaSkewNode = (CCNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_areaScaleNode = (CCNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_areaRotateNode = (CCNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_areaTransformNode2 = (CCNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_obb2 = (OBB2D *)0x0;
  (this_00->GJBaseGameLayer_data).m_spawnRemapTriggers.start = (unordered_map<int,int> *)0x0;
  (this_00->GJBaseGameLayer_data).m_spawnRemapTriggers.last = (unordered_map<int,int> *)0x0;
  (this_00->GJBaseGameLayer_data).m_spawnRemapTriggers.capacity = (unordered_map<int,int> *)0x0;
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.start = (unordered_map_node<> *)0x0;
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.size = 0;
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.factor = 1.0;
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.resize = 0;
                    
  uVar6 = FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_uiObjectPositions.factor,10);
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.listlen = uVar6;
  if (uVar6 == 1) {
    (this_00->GJBaseGameLayer_data).m_uiObjectPositions.single = (unordered_map_node<> *)0x0;
    puVar7 = (unordered_map_node<> *)&(this_00->GJBaseGameLayer_data).m_uiObjectPositions.single;
  }
  else {
    if (0x1fffffffffffffff < uVar6) {
                    
      uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e6a7c with catch @ 006e7964
                       catch() { ... } // from try @ 006e7960 with catch @ 006e7964 */
      goto LAB_006e7968;
    }
    puVar7 = operator.new((void *)(uVar6 << 3));
    memset(puVar7,0,(size_t)(uVar6 << 3));
  }
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.listptr = puVar7;
  (this_00->GJBaseGameLayer_data).m_fireBlendingLayerT5 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelBlendingLayerT5 = (CCSpriteBatchNode *)0x0;
  *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_particleBlendingLayerT5 = 0x3f800000;
  (this_00->GJBaseGameLayer_data).m_game2BlendingLayerT5 = (CCSpriteBatchNode *)0x0;
                    
  pCVar8 = (CCSpriteBatchNode *)
           FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_particleBlendingLayerT5,10);
  (this_00->GJBaseGameLayer_data).m_gameBlendingLayerT5 = pCVar8;
  if (pCVar8 == (CCSpriteBatchNode *)0x1) {
    (this_00->GJBaseGameLayer_data).m_gameLayerT4 = (CCSpriteBatchNode *)0x0;
    pGVar9 = (GJEffectManager *)&(this_00->GJBaseGameLayer_data).m_gameLayerT4;
  }
  else {
    pGVar9 = (GJEffectManager *)FUN_006c99c0();
  }
  (this_00->GJBaseGameLayer_data).m_effectManager = pGVar9;
  (this_00->GJBaseGameLayer_data).m_gameBlendingLayerT4 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelLayerT2 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_fireBlendingLayerT1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelLayerT1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelBlendingLayerT1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_glowLayerB1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_fireBlendingLayerB1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelLayerB1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelBlendingLayerB1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_particleBlendingLayerB1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_game2LayerB1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_game2BlendingLayerB1 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_gameLayerB2 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_gameBlendingLayerB2 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_fireBlendingLayerB2 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelLayerB2 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_pixelBlendingLayerB2 = (CCSpriteBatchNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_unkdd0 = (CCNode *)0x0;
  (this_00->GJBaseGameLayer_data).m_unkdd8.start = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_unkdd8.last = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_unkdd8.capacity = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_disabledObjects.start = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_disabledObjects.last = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_disabledObjects.capacity = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_unke08.start = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_unke08.last = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_unke08.capacity = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_areaObjects.start = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_areaObjects.last = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_areaObjects.capacity = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_processedAreaObjects.start = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_processedAreaObjects.last = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_processedAreaObjects.capacity = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_visibilityGroups.listptr = (unordered_map_node<> *)0x0;
  (this_00->GJBaseGameLayer_data).m_visibilityGroups.listlen = 0;
  (this_00->GJBaseGameLayer_data).m_visibilityGroups.start = (unordered_map_node<> *)0x0;
  (this_00->GJBaseGameLayer_data).m_visibilityGroups.size = 0;
  *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_visibilityGroups.factor = 0;
  (this_00->GJBaseGameLayer_data).m_visibilityGroups.resize = 0;
  (this_00->GJBaseGameLayer_data).m_visibilityGroups.single = (unordered_map_node<> *)0x0;
  (this_00->GJBaseGameLayer_data).m_visibleObjects.capacity = (GameObject **)0x0;
  (this_00->GJBaseGameLayer_data).m_visibleObjectsCount = 0;
  (this_00->GJBaseGameLayer_data).m_visibleObjectsIndex = 0;
  *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_visibleObjects2.start = 0x3f800000;
  (this_00->GJBaseGameLayer_data).m_visibleObjects2.last = (GameObject **)0x0;
                    
  ppGVar10 = (GameObject **)FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_visibleObjects2,10);
  (this_00->GJBaseGameLayer_data).m_visibleObjects.last = ppGVar10;
  if (ppGVar10 == (GameObject **)0x1) {
    (this_00->GJBaseGameLayer_data).m_visibleObjects2.capacity = (GameObject **)0x0;
    pppGVar11 = &(this_00->GJBaseGameLayer_data).m_visibleObjects2.capacity;
LAB_006e6bf8:
    (this_00->GJBaseGameLayer_data).m_visibleObjects.start = (GameObject **)pppGVar11;
    (this_00->GJBaseGameLayer_data).m_visibleObjects2Count = 0;
    (this_00->GJBaseGameLayer_data).m_visibleObjects2Index = 0;
    (this_00->GJBaseGameLayer_data).m_unked0 = 0;
    (this_00->GJBaseGameLayer_data).m_disabledObjectsCount = 0;
    (this_00->GJBaseGameLayer_data).m_unked8 = 0;
    (this_00->GJBaseGameLayer_data).m_areaObjectsCount = 0;
    (this_00->GJBaseGameLayer_data).m_processedAreaObjectsCount = 0;
    (this_00->GJBaseGameLayer_data).m_unkee4 = 0;
    (this_00->GJBaseGameLayer_data).m_disabledObjectsIndex = 0;
    (this_00->GJBaseGameLayer_data).m_unkeec = 0;
    (this_00->GJBaseGameLayer_data).m_areaObjectsIndex = 0;
    (this_00->GJBaseGameLayer_data).m_processedAreaObjectsIndex = 0;
    (this_00->GJBaseGameLayer_data).m_groupDict = (CCDictionary *)0x0;
    *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_staticGroupDict = 0;
    *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_staticGroupDict + 4) = 0;
    *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_optimizedGroupDict = 0;
    *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_optimizedGroupDict + 4) = 0;
    *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_groups.start = 0;
    *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_groups.start + 4) = 0;
    *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_groups.last = 0;
    *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_groups.last + 4) = 0;
    *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_groups.capacity = 0;
    *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_groups.capacity + 4) = 0;
    *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_staticGroups.start = 0;
    *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_staticGroups.start + 4) = 0;
    (this_00->GJBaseGameLayer_data).m_optimizedGroups.last = (CCArray **)0x0;
    (this_00->GJBaseGameLayer_data).m_optimizedGroups.capacity = (CCArray **)0x0;
    (this_00->GJBaseGameLayer_data).m_parentGroupsDict = (CCDictionary *)0x0;
    (this_00->GJBaseGameLayer_data).m_parentGroupIDs = (CCDictionary *)0x0;
    (this_00->GJBaseGameLayer_data).m_removedParentGroupIDs = (CCDictionary *)0x0;
    (this_00->GJBaseGameLayer_data).m_targetGroupsArray = (CCArray *)0x0;
    (this_00->GJBaseGameLayer_data).m_targetGroups.listptr = (unordered_map_node<> *)0x0;
    (this_00->GJBaseGameLayer_data).m_targetGroups.listlen = 0;
    (this_00->GJBaseGameLayer_data).m_targetGroups.start = (unordered_map_node<> *)0x0;
    (this_00->GJBaseGameLayer_data).m_targetGroups.size = 0;
    *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_targetGroups.factor = 0;
    (this_00->GJBaseGameLayer_data).m_targetGroups.resize = 0;
    (this_00->GJBaseGameLayer_data).m_targetGroups.single = (unordered_map_node<> *)0x0;
    (this_00->GJBaseGameLayer_data).m_objectParent = (CCNode *)0x0;
    (this_00->GJBaseGameLayer_data).m_inShaderParent = (CCNode *)0x0;
    *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_aboveShaderParent = 0x3f800000;
    (this_00->GJBaseGameLayer_data).m_objectLayer = (CCLayer *)0x0;
                    
    uVar6 = FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_aboveShaderParent,10);
    *(ulong *)&(this_00->GJBaseGameLayer_data).m_lastUsedLinkedID = uVar6;
    if (uVar6 == 1) {
      pCVar12 = (CCDictionary *)&(this_00->GJBaseGameLayer_data).m_inShaderObjectLayer;
      (this_00->GJBaseGameLayer_data).m_inShaderObjectLayer = (CCLayer *)0x0;
LAB_006e6ce8:
      (this_00->GJBaseGameLayer_data).m_linkedGroupDict = pCVar12;
      (this_00->GJBaseGameLayer_data).m_aboveShaderObjectLayer = (CCLayer *)0x0;
      *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_background = 0;
      (this_00->GJBaseGameLayer_data).m_unk1000 = (void *)0x0;
      (this_00->GJBaseGameLayer_data).m_groundLayer = (GJGroundLayer *)0x0;
      (this_00->GJBaseGameLayer_data).m_groundLayer2 = (GJGroundLayer *)0x0;
      (this_00->GJBaseGameLayer_data).m_labelObjects.listptr = (unordered_map_node<> *)0x0;
      (this_00->GJBaseGameLayer_data).m_labelObjects.start = (unordered_map_node<> *)0x0;
      (this_00->GJBaseGameLayer_data).m_labelObjects.size = 0;
      *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_labelObjects.factor = 0;
      (this_00->GJBaseGameLayer_data).m_labelObjects.resize = 0;
      (this_00->GJBaseGameLayer_data).m_labelObjects.single = (unordered_map_node<> *)0x0;
      (this_00->GJBaseGameLayer_data).m_timeLabelObjects.start = (unordered_map_node<> *)0x0;
      (this_00->GJBaseGameLayer_data).m_timeLabelObjects.size = 0;
      (this_00->GJBaseGameLayer_data).m_timeLabelObjects.factor = 1.0;
      (this_00->GJBaseGameLayer_data).m_timeLabelObjects.resize = 0;
                    
      uVar6 = FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_timeLabelObjects.factor,10);
      (this_00->GJBaseGameLayer_data).m_timeLabelObjects.listlen = uVar6;
      if (uVar6 == 1) {
        (this_00->GJBaseGameLayer_data).m_timeLabelObjects.single = (unordered_map_node<> *)0x0;
        __s = (unordered_map_node<> *)&(this_00->GJBaseGameLayer_data).m_timeLabelObjects.single;
LAB_006e6d70:
        (this_00->GJBaseGameLayer_data).m_timeLabelObjects.listptr = __s;
        (this_00->GJBaseGameLayer_data).m_spawnTuples.root = (set_node<> *)0x0;
        (this_00->GJBaseGameLayer_data).m_spawnTuples.left = (set_node<> *)0x0;
        *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_spawnTuples.right = 0x3f800000;
        (this_00->GJBaseGameLayer_data).m_spawnTuples.length = 0;
                    
        uVar6 = FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_spawnTuples.right,10);
        *(ulong *)&(this_00->GJBaseGameLayer_data).m_spawnTuples.black = uVar6;
        if (uVar6 == 1) {
          (this_00->GJBaseGameLayer_data).m_increasedLayerCapacity = false;
          *(undefined3 *)&(this_00->GJBaseGameLayer_data).field_0xf49 = 0;
          (this_00->GJBaseGameLayer_data).m_varianceValues[0] = 0.0;
          __s_00 = &(this_00->GJBaseGameLayer_data).m_increasedLayerCapacity;
LAB_006e6dcc:
          *(bool **)&(this_00->GJBaseGameLayer_data).m_spawnTuples = __s_00;
          pfVar1 = (this_00->GJBaseGameLayer_data).m_varianceValues + 3;
          ppfVar2 = &(this_00->GJBaseGameLayer_data).m_enterEasingValues.capacity;
          (this_00->GJBaseGameLayer_data).m_varianceValues[3] = 0.0;
          (this_00->GJBaseGameLayer_data).m_varianceValues[5] = 0.0;
          (this_00->GJBaseGameLayer_data).m_varianceValues[6] = 0.0;
          (this_00->GJBaseGameLayer_data).m_varianceValues[0xb] = 0.0;
          (this_00->GJBaseGameLayer_data).m_varianceValues[0xc] = 0.0;
          *(float **)((this_00->GJBaseGameLayer_data).m_varianceValues + 7) = pfVar1;
          *(float **)((this_00->GJBaseGameLayer_data).m_varianceValues + 9) = pfVar1;
          *(undefined1 *)((this_00->GJBaseGameLayer_data).m_varianceValues + 0xd) = 0;
          *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_enterEasingValues.capacity = 0;
          (this_00->GJBaseGameLayer_data).m_enterEasingIndices.listptr =
               (unordered_map_node<int,int> *)0x0;
          (this_00->GJBaseGameLayer_data).m_enterEasingIndices.size = 0;
          (this_00->GJBaseGameLayer_data).m_enterEasingIndices.listlen = (ulong)ppfVar2;
          (this_00->GJBaseGameLayer_data).m_enterEasingIndices.start =
               (unordered_map_node<int,int> *)ppfVar2;
          *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_enterEasingIndices.factor = 0;
          (this_00->GJBaseGameLayer_data).m_enterEasingIndices.resize = 0;
          (this_00->GJBaseGameLayer_data).m_enterEasingIndices.single =
               (unordered_map_node<int,int> *)0x0;
          (this_00->GJBaseGameLayer_data).m_jumping = false;
          *(undefined3 *)&(this_00->GJBaseGameLayer_data).field_0x2f21 = 0;
          (this_00->GJBaseGameLayer_data).m_leftSectionIndex = 0;
          (this_00->GJBaseGameLayer_data).m_rightSectionIndex = 0;
          (this_00->GJBaseGameLayer_data).m_bottomSectionIndex = 0;
          (this_00->GJBaseGameLayer_data).m_topSectionIndex = 0x3f800000;
          (this_00->GJBaseGameLayer_data).m_player1CollisionBlock = (GameObject *)0x0;
                    
          lVar13 = FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_topSectionIndex,10);
          (this_00->GJBaseGameLayer_data).m_clicks = (int)lVar13;
          (this_00->GJBaseGameLayer_data).m_attempts = (int)((ulong)lVar13 >> 0x20);
          if (lVar13 == 1) {
            (this_00->GJBaseGameLayer_data).m_player2CollisionBlock = (GameObject *)0x0;
            ppGVar10 = &(this_00->GJBaseGameLayer_data).m_player2CollisionBlock;
          }
          else {
            ppGVar10 = (GameObject **)FUN_006c9928();
          }
          *(GameObject ***)&(this_00->GJBaseGameLayer_data).m_enterEasingValuesIndex = ppGVar10;
          (this_00->GJBaseGameLayer_data).m_particleCount = 0;
          *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_customParticleCount = 0;
          (this_00->GJBaseGameLayer_data).m_particleSystemLimit = 0;
          *(undefined4 *)&(this_00->GJBaseGameLayer_data).field_0x2f54 = 0;
          *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_particlesDict = 0;
          *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_particlesDict + 4) = 0;
          *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_customParticles = 0;
          *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_customParticles + 4) = 0;
          *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_unclaimedParticles = 0;
          *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_unclaimedParticles + 4) = 0;
          *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_unclaimedParticles + 5) = 0;
          *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_unclaimedParticles + 6) = 0;
          (this_00->GJBaseGameLayer_data).m_particleCountToParticleString.listptr =
               (unordered_map_node<> *)0x0;
          (this_00->GJBaseGameLayer_data).m_particleCountToParticleString.listlen = 0;
          *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_particleCountToParticleString.start = 0;
          *(undefined4 *)
           ((long)&(this_00->GJBaseGameLayer_data).m_particleCountToParticleString.start + 4) = 0;
          *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_particleCountToParticleString.size = 0;
          *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_particleCountToParticleString.factor = 0
          ;
          (this_00->GJBaseGameLayer_data).m_particleCountToParticleString.resize = 0;
          (this_00->GJBaseGameLayer_data).m_particleCountToParticleString.single =
               (unordered_map_node<> *)0x0;
          (this_00->GJBaseGameLayer_data).m_customParticlesUIDs.listptr =
               (unordered_set_node<int> *)0x0;
          (this_00->GJBaseGameLayer_data).m_customParticlesUIDs.listlen = 0;
          *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_customParticlesUIDs.start = 0x3f800000;
          (this_00->GJBaseGameLayer_data).m_customParticlesUIDs.size = 0;
                    
          pCVar14 = (CCArray *)
                    FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_customParticlesUIDs.start,10);
          (this_00->GJBaseGameLayer_data).m_temporaryParticles = pCVar14;
          if (pCVar14 == (CCArray *)0x1) {
            *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_customParticlesUIDs.factor = 0;
            pCVar12 = (CCDictionary *)&(this_00->GJBaseGameLayer_data).m_customParticlesUIDs.factor;
LAB_006e6efc:
            (this_00->GJBaseGameLayer_data).m_claimedParticles = pCVar12;
            (this_00->GJBaseGameLayer_data).m_customParticlesUIDs.resize = 0;
            (this_00->GJBaseGameLayer_data).m_shaderLayer = (ShaderLayer *)0x0;
            (this_00->GJBaseGameLayer_data).m_objectsDeactivated = false;
            (this_00->GJBaseGameLayer_data).m_areaObjectsUpdated = false;
            *(undefined6 *)&(this_00->GJBaseGameLayer_data).field_0x300a = 0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_startPosObject = 0x3f800000;
            (this_00->GJBaseGameLayer_data).m_useReplay = false;
            (this_00->GJBaseGameLayer_data).m_unk3189 = false;
            *(undefined2 *)&(this_00->GJBaseGameLayer_data).field_0x301a = 0;
            (this_00->GJBaseGameLayer_data).m_solidCollisionObjectsCount = 0;
                    
            lVar13 = FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_startPosObject,10);
            *(long *)&(this_00->GJBaseGameLayer_data).m_activeGradients = lVar13;
            if (lVar13 == 1) {
              *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_solidCollisionObjectsIndex = 0;
              pCVar12 = (CCDictionary *)
                        &(this_00->GJBaseGameLayer_data).m_solidCollisionObjectsIndex;
            }
            else {
              pCVar12 = (CCDictionary *)FUN_006c99c0();
            }
            (this_00->GJBaseGameLayer_data).m_gradientLayers = pCVar12;
            (this_00->GJBaseGameLayer_data).m_solidCollisionObjects.start = (GameObject **)0x0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_solidCollisionObjects.last = 0;
            (this_00->GJBaseGameLayer_data).m_solidCollisionObjects.capacity = (GameObject **)0x0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_hazardCollisionObjectsCount = 0;
            *(undefined1 *)
             ((long)&(this_00->GJBaseGameLayer_data).m_hazardCollisionObjectsCount + 1) = 0;
            (this_00->GJBaseGameLayer_data).m_hazardCollisionObjects.start = (GameObject **)0x0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_hazardCollisionObjects.last = 0;
            *(undefined1 *)
             ((long)&(this_00->GJBaseGameLayer_data).m_hazardCollisionObjects.last + 1) = 0;
            *(undefined4 *)
             ((long)&(this_00->GJBaseGameLayer_data).m_hazardCollisionObjects.last + 4) = 0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_hazardCollisionObjects.capacity = 0;
            (this_00->GJBaseGameLayer_data).m_sequenceTriggers.start =
                 (SequenceTriggerGameObject **)0x0;
            (this_00->GJBaseGameLayer_data).m_sequenceTriggers.last =
                 (SequenceTriggerGameObject **)0x0;
            (this_00->GJBaseGameLayer_data).m_sequenceTriggers.capacity =
                 (SequenceTriggerGameObject **)0x0;
            (this_00->GJBaseGameLayer_data).m_isPracticeMode = false;
            (this_00->GJBaseGameLayer_data).m_practiceMusicSync = false;
            *(undefined2 *)&(this_00->GJBaseGameLayer_data).field_0x307a = 0;
            (this_00->GJBaseGameLayer_data).m_loadingProgress = 0.0;
            (this_00->GJBaseGameLayer_data).m_flashNode = (CCNode *)0x0;
            (this_00->GJBaseGameLayer_data).m_unk31f8 = 0.0;
            (this_00->GJBaseGameLayer_data).m_cameraFlip = 0.0;
            (this_00->GJBaseGameLayer_data).m_cameraWidthOffset = 0.0;
            (this_00->GJBaseGameLayer_data).m_cameraHeightOffset = 0.0;
            *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_updateGroundShadows = 0;
            (this_00->GJBaseGameLayer_data).m_collectedItems = (CCDictionary *)0x0;
            (this_00->GJBaseGameLayer_data).m_levelLength = 0.0;
            (this_00->GJBaseGameLayer_data).m_resetActiveObjects = false;
            (this_00->GJBaseGameLayer_data).m_skipArtReload = false;
            *(undefined2 *)&(this_00->GJBaseGameLayer_data).field_0x30ae = 0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_endPortal = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_endPortal + 1) = 0;
            (this_00->GJBaseGameLayer_data).m_isTestMode = false;
            (this_00->GJBaseGameLayer_data).m_freezeStartCamera = false;
            (this_00->GJBaseGameLayer_data).m_unk322a = false;
            (this_00->GJBaseGameLayer_data).field_0x30bb = 0;
            (this_00->GJBaseGameLayer_data).m_cameraUnzoomedHeightOffset = 0.0;
            *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_endPortal + 4) = 0;
            (this_00->GJBaseGameLayer_data).m_targetCameraHeightOffset = 0.0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_calculateTargetHeightOffset = 0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_glitterParticles = 0;
            *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_glitterParticles + 4) = 0;
            (this_00->GJBaseGameLayer_data).m_staticCameraShake = false;
            (this_00->GJBaseGameLayer_data).m_extraDelta = 0.0;
            (this_00->GJBaseGameLayer_data).m_started = false;
            (this_00->GJBaseGameLayer_data).m_unk3251 = false;
            *(undefined2 *)&(this_00->GJBaseGameLayer_data).field_0x30e2 = 0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_cameraWidth = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_cameraWidth + 1) = 0;
            (this_00->GJBaseGameLayer_data).m_cameraHeight = 0.0;
            (this_00->GJBaseGameLayer_data).m_cameraUnzoomedX = 0.0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_halfCameraWidth = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_halfCameraWidth + 1) = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_halfCameraWidth + 2) = 0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).field_0x30f4 = 0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_audioEffectsLayer = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_audioEffectsLayer + 4) = 0;
            (this_00->GJBaseGameLayer_data).m_cameraObb2 = (OBB2D *)0x0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_activeObjects.start = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_activeObjects.start + 1) = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_activeObjects.start + 2) = 0;
            (this_00->GJBaseGameLayer_data).m_activeObjects.last = (GameObject **)0x0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_activeObjects.capacity = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_activeObjects.capacity + 1) = 0
            ;
            (this_00->GJBaseGameLayer_data).m_recordInputs = false;
            (this_00->GJBaseGameLayer_data).m_unk32a1 = false;
            (this_00->GJBaseGameLayer_data).m_unk32a2 = false;
            (this_00->GJBaseGameLayer_data).m_unk32a3 = false;
            (this_00->GJBaseGameLayer_data).m_unk32a4 = false;
            *(undefined3 *)&(this_00->GJBaseGameLayer_data).field_0x3135 = 0;
            *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_activeObjects.capacity + 4) = 0
            ;
            (this_00->GJBaseGameLayer_data).m_recordString.data.data = (string_data *)0x0;
            (this_00->GJBaseGameLayer_data).m_activeObjectsCount = 0;
            (this_00->GJBaseGameLayer_data).m_unk32c8 = (CCObject *)0x0;
            (this_00->GJBaseGameLayer_data).m_activeObjectsIndex = 0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_lightBGColor = 0;
            (this_00->GJBaseGameLayer_data).m_unk32d0 = 0;
            (this_00->GJBaseGameLayer_data).m_unk32d4 = false;
            *(undefined3 *)&(this_00->GJBaseGameLayer_data).field_0x314d = 0;
            (this_00->GJBaseGameLayer_data).m_queueInterval = 0.0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_coinsCollected = 0;
            *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_coinsCollected + 4) = 0;
            (this_00->GJBaseGameLayer_data).m_unk32ec = 0;
            *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_currentStep = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_currentStep + 1) = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_currentStep + 2) = 0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_currentStep + 3) = 0;
            (this_00->GJBaseGameLayer_data).field_0x316c = 0;
            (this_00->GJBaseGameLayer_data).m_queuedButtons.start =
                 (PlayerButtonCommand *)&DAT_0134b6c8;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_queuedButtons.capacity = 0;
            (this_00->GJBaseGameLayer_data).m_queuedButtons.last = (PlayerButtonCommand *)0x0;
            *(undefined1 *)((long)&(this_00->GJBaseGameLayer_data).m_queuedButtons.capacity + 4) = 0
            ;
            (this_00->GJBaseGameLayer_data).m_queuedRecordedButtons.start =
                 (PlayerButtonCommand *)0x0;
            *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_queuedReplayButtons.start = 0;
            (this_00->GJBaseGameLayer_data).m_queuedRecordedButtons.last =
                 (PlayerButtonCommand *)0x0;
            (this_00->GJBaseGameLayer_data).m_queuedRecordedButtons.capacity =
                 (PlayerButtonCommand *)0x0;
            *(undefined4 *)((long)&(this_00->GJBaseGameLayer_data).m_queuedReplayButtons.start + 4)
                 = 0;
            (this_00->GJBaseGameLayer_data).m_queuedReplayButtons.last = (PlayerButtonCommand *)0x0;
            (this_00->GJBaseGameLayer_data).m_queuedReplayButtons.capacity =
                 (PlayerButtonCommand *)0x0;
            (this_00->GJBaseGameLayer_data).m_unk3340.start = (void **)0x0;
            (this_00->GJBaseGameLayer_data).m_unk3340.last = (void **)0x0;
            (this_00->GJBaseGameLayer_data).m_unk3340.capacity = (void **)0x0;
            (this_00->GJBaseGameLayer_data).m_unk3358.start = (void **)0x0;
            (this_00->GJBaseGameLayer_data).m_queuedRecordedButtonsSize = 0;
            (this_00->GJBaseGameLayer_data).m_portalIndicators = false;
            (this_00->GJBaseGameLayer_data).m_orbIndicators = false;
            *(undefined2 *)&(this_00->GJBaseGameLayer_data).field_0x31ee = 0;
            (this_00->GJBaseGameLayer_data).m_indicatorSprites = (CCArray *)0x0;
            (this_00->GJBaseGameLayer_data).m_unk3380 = 1.0;
            (this_00->GJBaseGameLayer_data).m_unk3388.start = (int *)0x0;
                    
            ppvVar15 = (void **)FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_unk3380,10);
            (this_00->GJBaseGameLayer_data).m_unk3358.capacity = ppvVar15;
            if (ppvVar15 == (void **)0x1) {
              (this_00->GJBaseGameLayer_data).m_unk3388.last = (int *)0x0;
              __s_01 = &(this_00->GJBaseGameLayer_data).m_unk3388.last;
LAB_006e70f4:
              (this_00->GJBaseGameLayer_data).m_unk3358.last = __s_01;
              *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_unk3388.capacity = 0;
              (this_00->GJBaseGameLayer_data).m_unk33a0.start = (int *)0x0;
              (this_00->GJBaseGameLayer_data).m_unk33a0.last = (int *)0x0;
              (this_00->GJBaseGameLayer_data).m_unk33a0.capacity = (int *)0x0;
              (this_00->GJBaseGameLayer_data).m_objectsToMove = (CCArray *)0x0;
              (this_00->GJBaseGameLayer_data).m_savePositionObjects.listptr =
                   (unordered_map_node<> *)0x0;
              *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_savePositionObjects.listlen =
                   0x3f800000;
              (this_00->GJBaseGameLayer_data).m_savePositionObjects.start =
                   (unordered_map_node<> *)0x0;
                    
              pCVar14 = (CCArray *)
                        FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_savePositionObjects.listlen,
                                     10);
              (this_00->GJBaseGameLayer_data).m_unk33c0 = pCVar14;
              if (pCVar14 == (CCArray *)0x1) {
                (this_00->GJBaseGameLayer_data).m_savePositionObjects.size = 0;
                __s_02 = &(this_00->GJBaseGameLayer_data).m_savePositionObjects.size;
LAB_006e7168:
                *(ulong **)&(this_00->GJBaseGameLayer_data).m_hideGround = __s_02;
                *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_savePositionObjects.factor = 0;
                (this_00->GJBaseGameLayer_data).m_savePositionObjects.resize = 0;
                (this_00->GJBaseGameLayer_data).m_savePositionObjects.single =
                     (unordered_map_node<> *)0x0;
                (this_00->GJBaseGameLayer_data).m_savePositionValues.listptr =
                     (unordered_map_node<int,int> *)0x0;
                (this_00->GJBaseGameLayer_data).m_savePositionValues.listlen = 0;
                (this_00->GJBaseGameLayer_data).m_savePositionValues.start =
                     (unordered_map_node<int,int> *)0x0;
                *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_savePositionValues.size = 0;
                *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_savePositionValues.single = 0;
                *(undefined4 *)
                 ((long)&(this_00->GJBaseGameLayer_data).m_savePositionValues.single + 4) = 0;
                *(undefined1 **)&(this_00->GJBaseGameLayer_data).m_savePositionValues.factor =
                     &DAT_0134b6c8;
                (this_00->GJBaseGameLayer_data).m_savePositionValues.resize = (ulong)&DAT_0134b6c8;
                (this_00->GJBaseGameLayer_data).m_keepGroupParents = false;
                (this_00->GJBaseGameLayer_data).field_0x32b9 = 0;
                (this_00->GJBaseGameLayer_data).field_0x32ba = 0;
                (this_00->GJBaseGameLayer_data).m_keyframeGroups = (CCDictionary *)0x0;
                (this_00->GJBaseGameLayer_data).m_keyframeGroup = 0x3f800000;
                (this_00->GJBaseGameLayer_data).m_uiLayer = (UILayer *)0x0;
                (this_00->GJBaseGameLayer_data).m_uiObjects = (CCArray *)0x0;
                (this_00->GJBaseGameLayer_data).m_uiObjectLayers = (CCDictionary *)0x0;
                (this_00->GJBaseGameLayer_data).m_uiTriggerUI = (CCNode *)0x0;
                (this_00->GJBaseGameLayer_data).m_timePlayed = 0.0;
                (this_00->GJBaseGameLayer_data).m_unk3568 = 0;
                (this_00->GJBaseGameLayer_data).m_unk356c = 0;
                (this_00->GJBaseGameLayer_data).m_levelEndAnimationStarted = false;
                (this_00->GJBaseGameLayer_data).m_pointsString.data.data = (string_data *)0x0;
                (this_00->GJBaseGameLayer_data).m_nonEffectObjects.start = (vector<> **)0x0;
                (this_00->GJBaseGameLayer_data).m_nonEffectObjects.last = (vector<> **)0x0;
                *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_nonEffectObjects.capacity =
                     0x3f800000;
                (this_00->GJBaseGameLayer_data).m_collisionBlockSections.start = (vector<> **)0x0;
                    
                ppvVar16 = (vector<> **)
                           FUN_00e146dc(&(this_00->GJBaseGameLayer_data).m_nonEffectObjects.capacity
                                        ,10);
                (this_00->GJBaseGameLayer_data).m_sections.capacity = ppvVar16;
                if (ppvVar16 == (vector<> **)0x1) {
                  (this_00->GJBaseGameLayer_data).m_collisionBlockSections.last = (vector<> **)0x0;
                  __s_03 = &(this_00->GJBaseGameLayer_data).m_collisionBlockSections.last;
LAB_006e7238:
                  (this_00->GJBaseGameLayer_data).m_sections.last = (vector<> **)__s_03;
                  (this_00->GJBaseGameLayer_data).m_calcNonEffectObjects.last = (GameObject **)0x0;
                  (this_00->GJBaseGameLayer_data).m_calcNonEffectObjects.capacity =
                       (GameObject **)0x0;
                  (this_00->GJBaseGameLayer_data).m_calcNonEffectObjectsSize = 0x3f800000;
                  (this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects.start =
                       (GameObject **)0x0;
                    
                  ppGVar10 = (GameObject **)
                             FUN_00e146dc(&(this_00->GJBaseGameLayer_data).
                                           m_calcNonEffectObjectsSize,10);
                  (this_00->GJBaseGameLayer_data).m_calcNonEffectObjects.start = ppGVar10;
                  if (ppGVar10 == (GameObject **)0x1) {
                    (this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects.last =
                         (GameObject **)0x0;
                    pppGVar11 = &(this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects.last;
                  }
                  else {
                    pppGVar11 = (GameObject ***)FUN_006c9928();
                  }
                  (this_00->GJBaseGameLayer_data).m_collisionBlockSections.capacity =
                       (vector<> **)pppGVar11;
                  *(undefined1 *)
                   &(this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects.capacity = 0;
                  *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjectsSize =
                       0;
                  *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.start
                       = 0;
                  (this_00->GJBaseGameLayer_data).m_sectionSizes.last = (vector<int> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last =
                       (GameObject **)0x0;
                  (this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.capacity =
                       (GameObject **)0x0;
                  *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_calcCollisionBlockObjects2Size =
                       0;
                  (this_00->GJBaseGameLayer_data).m_sectionSizes.start = (vector<int> **)0x0;
                  *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_sectionSizes.capacity = 0;
                  *(undefined4 *)
                   ((long)&(this_00->GJBaseGameLayer_data).m_sectionSizes.capacity + 4) = 0;
                  *(undefined1 *)&(this_00->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start = 0;
                  *(undefined4 *)
                   ((long)&(this_00->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start + 4) = 0;
                  (this_00->GJBaseGameLayer_data).m_nonEffectObjectsSizes.capacity =
                       (vector<int> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_nonEffectObjectsSizes.last =
                       (vector<int> **)&DAT_0134b6c8;
                  (this_00->GJBaseGameLayer_data).m_collisionBlockSectionSizes.start =
                       (vector<int> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_collisionBlockSectionSizes.last =
                       (vector<int> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_collisionBlockSectionSizes.capacity =
                       (vector<int> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_nonEffectObjectsFlags.start =
                       (vector<bool> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_nonEffectObjectsFlags.last =
                       (vector<bool> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_nonEffectObjectsFlags.capacity =
                       (vector<bool> **)0x0;
                  (this_00->GJBaseGameLayer_data).m_sectionXFactor = 0.0;
                  (this_00->GJBaseGameLayer_data).m_sectionYFactor = 0.0;
                  (this_00->GJBaseGameLayer_data).m_maxGameplayY = 0.0;
                  (this_00->GJBaseGameLayer_data).m_songTriggerInterval = 0.0;
                  (this_00->GJBaseGameLayer_data).m_stickyGroups.listptr =
                       (unordered_map_node<int,int> *)0x0;
                  (this_00->GJBaseGameLayer_data).m_stickyGroups.listlen = 0;
                  (this_00->GJBaseGameLayer_data).m_stickyGroups.start =
                       (unordered_map_node<int,int> *)0x0;
                  *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_stickyGroups.size = 0;
                  *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_stickyGroups.factor = 0;
                  (this_00->GJBaseGameLayer_data).m_stickyGroups.resize = 0;
                  (this_00->GJBaseGameLayer_data).m_stickyGroups.single =
                       (unordered_map_node<int,int> *)0x0;
                  *(undefined4 *)&(this_00->GJBaseGameLayer_data).m_audioVisualizerBG = 0;
                  (this_00->GJBaseGameLayer_data).m_audioVisualizerSFX = (FMODLevelVisualizer *)0x0;
                  (this_00->GJBaseGameLayer_data).m_showAudioVisualizer = false;
                  *(undefined3 *)&(this_00->GJBaseGameLayer_data).field_0x3471 = 0;
                  (this_00->GJBaseGameLayer_data).m_areaMovedCount = 0;
                  (this_00->GJBaseGameLayer_data).m_areaScaledCount = 0;
                  (this_00->GJBaseGameLayer_data).m_areaRotatedCount = 0;
                  (this_00->GJBaseGameLayer_data).m_areaColorCount = 0;
                  (this_00->GJBaseGameLayer_data).m_areaScaledCountTotal = 0;
                  (this_00->GJBaseGameLayer_data).m_areaRotatedCountTotal = 0;
                  (this_00->GJBaseGameLayer_data).m_areaColorCountTotal = 0;
                  (this_00->GJBaseGameLayer_data).m_movedCount = 0;
                  (this_00->GJBaseGameLayer_data).m_scaledCount = 0;
                  (this_00->GJBaseGameLayer_data).m_rotatedCount = 0;
                  (this_00->GJBaseGameLayer_data).m_followedCount = 0;
                  (this_00->GJBaseGameLayer_data).m_areaMovedCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_areaScaledCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_areaRotatedCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_areaColorCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_areaMovedCountTotalDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_areaScaledCountTotalDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_areaRotatedCountTotalDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_areaColorCountTotalDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_movedCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_scaledCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_rotatedCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_followedCountDisplay = 0;
                  (this_00->GJBaseGameLayer_data).m_loadingStartPosition = false;
                  (this_00->GJBaseGameLayer_data).m_processingAudioTriggers = false;
                  (this_00->GJBaseGameLayer_data).m_audioPaused = false;
                  (this_00->GJBaseGameLayer_data).m_startOptimization = false;
                  (this_00->GJBaseGameLayer_data).m_loadingLayer = (GJGameLoadingLayer *)0x0;
                  (this_00->GJBaseGameLayer_data).m_debugDrawNode = (CCDrawNode *)0x0;
                  *(undefined8 *)&(this_00->GJBaseGameLayer_data).m_isBetweenSteps = 0;
                  (this_00->GJBaseGameLayer_data).m_isDebugDrawEnabled = false;
                  (this_00->GJBaseGameLayer_data).m_disablePlayerHitbox = false;
                  (this_00->GJBaseGameLayer_data).m_hitboxesOnDeath = false;
                  (this_00->GJBaseGameLayer_data).field_0x34f3 = 0;
                  *(undefined4 *)&(this_00->GJBaseGameLayer_data).field_0x34f4 = 0;
                  this_00->CCCircleWaveDelegate = (CCCircleWaveDelegate *)0x0;
                  *(undefined4 *)&this_00->CurrencyRewardDelegate = 0x3f800000;
                  this_00->DialogDelegate = (DialogDelegate *)0x0;
                    
                  dVar17 = (double)FUN_00e146dc(&this_00->CurrencyRewardDelegate,10);
                  (this_00->GJBaseGameLayer_data).m_timestamp = dVar17;
                  if (dVar17 == 4.94065645841247e-324) {
                    *(undefined8 *)&this_00->PlayLayer_data = 0;
                    pGVar18 = (GameObject *)&this_00->PlayLayer_data;
                  }
                  else {
                    pGVar18 = (GameObject *)FUN_006c9928();
                  }
                  (this_00->GJBaseGameLayer_data).m_anticheatSpike = pGVar18;
                  *(undefined8 *)&(this_00->PlayLayer_data).m_unk36cf = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_objectStrings.start + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_objectStrings.last + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_objectStrings.last + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_objectStrings.capacity + 3) = 0
                  ;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_objectStrings.capacity + 7) = 0
                  ;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_coinArray + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_coinArray + 7) = 0;
                  *(undefined4 *)&(this_00->PlayLayer_data).field_0x30 = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_objectsCreated + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects.start + 3) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects.start + 7) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects.last + 3) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects.last + 7) =
                       0;
                  *(undefined4 *)
                   ((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects.capacity + 3) = 0;
                  *(undefined4 *)
                   ((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects.capacity + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects1.start + 3) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects1.start + 7) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects1.last + 3) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects1.last + 7) =
                       0;
                  *(undefined4 *)
                   ((long)&(this_00->PlayLayer_data).m_activeSaveObjects1.capacity + 3) = 0;
                  *(undefined4 *)
                   ((long)&(this_00->PlayLayer_data).m_activeSaveObjects1.capacity + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects2.start + 3) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects2.start + 7) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects2.last + 3) =
                       0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_activeSaveObjects2.last + 7) =
                       0;
                  *(undefined4 *)
                   ((long)&(this_00->PlayLayer_data).m_activeSaveObjects2.capacity + 3) = 0;
                  *(undefined1 *)
                   ((long)&(this_00->PlayLayer_data).m_activeSaveObjects2.capacity + 7) = 0;
                  *(undefined1 *)&(this_00->PlayLayer_data).m_dynamicSaveObjects2.start = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects2.start + 1)
                       = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects2.start + 2)
                       = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects2.start + 3)
                       = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_dynamicSaveObjects2.last + 3) =
                       0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_unk3768 + 3) = 0;
                  (this_00->PlayLayer_data).m_platformerRestart = false;
                  (this_00->PlayLayer_data).m_unk376d = false;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_statusLabel + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_unk3778 + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_unk3780 + 3) = 0;
                  *(undefined1 *)&(this_00->PlayLayer_data).m_unk3784 = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_unk3784 + 1) = 0;
                  this_00->CCCopying = (CCCopying *)vftable;
                  this_00->CCTouchDelegate = (CCTouchDelegate *)&PTR_~PlayLayer_01248b68;
                  this_00->CCAccelerometerDelegate = (CCAccelerometerDelegate *)&DAT_01248bd8;
                  this_00->CCKeypadDelegate = (CCKeypadDelegate *)&PTR_keyBackClicked_01248bf0;
                  this_00->CCKeyboardDelegate = (CCKeyboardDelegate *)&PTR_keyDown_01248c10;
                  this_00->CCMouseDelegate = (CCMouseDelegate *)&PTR_rightKeyDown_01248c30;
                  this_00->TriggerEffectDelegate =
                       (TriggerEffectDelegate *)&PTR_toggleGroupTriggered_01248c58;
                  *(undefined **)((long)&(this_00->PlayLayer_data).m_unk3788 + 3) = &DAT_01248c88;
                  *(undefined **)&(this_00->PlayLayer_data).field_0xc0 = &DAT_01248ca0;
                  *(undefined **)((long)&(this_00->PlayLayer_data).m_currentCheckpoint + 3) =
                       &DAT_01248cb8;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_checkpointArray + 7) = 0;
                  *(undefined1 *)&(this_00->PlayLayer_data).m_speedObjects = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_speedObjects + 1) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_speedObjects + 2) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_speedObjects + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0xe0 = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_enterEffectPosition.y + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_unk37c0 + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0xf8 = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_circleWaveArray + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_circleWaveArray + 7) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_collectibles + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0x110 = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_maxObjectX + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_attemptLabel + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_percentageLabel + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0x130 = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_progressBar + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_progressFill + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_progressWidth + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_totalGravityEffects + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_gravityEffectIndex + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_gravityEffects + 3) = 0;
                  *(undefined4 *)&(this_00->PlayLayer_data).field_0x168 = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_unk383c + 3) = 0;
                  (this_00->PlayLayer_data).m_skipAudioStep = false;
                  (this_00->PlayLayer_data).field_0x16e = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0x170 = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_blendingColors.listptr + 3) = 0
                  ;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_blendingColors.listlen + 3) = 0
                  ;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_blendingColors.listlen + 7) = 0
                  ;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_blendingColors.size + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_blendingColors.factor + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_blendingColors.size + 7) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_blendingColors.resize + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_jumps + 3) = 0;
                  (this_00->PlayLayer_data).m_hasJumped = false;
                    
                  cocos2d::CCPoint::CCPoint((CCPoint *)&(this_00->PlayLayer_data).field_0x1b4);
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_orbs + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0x1d0 = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_unk38b0 + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_unk38b8 + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_unk38b8 + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_unk38c0 + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0x1f0 = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_attemptTime + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_attemptTime + 4) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_bestAttemptTime + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_currentTime + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_pauseTime + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_currentTime + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_pauseDelta + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_pauseDelta + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_unk3900 + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0x230 = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_infoLabel + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_infoLabel + 7) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_unk3918.x + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_keyColors.start + 3) = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_keyColors.last + 3) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_keyColors.capacity + 3) =
                       0x3f800000;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_keyOpacities.start + 3) = 0;
                  lVar13 = FUN_00e146dc((undefined1 *)
                                        ((long)&(this_00->PlayLayer_data).m_keyColors.capacity + 3),
                                        10);
                  *(long *)((long)&(this_00->PlayLayer_data).m_colorKeyDict + 3) = lVar13;
                  if (lVar13 == 1) {
                    *(undefined8 *)((long)&(this_00->PlayLayer_data).m_keyOpacities.last + 3) = 0;
                    puVar19 = (undefined1 *)
                              ((long)&(this_00->PlayLayer_data).m_keyOpacities.last + 3);
                  }
                  else {
                    puVar19 = (undefined1 *)FUN_006c99c0();
                  }
                  *(undefined1 **)((long)&(this_00->PlayLayer_data).m_unk3920.x + 3) = puVar19;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_keyOpacities.capacity + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_keyOpacities.capacity + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_keyPulses.m_bits.start + 3) = 0
                  ;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_keyPulses.m_bits.start + 7) = 0
                  ;
                  *(undefined1 *)&(this_00->PlayLayer_data).m_keyPulses.m_bits.last = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_keyPulses.m_bits.last + 1) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_keyPulses.m_bits.last + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_keyPulses.m_bits.last + 7) = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_keyPulses.m_bits.capacity + 3)
                       = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_keyPulses.m_bits.capacity + 7)
                       = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_nextColorKey + 3) = 0;
                  (this_00->PlayLayer_data).m_tryPlaceCheckpoint = false;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_activatedCheckpoint + 3) = 0;
                  *(undefined8 *)&(this_00->PlayLayer_data).field_0x2b0 = 0;
                  *(undefined8 *)((long)&(this_00->PlayLayer_data).m_endPosition.y + 3) = 0;
                  *(undefined1 *)((long)&(this_00->PlayLayer_data).m_platformerEndTrigger + 3) = 0;
                  *(undefined4 *)&this_00[1].CCCopying = 0;
                  *(undefined4 *)((long)&(this_00->PlayLayer_data).m_platformerEndTrigger + 7) = 0;
                  this_00[1].CCObject_data.m_uID = 0;
                  this_00[1].CCObject_data.m_nLuaID = 0;
                  this_00[1].CCObject_data.m_nTag = 0;
                  this_00[1].CCObject_data.m_uReference = 0;
                  this_00[1].CCObject_data.m_uIndexInArray = 0;
                  this_00[1].CCObject_data.m_nChildIndex = 0;
                  this_00[1].CCObject_data.m_unknown2 = 0;
                  this_00[1].CCObject_data.m_nZOrder = 0;
                  this_00[1].CCObject_data.m_uOrderOfArrival = 0;
                  *(undefined1 *)&this_00[1].CCObject_data.m_unknown5 = 0;
                  *(undefined1 *)((long)&this_00[1].CCObject_data.m_unknown5 + 1) = 0;
                  *(undefined1 *)((long)&this_00[1].CCObject_data.m_unknown5 + 2) = 0;
                  *(undefined1 *)((long)&this_00[1].CCObject_data.m_unknown5 + 3) = 0;
                  *(undefined1 *)&this_00[1].CCNode_data.m_fRotationX = 0;
                  this_00[1].CCNode_data.m_fScaleX = 0.0;
                  this_00[1].CCNode_data.m_fScaleY = 0.0;
                    
                  cocos2d::CCPoint::CCPoint((CCPoint *)&this_00[1].CCNode_data.m_fVertexZ);
                  cocos2d::CCPoint::CCPoint((CCPoint *)&this_00[1].CCNode_data.m_obPosition.y);
                  *(undefined8 *)&this_00[1].CCNode_data.m_obAnchorPointInPoints.y = 0;
                  *(undefined8 *)&this_00[1].CCNode_data.m_obAnchorPoint.y = 0;
                  *(undefined8 *)&this_00[1].CCNode_data.m_obContentSize.height = 0;
                  this_00[1].CCNode_data.m_sAdditionalTransform.b = 0.0;
                  this_00[1].CCNode_data.m_sAdditionalTransform.c = 0.0;
                  this_00[1].CCNode_data.m_sAdditionalTransform.d = 0.0;
                  this_00[1].CCNode_data.m_sAdditionalTransform.tx = 0.0;
                  *(undefined8 *)&this_00[1].CCNode_data.m_sAdditionalTransform.ty = 0;
                  this_00[1].CCNode_data.m_sTransform.b = 0.0;
                  this_00[1].CCNode_data.m_sTransform.c = 0.0;
                  this_00[1].CCNode_data.m_sTransform.d = 0.0;
                  this_00[1].CCNode_data.m_sTransform.tx = 0.0;
                  *(undefined8 *)&this_00[1].CCNode_data.m_sTransform.ty = 0;
                    
                  FUN_006c9630(&this_00[1].CCNode_data.m_sTransform.b,1);
                  this_00[1].CCNode_data.m_sInverse.b = 0.0;
                  *(undefined1 *)&this_00[1].CCNode_data.m_sInverse.c = 0;
                  this_00[1].CCNode_data.m_sInverse.d = 0.0;
                  this_00[1].CCNode_data.m_sInverse.tx = 0.0;
                  *(undefined1 *)&this_00[1].CCNode_data.m_sInverse.ty = 0;
                    
                  cocos2d::CCPoint::CCPoint((CCPoint *)&this_00[1].CCNode_data.field_0x84);
                  this_00[1].CCNode_data.m_pGrid = (CCGridBase *)0x0;
                  cVar5 = init(this_00,param_1,param_2,param_3);
                  if (cVar5 == '\0') {
                    (**(code **)(this_00->CCCopying + 0x10))(this_00);
                    this_00 = (PlayLayer *)0x0;
                  }
                  else {
                    cocos2d::CCObject::autorelease((CCObject *)this_00);
                  }
                  if (local_8 == ___stack_chk_guard) {
                    return;
                  }
                    
                  __stack_chk_fail(this_00);
                }
                if (ppvVar16 < (vector<> **)0x2000000000000000) {
                  __s_03 = operator.new((void *)((long)ppvVar16 << 3));
                  memset(__s_03,0,(size_t)((long)ppvVar16 << 3));
                  goto LAB_006e7238;
                }
                    
                uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e71fc with catch @ 006e79f4
                       catch() { ... } // from try @ 006e79f0 with catch @ 006e79f4 */
                pCVar26 = (this_00->GJBaseGameLayer_data).m_uiTriggerUI;
                if (pCVar26 != (CCNode *)0x0) {
                  operator.delete(pCVar26);
                }
                pUVar27 = (this_00->GJBaseGameLayer_data).m_uiLayer;
                if (pUVar27 != (UILayer *)0x0) {
                  operator.delete(pUVar27);
                }
                puVar28 = (undefined8 *)
                          ((this_00->GJBaseGameLayer_data).m_savePositionValues.resize - 0x18);
                if (puVar28 != &DAT_0134b6b0) {
                  FUN_006c93b8(puVar28,auStack_10);
                }
                puVar28 = (undefined8 *)
                          (*(long *)&(this_00->GJBaseGameLayer_data).m_savePositionValues.factor +
                          -0x18);
                if (puVar28 != &DAT_0134b6b0) {
                  FUN_006c93b8(puVar28,auStack_10);
                }
                puVar29 = (this_00->GJBaseGameLayer_data).m_savePositionValues.listptr;
                if (puVar29 != (unordered_map_node<int,int> *)0x0) {
                  operator.delete(puVar29);
                }
                pvVar30 = *(void **)&(this_00->GJBaseGameLayer_data).m_savePositionObjects.factor;
                if (pvVar30 != (void *)0x0) {
                  operator.delete(pvVar30);
                }
                std::_Hashtable<>::~_Hashtable
                          ((_Hashtable<> *)&(this_00->GJBaseGameLayer_data).m_hideGround);
              }
              else {
                if (pCVar14 < (CCArray *)0x2000000000000000) {
                  __s_02 = operator.new((void *)((long)pCVar14 << 3));
                  memset(__s_02,0,(size_t)((long)pCVar14 << 3));
                  goto LAB_006e7168;
                }
                    
                uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e712c with catch @ 006e7a84
                       catch() { ... } // from try @ 006e7a80 with catch @ 006e7a84 */
              }
              piVar31 = (this_00->GJBaseGameLayer_data).m_unk33a0.start;
              if (piVar31 != (int *)0x0) {
                operator.delete(piVar31);
              }
              std::_Hashtable<>::~_Hashtable
                        ((_Hashtable<> *)&(this_00->GJBaseGameLayer_data).m_unk3358.last);
            }
            else {
              if (ppvVar15 < (void **)0x2000000000000000) {
                __s_01 = operator.new((void *)((long)ppvVar15 << 3));
                memset(__s_01,0,(size_t)((long)ppvVar15 << 3));
                goto LAB_006e70f4;
              }
                    
              uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e70b8 with catch @ 006e7810
                       catch() { ... } // from try @ 006e780c with catch @ 006e7810 */
            }
            ppvVar15 = (this_00->GJBaseGameLayer_data).m_unk3340.last;
            if (ppvVar15 != (void **)0x0) {
              operator.delete(ppvVar15);
            }
            pPVar20 = (this_00->GJBaseGameLayer_data).m_queuedReplayButtons.last;
            if (pPVar20 != (PlayerButtonCommand *)0x0) {
              operator.delete(pPVar20);
            }
            pPVar20 = (this_00->GJBaseGameLayer_data).m_queuedButtons.start + -1;
            if (pPVar20 != (PlayerButtonCommand *)&DAT_0134b6b0) {
              FUN_006c93b8(pPVar20,auStack_10);
            }
            pCVar21 = (this_00->GJBaseGameLayer_data).m_unk32c8;
            if (pCVar21 != (CCObject *)0x0) {
              operator.delete(pCVar21);
            }
            pvVar30 = *(void **)&(this_00->GJBaseGameLayer_data).m_updateGroundShadows;
            if (pvVar30 != (void *)0x0) {
              operator.delete(pvVar30);
            }
            pCVar26 = (this_00->GJBaseGameLayer_data).m_flashNode;
            if (pCVar26 != (CCNode *)0x0) {
              operator.delete(pCVar26);
            }
            ppSVar22 = (this_00->GJBaseGameLayer_data).m_sequenceTriggers.start;
            if (ppSVar22 != (SequenceTriggerGameObject **)0x0) {
              operator.delete(ppSVar22);
            }
            std::_Hashtable<>::~_Hashtable
                      ((_Hashtable<> *)&(this_00->GJBaseGameLayer_data).m_gradientLayers);
            puVar41 = (this_00->GJBaseGameLayer_data).m_customParticlesUIDs.listptr;
            while (puVar41 != (unordered_set_node<int> *)0x0) {
              puVar35 = puVar41->next;
              puVar28 = (undefined8 *)(puVar41->hash - 0x18);
              if (puVar28 != &DAT_0134b6b0) {
                piVar31 = (int *)(puVar41->hash - 8);
                do {
                  iVar3 = *piVar31;
                  cVar5 = '\x01';
                  bVar4 = (bool)ExclusiveMonitorPass(piVar31,0x10);
                  if (bVar4) {
                    *piVar31 = iVar3 + -1;
                    cVar5 = ExclusiveMonitorsStatus();
                  }
                } while (cVar5 != '\0');
                if (iVar3 < 1) {
                  operator.delete(puVar28);
                }
              }
              operator.delete(puVar41);
              puVar41 = puVar35;
            }
            memset((this_00->GJBaseGameLayer_data).m_claimedParticles,0,
                   (long)(this_00->GJBaseGameLayer_data).m_temporaryParticles << 3);
            pCVar12 = (this_00->GJBaseGameLayer_data).m_claimedParticles;
            (this_00->GJBaseGameLayer_data).m_customParticlesUIDs.listlen = 0;
            (this_00->GJBaseGameLayer_data).m_customParticlesUIDs.listptr =
                 (unordered_set_node<int> *)0x0;
            if ((pCVar12 != (CCDictionary *)0x0) &&
               (pCVar12 !=
                (CCDictionary *)&(this_00->GJBaseGameLayer_data).m_customParticlesUIDs.factor)) {
              operator.delete(pCVar12);
            }
          }
          else {
            if (pCVar14 < (CCArray *)0x2000000000000000) {
              pCVar12 = operator.new((void *)((long)pCVar14 << 3));
              memset(pCVar12,0,(size_t)((long)pCVar14 << 3));
              goto LAB_006e6efc;
            }
                    
            uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e6ec4 with catch @ 006e77c8
                       catch() { ... } // from try @ 006e77c4 with catch @ 006e77c8 */
          }
          std::_Hashtable<>::~_Hashtable
                    ((_Hashtable<> *)&(this_00->GJBaseGameLayer_data).m_enterEasingValuesIndex);
          pvVar30 = *(void **)&(this_00->GJBaseGameLayer_data).m_enterEasingIndices.factor;
          if (pvVar30 != (void *)0x0) {
            operator.delete(pvVar30);
          }
          puVar29 = (this_00->GJBaseGameLayer_data).m_enterEasingIndices.listptr;
          while (puVar29 != (unordered_map_node<int,int> *)0x0) {
            std::_Rb_tree<>::_M_erase
                      ((_Rb_tree<> *)&(this_00->GJBaseGameLayer_data).m_enterEasingValues.last,
                       (_Rb_tree_node *)puVar29[1].next);
            puVar33 = (unordered_map_node<int,int> *)puVar29->hash;
            operator.delete(puVar29);
            puVar29 = puVar33;
          }
          pvVar30 = *(void **)((this_00->GJBaseGameLayer_data).m_varianceValues + 5);
          while (pvVar30 != (void *)0x0) {
            std::_Rb_tree<>::_M_erase
                      ((_Rb_tree<> *)((this_00->GJBaseGameLayer_data).m_varianceValues + 1),
                       *(_Rb_tree_node **)((long)pvVar30 + 0x18));
            pvVar34 = *(void **)((long)pvVar30 + 0x10);
            operator.delete(pvVar30);
            pvVar30 = pvVar34;
          }
          std::_Hashtable<>::~_Hashtable
                    ((_Hashtable<> *)&(this_00->GJBaseGameLayer_data).m_spawnTuples);
        }
        else {
          if (uVar6 < 0x2000000000000000) {
            __s_00 = operator.new((void *)(uVar6 << 3));
            memset(__s_00,0,(size_t)(uVar6 << 3));
            goto LAB_006e6dcc;
          }
                    
          uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e6d94 with catch @ 006e78e4
                       catch() { ... } // from try @ 006e78e0 with catch @ 006e78e4 */
        }
        std::_Hashtable<>::~_Hashtable
                  ((_Hashtable<> *)&(this_00->GJBaseGameLayer_data).m_timeLabelObjects);
      }
      else {
        if (uVar6 < 0x2000000000000000) {
          __s = operator.new((void *)(uVar6 << 3));
          memset(__s,0,(size_t)(uVar6 << 3));
          goto LAB_006e6d70;
        }
                    
        uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e6d38 with catch @ 006e78c4
                       catch() { ... } // from try @ 006e78c0 with catch @ 006e78c4 */
      }
      pCVar26 = (this_00->GJBaseGameLayer_data).m_objectParent;
      while (pCVar26 != (CCNode *)0x0) {
        pCVar36 = (CCNode *)pCVar26->CCCopying;
        operator.delete(pCVar26);
        pCVar26 = pCVar36;
      }
      memset((this_00->GJBaseGameLayer_data).m_linkedGroupDict,0,
             *(long *)&(this_00->GJBaseGameLayer_data).m_lastUsedLinkedID << 3);
      pCVar12 = (this_00->GJBaseGameLayer_data).m_linkedGroupDict;
      (this_00->GJBaseGameLayer_data).m_inShaderParent = (CCNode *)0x0;
      (this_00->GJBaseGameLayer_data).m_objectParent = (CCNode *)0x0;
      if ((pCVar12 != (CCDictionary *)0x0) &&
         (pCVar12 != (CCDictionary *)&(this_00->GJBaseGameLayer_data).m_inShaderObjectLayer)) {
        operator.delete(pCVar12);
      }
    }
    else {
      if (uVar6 < 0x2000000000000000) {
        pCVar12 = operator.new((void *)(uVar6 << 3));
        memset(pCVar12,0,(size_t)(uVar6 << 3));
        goto LAB_006e6ce8;
      }
                    
      uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e6cac with catch @ 006e78f8
                       catch() { ... } // from try @ 006e78f4 with catch @ 006e78f8 */
    }
    puVar23 = (this_00->GJBaseGameLayer_data).m_targetGroups.listptr;
    if (puVar23 != (unordered_map_node<> *)0x0) {
      operator.delete(puVar23);
    }
    pCVar12 = (this_00->GJBaseGameLayer_data).m_parentGroupIDs;
    if (pCVar12 != (CCDictionary *)0x0) {
      operator.delete(pCVar12);
    }
    ppCVar24 = (this_00->GJBaseGameLayer_data).m_optimizedGroups.last;
    if (ppCVar24 != (CCArray **)0x0) {
      operator.delete(ppCVar24);
    }
    pvVar30 = *(void **)&(this_00->GJBaseGameLayer_data).m_disabledObjectsIndex;
    if (pvVar30 != (void *)0x0) {
      operator.delete(pvVar30);
    }
    pvVar30 = *(void **)&(this_00->GJBaseGameLayer_data).m_visibleObjects2Count;
    if (pvVar30 != (void *)0x0) {
      operator.delete(pvVar30);
    }
    pGVar18 = (GameObject *)(this_00->GJBaseGameLayer_data).m_visibleObjects.capacity;
    while (pGVar18 != (GameObject *)0x0) {
      pvVar30 = *(void **)&(pGVar18->CCObject_data).m_nTag;
      pGVar37 = (GameObject *)pGVar18->CCCopying;
      if (pvVar30 != (void *)0x0) {
        operator.delete(pvVar30);
      }
      operator.delete(pGVar18);
      pGVar18 = pGVar37;
    }
    memset((this_00->GJBaseGameLayer_data).m_visibleObjects.start,0,
           (long)(this_00->GJBaseGameLayer_data).m_visibleObjects.last << 3);
    ppGVar10 = (this_00->GJBaseGameLayer_data).m_visibleObjects.start;
    (this_00->GJBaseGameLayer_data).m_visibleObjectsCount = 0;
    (this_00->GJBaseGameLayer_data).m_visibleObjectsIndex = 0;
    (this_00->GJBaseGameLayer_data).m_visibleObjects.capacity = (GameObject **)0x0;
    if ((ppGVar10 != (GameObject **)0x0) &&
       (ppGVar10 != (GameObject **)&(this_00->GJBaseGameLayer_data).m_visibleObjects2.capacity)) {
      operator.delete(ppGVar10);
    }
  }
  else {
    if (ppGVar10 < (GameObject **)0x2000000000000000) {
      pppGVar11 = operator.new((void *)((long)ppGVar10 << 3));
      memset(pppGVar11,0,(size_t)((long)ppGVar10 << 3));
      goto LAB_006e6bf8;
    }
                    
    uVar25 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e6bc0 with catch @ 006e7990
                       catch() { ... } // from try @ 006e798c with catch @ 006e7990 */
  }
  pvVar30 = *(void **)&(this_00->GJBaseGameLayer_data).m_visibilityGroups.factor;
  if (pvVar30 != (void *)0x0) {
    operator.delete(pvVar30);
  }
  pvVar30 = (void *)(this_00->GJBaseGameLayer_data).m_visibilityGroups.listlen;
  if (pvVar30 != (void *)0x0) {
    operator.delete(pvVar30);
  }
  ppGVar10 = (this_00->GJBaseGameLayer_data).m_processedAreaObjects.last;
  if (ppGVar10 != (GameObject **)0x0) {
    operator.delete(ppGVar10);
  }
  ppGVar10 = (this_00->GJBaseGameLayer_data).m_areaObjects.last;
  if (ppGVar10 != (GameObject **)0x0) {
    operator.delete(ppGVar10);
  }
  ppGVar10 = (this_00->GJBaseGameLayer_data).m_unke08.last;
  if (ppGVar10 != (GameObject **)0x0) {
    operator.delete(ppGVar10);
  }
  std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&(this_00->GJBaseGameLayer_data).m_effectManager);
  puVar7 = (this_00->GJBaseGameLayer_data).m_uiObjectPositions.start;
  while (puVar7 != (unordered_map_node<> *)0x0) {
    puVar39 = puVar7->next;
    operator.delete(puVar7);
    puVar7 = puVar39;
  }
  memset((this_00->GJBaseGameLayer_data).m_uiObjectPositions.listptr,0,
         (this_00->GJBaseGameLayer_data).m_uiObjectPositions.listlen << 3);
  puVar7 = (this_00->GJBaseGameLayer_data).m_uiObjectPositions.listptr;
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.size = 0;
  (this_00->GJBaseGameLayer_data).m_uiObjectPositions.start = (unordered_map_node<> *)0x0;
  if ((puVar7 != (unordered_map_node<> *)0x0) &&
     (puVar7 != (unordered_map_node<> *)&(this_00->GJBaseGameLayer_data).m_uiObjectPositions.single)
     ) {
    operator.delete(puVar7);
  }
LAB_006e7968:
  puVar40 = (this_00->GJBaseGameLayer_data).m_spawnRemapTriggers.last;
  for (puVar38 = (this_00->GJBaseGameLayer_data).m_spawnRemapTriggers.start; puVar40 != puVar38;
      puVar38 = puVar38 + 1) {
    std::_Hashtable<>::~_Hashtable((_Hashtable<> *)puVar38);
  }
  puVar38 = (this_00->GJBaseGameLayer_data).m_spawnRemapTriggers.start;
  if (puVar38 != (unordered_map<int,int> *)0x0) {
    operator.delete(puVar38);
  }
  ppvVar15 = (this_00->GJBaseGameLayer_data).m_unk8a0.start;
  if (ppvVar15 != (void **)0x0) {
    operator.delete(ppvVar15);
  }
  ppSVar32 = (this_00->GJBaseGameLayer_data).m_activeSfxTriggers.start;
  if (ppSVar32 != (SFXTriggerGameObject **)0x0) {
    operator.delete(ppSVar32);
  }
  GJGameState::~GJGameState(this);
  cocos2d::CCLayer::~CCLayer((CCLayer *)this_00);
  operator.delete(this_00);
                    
  _Unwind_Resume(uVar25);
}





void PlayLayer::createCheckpoint(PlayLayer *this)

{
  float *this_00;
  bool *this_01;
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  bool bVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined2 uVar27;
  CCPoint CVar28;
  void *pvVar29;
  void *pvVar30;
  GroupCommandObject2 *pGVar31;
  char cVar32;
  PlayerCheckpoint *this_02;
  CCObject *pCVar33;
  FMODAudioEngine *pFVar34;
  GameObject *pGVar35;
  ulong *puVar36;
  _Hashtable<> *this_03;
  undefined8 *puVar37;
  GameObject *pGVar38;
  CCPoint *pCVar39;
  undefined8 uVar40;
  CCActionManager *pCVar41;
  CCNode *pCVar42;
  CCObject *pCVar43;
  ulong uVar44;
  GameObject *pGVar45;
  long lVar46;
  void *pvVar47;
  CCDictionary *pCVar48;
  void *pvVar49;
  CCObject *pCVar50;
  code *pcVar51;
  size_t __n;
  GameObject **ppGVar52;
  GroupCommandObject2 *pGVar53;
  void *pvVar54;
  CCPoint CVar55;
  CCDictionary *pCVar56;
  GroupCommandObject2 *pGVar57;
  undefined1 *puVar58;
  GroupCommandObject2 *pGVar59;
  CCPoint *local_318;
  CCPoint local_310;
  float *local_308;
  void *local_2f8;
  undefined8 *local_2e0;
  ulong local_2d8;
  undefined4 local_2c0 [4];
  undefined8 local_2b0;
  undefined8 *local_2a8;
  ulong local_2a0;
  undefined8 local_298;
  undefined8 local_290;
  undefined4 local_288 [2];
  undefined8 local_280;
  undefined8 local_278;
  undefined8 *local_270;
  long local_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined4 local_250 [2];
  undefined8 local_248;
  undefined8 local_240;
  _Rb_tree<> a_Stack_238 [8];
  undefined4 local_230 [2];
  void *local_228;
  undefined4 *local_220;
  undefined4 *local_218;
  undefined8 local_210;
  undefined8 *local_208;
  ulong local_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined4 local_1e8 [2];
  undefined8 local_1e0;
  undefined8 local_1d8;
  void *local_1d0;
  void *local_1c8;
  undefined8 local_1c0;
  void *local_1b8;
  void *local_1b0;
  undefined8 local_1a8;
  void *local_1a0;
  void *local_198;
  undefined8 local_190;
  void *local_188;
  void *local_180;
  undefined8 local_178;
  undefined8 *local_170;
  long local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined4 local_150 [2];
  undefined8 local_148;
  undefined8 local_140;
  undefined8 *local_138;
  long local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined4 local_118 [2];
  undefined8 local_110;
  undefined8 local_108;
  GroupCommandObject2 *local_100;
  GroupCommandObject2 *local_f8;
  undefined8 local_f0;
  undefined8 *local_e8;
  ulong local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  long local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90 [2];
  undefined8 local_88;
  undefined8 local_80;
  undefined8 *local_78;
  ulong local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 *local_40;
  ulong local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20 [2];
  undefined8 local_18;
  undefined8 local_10;
  CheckpointObject *local_8;
  
  local_8 = ___stack_chk_guard;
  this_02 = (PlayerCheckpoint *)CheckpointObject::create(___stack_chk_guard);
  pCVar33 = (CCObject *)PlayerCheckpoint::create(this_02);
  pCVar43 = *(CCObject **)&this_02[2].PlayerCheckpoint_data.m_unk3e0;
  if (pCVar33 != pCVar43) {
    if (pCVar33 != (CCObject *)0x0) {
      cocos2d::CCObject::retain(pCVar33);
      pCVar43 = *(CCObject **)&this_02[2].PlayerCheckpoint_data.m_unk3e0;
    }
    if (pCVar43 != (CCObject *)0x0) {
      cocos2d::CCObject::release(pCVar43);
    }
    *(CCObject **)&this_02[2].PlayerCheckpoint_data.m_unk3e0 = pCVar33;
  }
  PlayerObject::saveToCheckpoint
            ((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0,(PlayerCheckpoint *)pCVar33);
  bVar18 = (this->GJBaseGameLayer_data).m_gameState.m_isDualMode;
  if (bVar18 != false) {
    pCVar33 = (CCObject *)PlayerCheckpoint::create((PlayerCheckpoint *)(ulong)bVar18);
    pCVar43 = (CCObject *)this_02[2].PlayerCheckpoint_data.m_collidedTopMinY;
    if (pCVar43 != pCVar33) {
      if (pCVar33 != (CCObject *)0x0) {
        cocos2d::CCObject::retain(pCVar33);
        pCVar43 = (CCObject *)this_02[2].PlayerCheckpoint_data.m_collidedTopMinY;
      }
      if (pCVar43 != (CCObject *)0x0) {
        cocos2d::CCObject::release(pCVar43);
      }
      this_02[2].PlayerCheckpoint_data.m_collidedTopMinY = (double)pCVar33;
    }
    PlayerObject::saveToCheckpoint
              ((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start,
               (PlayerCheckpoint *)pCVar33);
  }
  GJGameState::operator=
            ((GJGameState *)&(this_02->PlayerCheckpoint_data).m_position.y,
             (GJGameState *)&(this->GJBaseGameLayer_data).m_gameState);
  ppGVar52 = (this->GJBaseGameLayer_data).m_solidCollisionObjects.capacity;
  uVar1 = (this->GJBaseGameLayer_data).m_gameState.m_commandIndex;
  pFVar34 = (FMODAudioEngine *)(ulong)uVar1;
  *(uint *)&this_02[3].PlayerCheckpoint_data.m_decreaseBoostSlide = uVar1;
  if (ppGVar52 != (GameObject **)0x0) {
    this_00 = &this_02[1].PlayerCheckpoint_data.m_trailingParticleLife;
    std::_Hashtable<>::operator=
              ((_Hashtable<> *)&this_02[1].PlayerCheckpoint_data.unk_584,
               (_Hashtable *)(ppGVar52 + 0x33));
    if ((_Hashtable *)this_00 != (_Hashtable *)(ppGVar52 + 0x3a)) {
      pGVar35 = (GameObject *)this_02[1].PlayerCheckpoint_data.m_gameModeChangedTime;
      if (pGVar35 == ppGVar52[0x3b]) {
        puVar58 = (undefined1 *)0x0;
        memset(*(void **)&this_02[1].PlayerCheckpoint_data.m_trailingParticleLife,0,
               (long)pGVar35 << 3);
      }
      else {
        puVar58 = *(undefined1 **)&this_02[1].PlayerCheckpoint_data.m_trailingParticleLife;
        if (ppGVar52[0x3b] == (GameObject *)0x1) {
          this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.listlen = 0;
          puVar36 = &this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.listlen;
          pGVar35 = (GameObject *)0x1;
        }
        else {
          puVar36 = (ulong *)FUN_006c9a0c();
          pGVar35 = ppGVar52[0x3b];
        }
        *(ulong **)&this_02[1].PlayerCheckpoint_data.m_trailingParticleLife = puVar36;
        this_02[1].PlayerCheckpoint_data.m_gameModeChangedTime = (double)pGVar35;
      }
      local_318 = &local_310;
      pGVar35 = ppGVar52[0x3e];
      pGVar45 = ppGVar52[0x3f];
      local_310 = *(CCPoint *)&this_02[1].PlayerCheckpoint_data.m_padRingRelated;
      this_02[1].PlayerCheckpoint_data.m_lastSpiderFlipTime = (double)ppGVar52[0x3d];
      *(GameObject **)&this_02[1].PlayerCheckpoint_data.m_unkBool5 = pGVar35;
      this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.listptr = (unordered_set_node<int> *)pGVar45
      ;
      this_02[1].PlayerCheckpoint_data.m_padRingRelated = false;
      this_02[1].PlayerCheckpoint_data.m_maybeIsFalling = false;
      this_02[1].PlayerCheckpoint_data.m_shouldTryPlacingCheckpoint = false;
      this_02[1].PlayerCheckpoint_data.m_playEffects = false;
      this_02[1].PlayerCheckpoint_data.m_maybeCanRunIntoBlocks = false;
      this_02[1].PlayerCheckpoint_data.m_isOnGround3 = false;
      *(undefined2 *)&this_02[1].PlayerCheckpoint_data.field_0x1dc = 0;
      local_308 = this_00;
                    
      std::_Hashtable<>::operator=
                ((_Hashtable<> *)this_00,(_Hashtable *)(ppGVar52 + 0x3a),
                 ({lambda(std::__detail::_Hash_node<>_const*)#2} *)&local_318);
      CVar28 = local_310;
      if ((puVar58 != (undefined1 *)0x0) &&
         ((ulong *)puVar58 != &this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.listlen)) {
        operator.delete(puVar58);
        CVar28 = local_310;
      }
      while (CVar28 != (CCPoint)0x0) {
        CVar55 = *(CCPoint *)CVar28;
        operator.delete((void *)CVar28);
        CVar28 = CVar55;
      }
    }
    uVar27 = *(undefined2 *)(ppGVar52 + 0x45);
    pGVar45 = ppGVar52[0x42];
    uVar2 = *(undefined4 *)(ppGVar52 + 0x46);
    pGVar35 = ppGVar52[0x43];
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x234);
    uVar3 = *(undefined4 *)(ppGVar52 + 0x44);
    uVar4 = *(undefined4 *)((long)ppGVar52 + 0x224);
    this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.start =
         (unordered_set_node<int> *)ppGVar52[0x41];
    this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.size = (ulong)pGVar45;
    *(GameObject **)&this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.factor = pGVar35;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.resize = uVar3;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.resize + 4) = uVar4;
    *(undefined2 *)&this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.single = uVar27;
    fVar5 = *(float *)(ppGVar52 + 0x47);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.single + 2) =
         *(undefined1 *)((long)ppGVar52 + 0x22a);
    uVar3 = *(undefined4 *)((long)ppGVar52 + 0x23c);
    uVar4 = *(undefined4 *)((long)ppGVar52 + 0x22c);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_maybeSpriteRelated = uVar2;
    uVar2 = *(undefined4 *)(ppGVar52 + 0x48);
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_landParticlesAngle = uVar19;
    uVar6 = *(undefined4 *)((long)ppGVar52 + 0x244);
    uVar7 = *(undefined4 *)(ppGVar52 + 0x49);
    uVar8 = *(undefined4 *)((long)ppGVar52 + 0x24c);
    uVar9 = *(undefined4 *)(ppGVar52 + 0x4a);
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_ringRelatedSet.single + 4) = uVar4;
    this_02[1].PlayerCheckpoint_data.m_landParticleRelatedY = fVar5;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.field_0x232 = uVar3;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_slopeRotation = uVar2;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_slopeRotation + 4) = uVar6;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_currentSlopeYVelocity = uVar7;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_currentSlopeYVelocity + 4) = uVar8;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_unk3d0 = uVar9;
    uVar2 = *(undefined4 *)((long)ppGVar52 + 0x254);
    uVar3 = *(undefined4 *)(ppGVar52 + 0x4d);
    uVar4 = *(undefined4 *)(ppGVar52 + 0x4b);
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x26c);
    uVar6 = *(undefined4 *)(ppGVar52 + 0x4c);
    uVar20 = *(undefined1 *)((long)ppGVar52 + 0x26d);
    uVar7 = *(undefined4 *)((long)ppGVar52 + 0x264);
    uVar21 = *(undefined1 *)((long)ppGVar52 + 0x26e);
    uVar8 = *(undefined4 *)(ppGVar52 + 0x4e);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_blackOrbRelated + 4) =
         *(undefined1 *)((long)ppGVar52 + 0x25c);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_collidedTopMinY = uVar3;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_collidedTopMinY + 4) = uVar19;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_collidedTopMinY + 5) = uVar20;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_collidedTopMinY + 6) = uVar21;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_unk3d0 + 4) = uVar2;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_blackOrbRelated = uVar4;
    this_02[1].PlayerCheckpoint_data.m_unk3e0 = (bool)(char)uVar6;
    this_02[1].PlayerCheckpoint_data.m_unk3e1 = (bool)(char)((uint)uVar6 >> 8);
    this_02[1].PlayerCheckpoint_data.m_isAccelerating = (bool)(char)((uint)uVar6 >> 0x10);
    this_02[1].PlayerCheckpoint_data.m_isCurrentSlopeTop = (bool)(char)((uint)uVar6 >> 0x18);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.field_0x25a = uVar7;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_collidedBottomMaxY = uVar8;
    cocos2d::CCPoint::operator=
              ((CCPoint *)((long)&this_02[1].PlayerCheckpoint_data.m_collidedBottomMaxY + 4),
               (CCPoint *)((long)ppGVar52 + 0x274));
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_collidedLeftMaxX + 4) =
         *(undefined1 *)((long)ppGVar52 + 0x27c);
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.m_collidedRightMinX,
               (CCPoint *)(ppGVar52 + 0x50));
    pGVar35 = ppGVar52[0x51];
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x29d);
    uVar20 = *(undefined1 *)((long)ppGVar52 + 0x29e);
    uVar2 = *(undefined4 *)(ppGVar52 + 0x52);
    fVar5 = *(float *)(ppGVar52 + 0x57);
    uVar3 = *(undefined4 *)(ppGVar52 + 0x54);
    uVar21 = *(undefined1 *)((long)ppGVar52 + 700);
    uVar4 = *(undefined4 *)((long)ppGVar52 + 0x2a4);
    uVar22 = *(undefined1 *)((long)ppGVar52 + 0x29f);
    uVar6 = *(undefined4 *)(ppGVar52 + 0x55);
    uVar7 = *(undefined4 *)((long)ppGVar52 + 0x294);
    uVar8 = *(undefined4 *)(ppGVar52 + 0x53);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_yVelocity + 4) =
         *(undefined1 *)((long)ppGVar52 + 0x29c);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_yVelocity + 5) = uVar19;
    iVar10 = *(int *)((long)ppGVar52 + 0x2ac);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_yVelocity + 6) = uVar20;
    uVar9 = *(undefined4 *)(ppGVar52 + 0x56);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_yVelocity + 7) = uVar22;
    uVar11 = *(undefined4 *)((long)ppGVar52 + 0x2b4);
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x2bd);
    *(GameObject **)&this_02[1].PlayerCheckpoint_data.m_wasJumpBuffered = pGVar35;
    this_02[1].PlayerCheckpoint_data.m_xVelocityRelated2 = fVar5;
    this_02[1].PlayerCheckpoint_data.m_stateRingJump2 = (bool)(char)uVar2;
    this_02[1].PlayerCheckpoint_data.m_touchedRing = (bool)(char)((uint)uVar2 >> 8);
    this_02[1].PlayerCheckpoint_data.m_touchedCustomRing = (bool)(char)((uint)uVar2 >> 0x10);
    this_02[1].PlayerCheckpoint_data.m_touchedGravityPortal = (bool)(char)((uint)uVar2 >> 0x18);
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_shipRotation.x = uVar21;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_fallSpeed = uVar3;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_fallSpeed + 4) = uVar4;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_maybeUpsideDownSlope = uVar6;
    this_02[1].PlayerCheckpoint_data.m_reverseRelated = iVar10;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_maybeReverseAcceleration = uVar9;
    this_02[1].PlayerCheckpoint_data.m_maybeTouchedBreakableBlock = (bool)(char)uVar7;
    this_02[1].PlayerCheckpoint_data.m_touchedPad = (bool)(char)((uint)uVar7 >> 8);
    *(short *)&this_02[1].PlayerCheckpoint_data.field_0x28c = (short)((uint)uVar7 >> 0x10);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_yVelocity = uVar8;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_maybeReverseAcceleration + 4) = uVar11
    ;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_shipRotation.x + 1) = uVar19;
    fVar5 = *(float *)(ppGVar52 + 0x58);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_shipRotation.x + 2) =
         *(undefined1 *)((long)ppGVar52 + 0x2be);
    this_02[1].PlayerCheckpoint_data.m_shipRotation.y = fVar5;
    cocos2d::CCPoint::operator=
              (&this_02[1].PlayerCheckpoint_data.m_lastPortalPos,(CCPoint *)((long)ppGVar52 + 0x2c4)
              );
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_unkUnused3 =
         *(undefined1 *)((long)ppGVar52 + 0x2cc);
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.m_isOnGround2,
               (CCPoint *)(ppGVar52 + 0x5a));
    uVar2 = *(undefined4 *)(ppGVar52 + 0x5b);
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x2fc);
    uVar3 = *(undefined4 *)((long)ppGVar52 + 0x2dc);
    fVar5 = *(float *)(ppGVar52 + 0x5c);
    uVar4 = *(undefined4 *)((long)ppGVar52 + 0x2e4);
    uVar6 = *(undefined4 *)(ppGVar52 + 0x5d);
    uVar7 = *(undefined4 *)((long)ppGVar52 + 0x2ec);
    this_02[1].PlayerCheckpoint_data.m_isLocked = *(bool *)(ppGVar52 + 0x5e);
    fVar12 = *(float *)((long)ppGVar52 + 0x2f4);
    fVar13 = *(float *)(ppGVar52 + 0x5f);
    this_02[1].PlayerCheckpoint_data.field_0x2f2 = uVar19;
    uVar8 = *(undefined4 *)(ppGVar52 + 0x60);
    uVar9 = *(undefined4 *)((long)ppGVar52 + 0x304);
    uVar11 = *(undefined4 *)(ppGVar52 + 0x61);
    uVar14 = *(undefined4 *)((long)ppGVar52 + 0x30c);
    uVar15 = *(undefined4 *)(ppGVar52 + 0x62);
    uVar16 = *(undefined4 *)((long)ppGVar52 + 0x314);
    uVar17 = *(undefined4 *)(ppGVar52 + 99);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_lastLandTime = uVar2;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_lastLandTime + 4) = uVar3;
    this_02[1].PlayerCheckpoint_data.m_platformerVelocityRelated = fVar5;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_maybeIsBoosted = uVar4;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_scaleXRelatedTime = uVar6;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_scaleXRelatedTime + 4) = uVar7;
    this_02[1].PlayerCheckpoint_data.m_lastGroundedPos.x = fVar12;
    this_02[1].PlayerCheckpoint_data.m_lastGroundedPos.y = fVar13;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_touchingRings = uVar8;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchingRings + 4) = uVar9;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_touchedRings.listptr = uVar11;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.listptr + 4) = uVar14;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_touchedRings.listlen = uVar15;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.listlen + 4) = uVar16;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_touchedRings.start = uVar17;
    uVar19 = *(undefined1 *)(ppGVar52 + 100);
    uVar2 = *(undefined4 *)((long)ppGVar52 + 0x31c);
    uVar20 = *(undefined1 *)((long)ppGVar52 + 0x321);
    uVar3 = *(undefined4 *)((long)ppGVar52 + 0x324);
    uVar21 = *(undefined1 *)((long)ppGVar52 + 0x322);
    fVar5 = *(float *)(ppGVar52 + 0x65);
    uVar22 = *(undefined1 *)((long)ppGVar52 + 0x323);
    uVar4 = *(undefined4 *)(ppGVar52 + 0x66);
    uVar23 = *(undefined1 *)((long)ppGVar52 + 0x32c);
    uVar6 = *(undefined4 *)((long)ppGVar52 + 0x334);
    uVar24 = *(undefined1 *)((long)ppGVar52 + 0x32d);
    uVar7 = *(undefined4 *)(ppGVar52 + 0x67);
    uVar25 = *(undefined1 *)((long)ppGVar52 + 0x32e);
    uVar26 = *(undefined1 *)((long)ppGVar52 + 0x32f);
    uVar8 = *(undefined4 *)((long)ppGVar52 + 0x33c);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_lastActivatedPortal =
         *(undefined4 *)(ppGVar52 + 0x68);
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.start + 4) = uVar2;
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_touchedRings.size = uVar19;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.size + 1) = uVar20;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.size + 2) = uVar21;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.size + 3) = uVar22;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.size + 4) = uVar3;
    this_02[1].PlayerCheckpoint_data.m_touchedRings.field_0x24 = uVar23;
    this_02[1].PlayerCheckpoint_data.m_touchedRings.factor = fVar5;
    this_02[1].PlayerCheckpoint_data.m_touchedRings.field_0x25 = uVar24;
    this_02[1].PlayerCheckpoint_data.m_touchedRings.field_0x26 = uVar25;
    this_02[1].PlayerCheckpoint_data.m_touchedRings.field_0x27 = uVar26;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_touchedRings.resize = uVar4;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.single + 4) = uVar8;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_touchedRings.resize + 4) = uVar6;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_touchedRings.single = uVar7;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_lastActivatedPortal + 4) =
         *(undefined1 *)((long)ppGVar52 + 0x344);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_lastActivatedPortal + 5) =
         *(undefined1 *)((long)ppGVar52 + 0x345);
    *(undefined2 *)((long)&this_02[1].PlayerCheckpoint_data.m_lastActivatedPortal + 6) =
         *(undefined2 *)((long)ppGVar52 + 0x346);
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_totalTime = *(undefined1 *)(ppGVar52 + 0x69);
    cocos2d::CCPoint::operator=
              ((CCPoint *)((long)&this_02[1].PlayerCheckpoint_data.m_totalTime + 4),
               (CCPoint *)((long)ppGVar52 + 0x34c));
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.m_defaultMiniIcon,
               (CCPoint *)((long)ppGVar52 + 0x354));
    uVar2 = *(undefined4 *)((long)ppGVar52 + 0x35c);
    iVar10 = *(int *)(ppGVar52 + 0x6c);
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x364);
    this_02[1].PlayerCheckpoint_data.m_maybeStateForce2 = *(int *)(ppGVar52 + 0x6d);
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_stateBoostY = uVar19;
    this_02[1].PlayerCheckpoint_data.m_stateUnk = (char)uVar2;
    this_02[1].PlayerCheckpoint_data.m_stateNoStickX = (char)((uint)uVar2 >> 8);
    this_02[1].PlayerCheckpoint_data.m_stateNoStickY = (char)((uint)uVar2 >> 0x10);
    this_02[1].PlayerCheckpoint_data.m_stateUnk2 = (char)((uint)uVar2 >> 0x18);
    this_02[1].PlayerCheckpoint_data.m_stateBoostX = iVar10;
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.m_stateScale,
               (CCPoint *)((long)ppGVar52 + 0x36c));
    cocos2d::CCPoint::operator=
              ((CCPoint *)((long)&this_02[1].PlayerCheckpoint_data.m_platformerXVelocity + 4),
               (CCPoint *)((long)ppGVar52 + 0x374));
    uVar2 = *(undefined4 *)((long)ppGVar52 + 0x37c);
    uVar3 = *(undefined4 *)(ppGVar52 + 0x75);
    uVar4 = *(undefined4 *)(ppGVar52 + 0x70);
    uVar6 = *(undefined4 *)(ppGVar52 + 0x73);
    uVar7 = *(undefined4 *)((long)ppGVar52 + 900);
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x39d);
    uVar20 = *(undefined1 *)((long)ppGVar52 + 0x3a4);
    uVar8 = *(undefined4 *)(ppGVar52 + 0x71);
    uVar21 = *(undefined1 *)((long)ppGVar52 + 0x39c);
    fVar5 = *(float *)((long)ppGVar52 + 0x38c);
    uVar9 = *(undefined4 *)(ppGVar52 + 0x72);
    uVar11 = *(undefined4 *)(ppGVar52 + 0x74);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.field_0x38a =
         *(undefined4 *)((long)ppGVar52 + 0x394);
    uVar14 = *(undefined4 *)((long)ppGVar52 + 0x3ac);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_physDeltaRelated = uVar3;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_maybeSlopeForce = uVar6;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_maybeSlopeForce + 5) = uVar19;
    this_02[1].PlayerCheckpoint_data.field_0x39a = uVar20;
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_maybeSlopeForce + 4) = uVar21;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.field_0x372 = uVar2;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_scaleXRelated = uVar4;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_scaleXRelated + 4) = uVar7;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_maybeHasStopped = uVar8;
    this_02[1].PlayerCheckpoint_data.m_xVelocityRelated = fVar5;
    this_02[1].PlayerCheckpoint_data.m_maybeGoingCorrectSlopeDirection = (bool)(char)uVar9;
    this_02[1].PlayerCheckpoint_data.m_isSliding = (bool)(char)((uint)uVar9 >> 8);
    *(short *)&this_02[1].PlayerCheckpoint_data.field_0x388 = (short)((uint)uVar9 >> 0x10);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_isOnIce = uVar11;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_physDeltaRelated + 4) = uVar14;
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.m_isOnGround4,
               (CCPoint *)(ppGVar52 + 0x76));
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.m_maybeSlidingStartTime,
               (CCPoint *)(ppGVar52 + 0x77));
    uVar2 = *(undefined4 *)(ppGVar52 + 0x78);
    uVar19 = *(undefined1 *)((long)ppGVar52 + 0x3c9);
    uVar3 = *(undefined4 *)((long)ppGVar52 + 0x3c4);
    uVar4 = *(undefined4 *)((long)ppGVar52 + 0x3cc);
    uVar6 = *(undefined4 *)(ppGVar52 + 0x7a);
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_slopeEndTime =
         *(undefined1 *)(ppGVar52 + 0x79);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_slopeEndTime + 1) = uVar19;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_slopeEndTime + 4) = uVar4;
    this_02[1].PlayerCheckpoint_data.m_isMoving = (bool)(char)uVar6;
    this_02[1].PlayerCheckpoint_data.m_platformerMovingLeft = (bool)(char)((uint)uVar6 >> 8);
    this_02[1].PlayerCheckpoint_data.m_platformerMovingRight = (bool)(char)((uint)uVar6 >> 0x10);
    this_02[1].PlayerCheckpoint_data.m_isSlidingRight = (bool)(char)((uint)uVar6 >> 0x18);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_changedDirectionsTime = uVar2;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_changedDirectionsTime + 4) = uVar3;
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.field_0x3ca,
               (CCPoint *)((long)ppGVar52 + 0x3d4));
    cocos2d::CCPoint::operator=
              ((CCPoint *)
               ((long)&this_02[1].PlayerCheckpoint_data.m_maybeChangedDirectionsAngle + 4),
               (CCPoint *)((long)ppGVar52 + 0x3dc));
    iVar10 = *(int *)(ppGVar52 + 0x7d);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_unkUnused2 + 4) =
         *(undefined1 *)((long)ppGVar52 + 0x3e4);
    this_02[1].PlayerCheckpoint_data.m_stateNoAutoJump = iVar10;
    cocos2d::CCPoint::operator=
              ((CCPoint *)&this_02[1].PlayerCheckpoint_data.m_stateDartSlide,
               (CCPoint *)((long)ppGVar52 + 0x3ec));
    iVar10 = *(int *)((long)ppGVar52 + 0x3f4);
    fVar5 = *(float *)((long)ppGVar52 + 0x3fc);
    uVar27 = *(undefined2 *)(ppGVar52 + 0x80);
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_stateForce = *(undefined1 *)(ppGVar52 + 0x7f)
    ;
    this_02[1].PlayerCheckpoint_data.m_stateFlipGravity = iVar10;
    this_02[1].PlayerCheckpoint_data.m_stateForceVector.x = fVar5;
    *(undefined2 *)&this_02[1].PlayerCheckpoint_data.m_stateForceVector.y = uVar27;
    uVar2 = *(undefined4 *)(ppGVar52 + 0x81);
    uVar19 = *(undefined1 *)(ppGVar52 + 0x83);
    *(undefined1 *)((long)&this_02[1].PlayerCheckpoint_data.m_stateForceVector.y + 2) =
         *(undefined1 *)((long)ppGVar52 + 0x402);
    uVar3 = *(undefined4 *)((long)ppGVar52 + 0x40c);
    uVar4 = *(undefined4 *)(ppGVar52 + 0x82);
    uVar6 = *(undefined4 *)((long)ppGVar52 + 0x414);
    uVar7 = *(undefined4 *)((long)ppGVar52 + 0x404);
    *(undefined1 *)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.root = uVar19;
    uVar8 = *(undefined4 *)((long)ppGVar52 + 0x41c);
    uVar9 = *(undefined4 *)(ppGVar52 + 0x84);
    uVar11 = *(undefined4 *)((long)ppGVar52 + 0x424);
    uVar14 = *(undefined4 *)(ppGVar52 + 0x85);
    uVar15 = *(undefined4 *)((long)ppGVar52 + 0x42c);
    uVar16 = *(undefined4 *)(ppGVar52 + 0x86);
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field4_0x4 = (char)uVar3;
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field5_0x5 = (char)((uint)uVar3 >> 8);
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field6_0x6 = (char)((uint)uVar3 >> 0x10);
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field7_0x7 = (char)((uint)uVar3 >> 0x18);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.black = uVar4;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field_0xc = uVar6;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.root + 4) = uVar8;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.left = uVar9;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.left + 4) = uVar11;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.right = uVar14;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.right + 4) = uVar15;
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_affectedByForces = uVar7;
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.comparator = (char)uVar2;
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field1_0x1 = (char)((uint)uVar2 >> 8);
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field2_0x2 = (char)((uint)uVar2 >> 0x10);
    this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.field3_0x3 = (char)((uint)uVar2 >> 0x18);
    *(undefined4 *)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.length = uVar16;
    uVar19 = *(undefined1 *)(ppGVar52 + 0x88);
    uVar2 = *(undefined4 *)((long)ppGVar52 + 0x434);
    uVar3 = *(undefined4 *)((long)ppGVar52 + 0x444);
    fVar5 = *(float *)(ppGVar52 + 0x87);
    uVar1 = *(uint *)(ppGVar52 + 0x89);
    uVar4 = *(undefined4 *)((long)ppGVar52 + 0x43c);
    uVar20 = *(undefined1 *)((long)ppGVar52 + 0x44c);
    uVar21 = *(undefined1 *)((long)ppGVar52 + 0x44d);
    pFVar34 = (FMODAudioEngine *)(ulong)*(byte *)((long)ppGVar52 + 0x44e);
    *(byte *)((long)&this_02[2].CCObject_data.m_nLuaID + 2) = *(byte *)((long)ppGVar52 + 0x44e);
    *(undefined1 *)&this_02[2].CCCopying = uVar19;
    *(undefined4 *)((long)&this_02[2].CCCopying + 4) = uVar3;
    this_02[2].CCObject_data.m_uID = uVar1;
    *(undefined1 *)&this_02[2].CCObject_data.m_nLuaID = uVar20;
    *(undefined1 *)((long)&this_02[2].CCObject_data.m_nLuaID + 1) = uVar21;
    *(undefined4 *)((long)&this_02[1].PlayerCheckpoint_data.m_jumpPadRelated.length + 4) = uVar2;
    this_02[1].PlayerCheckpoint_data.m_fallStartY = fVar5;
    *(undefined4 *)&this_02[1].field_0x56c = uVar4;
  }
  pFVar34 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar34);
  FMODAudioEngine::saveAudioState(pFVar34,(FMODAudioState *)&this_02[2].CCObject_data.m_nTag);
  pCVar56 = (this->GJBaseGameLayer_data).m_collectedItems;
  for (pCVar48 = *(CCDictionary **)&(this->GJBaseGameLayer_data).m_updateGroundShadows;
      pCVar56 != pCVar48; pCVar48 = pCVar48 + 8) {
    lVar46 = *(long *)pCVar48;
    local_310.x = *(float *)(lVar46 + 900);
    this_03 = (_Hashtable<> *)
              std::__detail::_Map_base<>::operator[]
                        ((_Map_base<> *)&this_02[3].PlayerCheckpoint_data.m_dashRing,
                         (int *)&local_310);
    std::_Hashtable<>::operator=(this_03,(_Hashtable *)(lVar46 + 0x738));
    std::_Hashtable<>::operator=((_Hashtable<> *)(this_03 + 0x38),(_Hashtable *)(lVar46 + 0x770));
  }
  this_01 = &this_02[2].PlayerCheckpoint_data.m_isOnGround2;
  *(byte *)((long)&this_02[2].PlayerCheckpoint_data.m_collidedLeftMaxX + 4) =
       *(byte *)((this->GJBaseGameLayer_data).m_labelObjects.size + 0x1c9) ^ 1;
  memset(&local_310,0,0x308);
  local_2c0[0] = 0x3f800000;
                    
  local_2d8 = FUN_00e146dc(local_2c0,10);
  if (local_2d8 == 1) {
    puVar37 = &local_2b0;
    local_2b0 = 0;
  }
  else {
    if (0x1fffffffffffffff < local_2d8) {
                    
      uVar40 = FUN_00e1383c();
                    /* catch() { ... } // from try @ 006e3770 with catch @ 006e41f4
                       catch() { ... } // from try @ 006e41f0 with catch @ 006e41f4 */
      goto LAB_006e4064;
    }
    pvVar47 = (void *)(local_2d8 << 3);
    puVar37 = operator.new(pvVar47);
    memset(puVar37,0,(size_t)pvVar47);
  }
  local_298 = 0;
  local_290 = 0;
  local_280 = 0;
  local_288[0] = 0x3f800000;
  local_2e0 = puVar37;
                    
  local_2a0 = FUN_00e146dc(local_288,10);
  if (local_2a0 == 1) {
    puVar37 = &local_278;
    local_278 = 0;
LAB_006e3800:
    local_260 = 0;
    local_258 = 0;
    local_248 = 0;
    local_250[0] = 0x3f800000;
    local_2a8 = puVar37;
                    
    local_268 = FUN_00e146dc(local_250,10);
    if (local_268 == 1) {
      local_270 = &local_240;
      local_240 = 0;
    }
    else {
      local_270 = (undefined8 *)FUN_006c99c0();
    }
    local_220 = local_230;
    local_230[0] = 0;
    local_228 = (void *)0x0;
    local_210 = 0;
    local_1f8 = 0;
    local_1f0 = 0;
    local_1e0 = 0;
    local_1e8[0] = 0x3f800000;
    local_218 = local_220;
                    
    local_200 = FUN_00e146dc(local_1e8,10);
    if (local_200 == 1) {
      local_1d8 = 0;
      puVar37 = &local_1d8;
LAB_006e38a8:
      local_1d0 = (void *)0x0;
      local_1c8 = (void *)0x0;
      local_1c0 = 0;
      local_1b8 = (void *)0x0;
      local_1b0 = (void *)0x0;
      local_1a8 = 0;
      local_1a0 = (void *)0x0;
      local_198 = (void *)0x0;
      local_190 = 0;
      local_188 = (void *)0x0;
      local_180 = (void *)0x0;
      local_178 = 0;
      local_160 = 0;
      local_158 = 0;
      local_148 = 0;
      local_150[0] = 0x3f800000;
      local_208 = puVar37;
                    
      local_168 = FUN_00e146dc(local_150,10);
      if (local_168 == 1) {
        local_140 = 0;
        local_170 = &local_140;
      }
      else {
        local_170 = (undefined8 *)FUN_006c9928();
      }
      local_128 = 0;
      local_120 = 0;
      local_110 = 0;
      local_118[0] = 0x3f800000;
                    
      local_130 = FUN_00e146dc(local_118,10);
      if (local_130 == 1) {
        local_108 = 0;
        local_138 = &local_108;
      }
      else {
        local_138 = (undefined8 *)FUN_006c9a58();
      }
      local_100 = (GroupCommandObject2 *)0x0;
      local_f8 = (GroupCommandObject2 *)0x0;
      local_f0 = 0;
      local_d8 = 0;
      local_d0 = 0;
      local_c8[0] = 0x3f800000;
      local_c0 = 0;
                    
      local_e0 = FUN_00e146dc(local_c8,10);
      if (local_e0 == 1) {
        local_b8 = 0;
        puVar37 = &local_b8;
      }
      else {
        if (0x1fffffffffffffff < local_e0) goto LAB_006e40a4;
        pvVar47 = (void *)(local_e0 << 3);
        puVar37 = operator.new(pvVar47);
        memset(puVar37,0,(size_t)pvVar47);
      }
      local_a0 = 0;
      local_98 = 0;
      local_90[0] = 0x3f800000;
      local_88 = 0;
      local_e8 = puVar37;
                    
      local_a8 = FUN_00e146dc(local_90,10);
      if (local_a8 == 1) {
        local_80 = 0;
        local_b0 = &local_80;
      }
      else {
        local_b0 = (undefined8 *)FUN_006c99c0();
      }
      local_68 = 0;
      local_60 = 0;
      local_58[0] = 0x3f800000;
      local_50 = 0;
                    
      local_70 = FUN_00e146dc(local_58,10);
      if (local_70 == 1) {
        local_48 = 0;
        puVar37 = &local_48;
LAB_006e3a38:
        local_30 = 0;
        local_28 = 0;
        local_20[0] = 0x3f800000;
        local_18 = 0;
        local_78 = puVar37;
                    
        local_38 = FUN_00e146dc(local_20,10);
        if (local_38 == 1) {
          local_10 = 0;
          puVar37 = &local_10;
        }
        else {
          if (0x1fffffffffffffff < local_38) goto LAB_006e4130;
          pvVar47 = (void *)(local_38 << 3);
          puVar37 = operator.new(pvVar47);
          memset(puVar37,0,(size_t)pvVar47);
        }
        local_40 = puVar37;
        EffectManagerState::operator=
                  ((EffectManagerState *)this_01,(EffectManagerState *)&local_310);
        FUN_006c980c(local_30);
        memset(local_40,0,local_38 << 3);
        local_28 = 0;
        local_30 = 0;
        if ((local_40 != (undefined8 *)0x0) && (local_40 != &local_10)) {
          operator.delete(local_40);
        }
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_78);
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_b0);
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_e8);
        pGVar31 = local_f8;
        pGVar59 = local_f8;
        if (local_100 != local_f8) {
          pGVar53 = local_100 + 0x1b8;
          pGVar57 = local_100;
          do {
            if (*(void **)(pGVar53 + 0x30) != (void *)0x0) {
              operator.delete(*(void **)(pGVar53 + 0x30));
            }
            pvVar47 = *(void **)pGVar53;
            pvVar49 = *(void **)(pGVar53 + 8);
            if (pvVar47 != pvVar49) {
              do {
                if (*(void **)((long)pvVar47 + 0x128) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0x128));
                }
                if (*(void **)((long)pvVar47 + 0x110) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0x110));
                }
                if (*(void **)((long)pvVar47 + 0xf8) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0xf8));
                }
                if (*(void **)((long)pvVar47 + 0xe0) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0xe0));
                }
                if (*(void **)((long)pvVar47 + 200) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 200));
                }
                if (*(void **)((long)pvVar47 + 0x80) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0x80));
                }
                if (*(void **)((long)pvVar47 + 0x68) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0x68));
                }
                if (*(void **)((long)pvVar47 + 0x50) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0x50));
                }
                if (*(void **)((long)pvVar47 + 0x38) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0x38));
                }
                if (*(void **)((long)pvVar47 + 0x20) != (void *)0x0) {
                  operator.delete(*(void **)((long)pvVar47 + 0x20));
                }
                pvVar47 = (void *)((long)pvVar47 + 0x1c0);
              } while (pvVar49 != pvVar47);
              pvVar49 = *(void **)pGVar53;
            }
            if (pvVar49 != (void *)0x0) {
              operator.delete(pvVar49);
            }
            pGVar57 = pGVar57 + 0x208;
            pGVar53 = pGVar53 + 0x208;
            pGVar59 = local_100;
          } while (pGVar31 != pGVar57);
        }
        if (pGVar59 != (GroupCommandObject2 *)0x0) {
          operator.delete(pGVar59);
        }
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_138);
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_170);
        pvVar54 = local_180;
        pvVar49 = local_180;
        for (pvVar47 = local_188; pvVar47 != pvVar54; pvVar47 = (void *)((long)pvVar47 + 0x48)) {
          if (*(void **)((long)pvVar47 + 0x30) != (void *)0x0) {
            operator.delete(*(void **)((long)pvVar47 + 0x30));
          }
          pvVar49 = local_188;
        }
        pvVar47 = local_1a0;
        pvVar54 = local_198;
        pvVar29 = local_198;
        if (pvVar49 != (void *)0x0) {
          operator.delete(pvVar49);
          pvVar47 = local_1a0;
          pvVar54 = local_198;
          pvVar29 = local_198;
        }
        for (; pvVar49 = local_198, pvVar47 != local_198; pvVar47 = (void *)((long)pvVar47 + 0x30))
        {
          local_198 = pvVar29;
          if (*(void **)((long)pvVar47 + 0x18) != (void *)0x0) {
            operator.delete(*(void **)((long)pvVar47 + 0x18));
          }
          pvVar54 = local_1a0;
          pvVar29 = local_198;
          local_198 = pvVar49;
        }
        pvVar47 = local_1b8;
        pvVar49 = local_1b0;
        pvVar30 = local_1b0;
        local_198 = pvVar29;
        if (pvVar54 != (void *)0x0) {
          operator.delete(pvVar54);
          pvVar47 = local_1b8;
          pvVar49 = local_1b0;
          pvVar30 = local_1b0;
        }
        for (; pvVar54 = local_1b0, pvVar47 != local_1b0; pvVar47 = (void *)((long)pvVar47 + 0x38))
        {
          local_1b0 = pvVar30;
          if (*(void **)((long)pvVar47 + 0x20) != (void *)0x0) {
            operator.delete(*(void **)((long)pvVar47 + 0x20));
          }
          pvVar49 = local_1b8;
          pvVar30 = local_1b0;
          local_1b0 = pvVar54;
        }
        pvVar47 = local_1d0;
        pvVar54 = local_1c8;
        pvVar29 = local_1c8;
        local_1b0 = pvVar30;
        if (pvVar49 != (void *)0x0) {
          operator.delete(pvVar49);
          pvVar47 = local_1d0;
          pvVar54 = local_1c8;
          pvVar29 = local_1c8;
        }
        for (; pvVar49 = local_1c8, pvVar47 != local_1c8; pvVar47 = (void *)((long)pvVar47 + 0x38))
        {
          local_1c8 = pvVar29;
          if (*(void **)((long)pvVar47 + 0x20) != (void *)0x0) {
            operator.delete(*(void **)((long)pvVar47 + 0x20));
          }
          pvVar54 = local_1d0;
          pvVar29 = local_1c8;
          local_1c8 = pvVar49;
        }
        local_1c8 = pvVar29;
        if (pvVar54 != (void *)0x0) {
          operator.delete(pvVar54);
        }
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_208);
        pvVar47 = local_228;
        while (pvVar47 != (void *)0x0) {
          std::_Rb_tree<>::_M_erase(a_Stack_238,*(_Rb_tree_node **)((long)pvVar47 + 0x18));
          pvVar49 = *(void **)((long)pvVar47 + 0x10);
          operator.delete(pvVar47);
          pvVar47 = pvVar49;
        }
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_270);
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_2a8);
        std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_2e0);
        if (local_2f8 != (void *)0x0) {
          operator.delete(local_2f8);
        }
        if (local_310 != (CCPoint)0x0) {
          operator.delete((void *)local_310);
        }
        lVar46 = getLastCheckpoint(this);
        if (lVar46 == 0) {
LAB_006e3d80:
          GJEffectManager::saveToState
                    ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,
                     (EffectManagerState *)this_01);
          ppGVar52 = (this->GJBaseGameLayer_data).m_solidCollisionObjects.start;
          if ((ppGVar52 != (GameObject **)0x0) &&
             (pGVar35 = ppGVar52[7], pGVar35 != (GameObject *)0x0)) {
            pCVar33 = (CCObject *)0x0;
            pGVar45 = *(GameObject **)&(pGVar35->CCNode_data).m_bReorderChildDirty;
            while( true ) {
              pCVar41 = (pGVar35->CCNode_data).m_pActionManager;
              pCVar50 = *(CCObject **)(pCVar41 + 0x248);
              lVar46 = (**(code **)(*(long *)pCVar41 + 0x1f0))(pCVar41);
              if ((lVar46 != 0) && (pCVar50 != (CCObject *)0x0)) {
                if (pCVar33 == (CCObject *)0x0) {
                  pCVar33 = (CCObject *)cocos2d::CCArray::create();
                }
                cocos2d::CCArray::addObject((CCArray *)pCVar33,pCVar50);
              }
              if (pGVar45 == (GameObject *)0x0) break;
              pGVar35 = pGVar45;
              pGVar45 = *(GameObject **)&(pGVar45->CCNode_data).m_bReorderChildDirty;
            }
            if ((pCVar33 != (CCObject *)0x0) &&
               (pCVar33 != (CCObject *)this_02[3].PlayerCheckpoint_data.m_dashAngle)) {
              cocos2d::CCObject::retain(pCVar33);
              pCVar43 = (CCObject *)this_02[3].PlayerCheckpoint_data.m_dashAngle;
              if (pCVar43 != (CCObject *)0x0) {
                cocos2d::CCObject::release(pCVar43);
              }
              this_02[3].PlayerCheckpoint_data.m_dashAngle = (double)pCVar33;
            }
          }
          pGVar38 = (GameObject *)GameObject::createWithFrame("checkpoint_01_001.png");
          *(undefined4 *)(pGVar38 + 0x3f4) = 0x2c;
          (**(code **)(*(long *)pGVar38 + 0x4e0))();
          cVar32 = GJBaseGameLayer::isFlipping((GJBaseGameLayer *)this);
          if (cVar32 == '\0') {
            pCVar42 = (this->GJBaseGameLayer_data).m_unkdd0;
            pcVar51 = *(code **)(*(long *)pGVar38 + 0x548);
            pCVar39 = (CCPoint *)(**(code **)(pCVar42->CCCopying + 0xc0))(pCVar42);
            cocos2d::CCPoint::CCPoint(&local_310,pCVar39);
            (*pcVar51)(pGVar38,&local_310);
          }
          else {
            pcVar51 = *(code **)(*(long *)pGVar38 + 0x548);
            cocos2d::CCPoint::CCPoint
                      (&local_310,
                       (CCPoint *)
                       &(this->GJBaseGameLayer_data).m_unkdd0[8].CCNode_data.m_obAnchorPointInPoints
                        .y);
            (*pcVar51)(pGVar38,&local_310);
          }
          CheckpointObject::setObject((CheckpointObject *)this_02,pGVar38);
          saveDynamicSaveObjects(this,(vector *)&this_02[2].PlayerCheckpoint_data.m_wasJumpBuffered)
          ;
          saveActiveSaveObjects
                    ((vector *)this,(vector *)&this_02[2].PlayerCheckpoint_data.m_fallSpeed);
          if (local_8 == ___stack_chk_guard) {
            return;
          }
                    
          __stack_chk_fail(this_02);
        }
        pvVar47 = (void *)(*(long *)(lVar46 + 0xee8) - *(long *)(lVar46 + 0xee0));
        uVar44 = ((long)pvVar47 >> 2) * -0xf0f0f0f0f0f0f0f;
        if (uVar44 < 0x3c3c3c3c3c3c3c4) {
          pvVar49 = *(void **)&this_02[2].PlayerCheckpoint_data.m_isOnGround2;
          lVar46 = *(long *)&this_02[2].PlayerCheckpoint_data.m_platformerVelocityRelated -
                   (long)pvVar49 >> 2;
          if ((ulong)(lVar46 * -0xf0f0f0f0f0f0f0f) <= uVar44 &&
              uVar44 + lVar46 * 0xf0f0f0f0f0f0f0f != 0) {
            pvVar54 = (void *)0x0;
            __n = (long)this_02[2].PlayerCheckpoint_data.m_lastLandTime - (long)pvVar49;
            if (uVar44 != 0) {
              pvVar54 = operator.new(pvVar47);
            }
            if (((long)__n >> 2) * -0xf0f0f0f0f0f0f0f != 0) {
              memmove(pvVar54,pvVar49,__n);
            }
            pvVar49 = *(void **)&this_02[2].PlayerCheckpoint_data.m_isOnGround2;
            if (pvVar49 != (void *)0x0) {
              operator.delete(pvVar49);
            }
            *(void **)&this_02[2].PlayerCheckpoint_data.m_isOnGround2 = pvVar54;
            this_02[2].PlayerCheckpoint_data.m_lastLandTime = (double)((long)pvVar54 + __n);
            *(long *)&this_02[2].PlayerCheckpoint_data.m_platformerVelocityRelated =
                 (long)pvVar54 + (long)pvVar47;
          }
          goto LAB_006e3d80;
        }
      }
      else {
        if (local_70 < 0x2000000000000000) {
          pvVar47 = (void *)(local_70 << 3);
          puVar37 = operator.new(pvVar47);
          memset(puVar37,0,(size_t)pvVar47);
          goto LAB_006e3a38;
        }
                    
        FUN_00e1383c();
LAB_006e4130:
                    
        FUN_00e1383c();
      }
      FUN_00e13af4("vector::reserve");
    }
    else if (local_200 < 0x2000000000000000) {
      pvVar47 = (void *)(local_200 << 3);
      puVar37 = operator.new(pvVar47);
      memset(puVar37,0,(size_t)pvVar47);
      goto LAB_006e38a8;
    }
                    
    uVar40 = FUN_00e1383c();
                    
  }
  else {
    if (local_2a0 < 0x2000000000000000) {
      pvVar47 = (void *)(local_2a0 << 3);
      puVar37 = operator.new(pvVar47);
      memset(puVar37,0,(size_t)pvVar47);
      goto LAB_006e3800;
    }
                    
    FUN_00e1383c();
LAB_006e40a4:
                    
    uVar40 = FUN_00e1383c();
    std::_Destroy_aux<false>::__destroy<>(local_100,local_f8);
                    /* catch() { ... } // from try @ 006e3970 with catch @ 006e415c
                       catch() { ... } // from try @ 006e4158 with catch @ 006e415c */
    if (local_100 != (GroupCommandObject2 *)0x0) {
      operator.delete(local_100);
    }
    std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_138);
    std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_170);
    std::vector<>::~vector((vector<> *)&local_188);
    std::vector<>::~vector((vector<> *)&local_1a0);
    std::vector<>::~vector((vector<> *)&local_1b8);
    std::vector<>::~vector((vector<> *)&local_1d0);
    std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_208);
    pvVar47 = local_228;
    while (pvVar47 != (void *)0x0) {
      std::_Rb_tree<>::_M_erase(a_Stack_238,*(_Rb_tree_node **)((long)pvVar47 + 0x18));
      pvVar49 = *(void **)((long)pvVar47 + 0x10);
      operator.delete(pvVar47);
      pvVar47 = pvVar49;
    }
    std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_270);
  }
  std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_2a8);
  std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_2e0);
LAB_006e4064:
  if (local_2f8 != (void *)0x0) {
    operator.delete(local_2f8);
  }
  if (local_310 != (CCPoint)0x0) {
    operator.delete((void *)local_310);
  }
                    
  _Unwind_Resume(uVar40);
}






void PlayLayer::createObjectsFromSetupFinished(PlayLayer *this)

{
  undefined3 *puVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  CCArray *pCVar7;
  EnhancedGameObject *this_00;
  ulong uVar8;
  undefined8 *puVar9;
  CCDirector *pCVar10;
  EndPortalObject *this_01;
  long *plVar11;
  CCPoint *pCVar12;
  uint *puVar13;
  int *piVar14;
  long lVar15;
  long lVar16;
  CCNode *pCVar17;
  long lVar18;
  ulong uVar19;
  undefined8 *puVar20;
  uint uVar21;
  code *pcVar22;
  long *plVar23;
  long *plVar24;
  float extraout_s0;
  float extraout_s0_00;
  float fVar25;
  CCPoint local_10;
  long local_8;
  
  pCVar7 = *(CCArray **)&(this->PlayLayer_data).field_0xf8;
  local_8 = ___stack_chk_guard;
  if ((pCVar7 != (CCArray *)0x0) && (iVar5 = cocos2d::CCArray::count(pCVar7), iVar5 != 0)) {
    puVar13 = *(uint **)(*(long *)&(this->PlayLayer_data).field_0xf8 + 0x38);
    qsort(*(void **)(puVar13 + 4),(ulong)*puVar13,8,xCompRealPos);
    uVar21 = 0;
    while ((uVar6 = cocos2d::CCArray::count(*(CCArray **)&(this->PlayLayer_data).field_0xf8),
           uVar21 < uVar6 && ((int)uVar21 < 3))) {
      this_00 = (EnhancedGameObject *)
                cocos2d::CCArray::objectAtIndex
                          (*(CCArray **)&(this->PlayLayer_data).field_0xf8,uVar21);
      *(uint *)(this_00 + 0x6f0) = uVar21 + 1;
      EnhancedGameObject::updateUserCoin(this_00);
      uVar21 = uVar21 + 1;
    }
  }
  if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) == '\0') {
    pCVar10 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
    this_01 = (EndPortalObject *)cocos2d::CCDirector::getScreenRight(pCVar10);
    fVar25 = *(float *)((long)&(this->PlayLayer_data).m_unk38c0 + 3) + 340.0;
    if (fVar25 <= extraout_s0 + 300.0) {
      pCVar10 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
      this_01 = (EndPortalObject *)cocos2d::CCDirector::getScreenRight(pCVar10);
      fVar25 = extraout_s0_00 + 300.0;
    }
    *(float *)&(this->GJBaseGameLayer_data).m_started = fVar25;
    *(float *)((long)&(this->PlayLayer_data).m_blendingColors.size + 7) = fVar25;
    plVar11 = (long *)EndPortalObject::create(this_01);
    *(long **)&(this->GJBaseGameLayer_data).m_cameraHeight = plVar11;
    pcVar22 = *(code **)(*plVar11 + 0x548);
    cocos2d::CCPoint::CCPoint(&local_10,*(float *)&(this->GJBaseGameLayer_data).m_started,225.0);
    (*pcVar22)(plVar11,&local_10);
    lVar15 = *(long *)&(this->GJBaseGameLayer_data).m_cameraHeight;
    pcVar22 = *(code **)(this->CCCopying + 0x510);
    *(undefined4 *)(lVar15 + 0x408) = 0xb;
    (*pcVar22)(this,lVar15);
    cocos2d::CCArray::addObject
              ((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity,
               *(CCObject **)&(this->GJBaseGameLayer_data).m_cameraHeight);
    pCVar17 = (this->GJBaseGameLayer_data).m_unkdd0;
    local_10.x._1_1_ = *(undefined1 *)((long)&pCVar17[8].CCNode_data.m_fSkewY + 3);
    local_10.x._2_1_ = *(undefined1 *)&pCVar17[8].CCNode_data.m_obAnchorPointInPoints.x;
    puVar1 = (undefined3 *)((long)&pCVar17[8].CCNode_data.m_fSkewY + 2);
    local_10.x._0_1_ = *(undefined1 *)puVar1;
    EndPortalObject::updateColors
              (*(EndPortalObject **)&(this->GJBaseGameLayer_data).m_cameraHeight,
               CONCAT53(local_10._3_5_,*puVar1));
    plVar11 = *(long **)&(this->GJBaseGameLayer_data).m_cameraHeight;
    (**(code **)(*plVar11 + 0x148))(plVar11,0);
    plVar11 = *(long **)&(this->GJBaseGameLayer_data).m_cameraHeight;
    pCVar12 = (CCPoint *)(**(code **)(*plVar11 + 0xc0))(plVar11);
    cocos2d::CCPoint::operator=((CCPoint *)&this[1].CCNode_data.field_0x84,pCVar12);
  }
  LevelTools::sortSpeedObjects
            (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.single + 3),
             (GJBaseGameLayer *)this);
  GJBaseGameLayer::orderSpawnObjects((GJBaseGameLayer *)this);
  GJBaseGameLayer::updateMaxGameplayY((GJBaseGameLayer *)this);
  plVar24 = *(long **)&(this->PlayLayer_data).field_0xe0;
  plVar23 = *(long **)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3);
  plVar11 = plVar24;
joined_r0x006d7d90:
  if (plVar23 != plVar11) {
    do {
      puVar20 = (undefined8 *)(*plVar11 + -0x18);
      if (puVar20 != &DAT_0134b6b0) {
        piVar14 = (int *)(*plVar11 + -8);
        do {
          iVar5 = *piVar14;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar14,0x10);
          if (bVar3) {
            *piVar14 = iVar5 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (iVar5 < 1) goto code_r0x006d7ddc;
      }
      plVar11 = plVar11 + 1;
      if (plVar23 == plVar11) break;
    } while( true );
  }
  pCVar7 = *(CCArray **)&(this->PlayLayer_data).field_0xf8;
  *(long **)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3) = plVar24;
  cocos2d::CCArray::removeAllObjects(pCVar7);
  cocos2d::CCObject::release(*(CCObject **)&(this->PlayLayer_data).field_0xf8);
  *(undefined8 *)&(this->PlayLayer_data).field_0xf8 = 0;
  lVar18 = *(long *)&this[1].CCNode_data.m_obAnchorPointInPoints.y;
  lVar15 = *(long *)&this[1].CCNode_data.m_obAnchorPoint.y - lVar18;
  fVar25 = (float)((int)this[1].CCNode_data.m_sInverse.b + 1);
  this[1].CCNode_data.m_sInverse.b = fVar25;
  uVar8 = lVar15 * -0x5555555555555555;
  uVar19 = (ulong)(int)fVar25;
  if (uVar8 < uVar19) {
    std::vector<>::_M_default_append
              ((vector<> *)&this[1].CCNode_data.m_obAnchorPointInPoints.y,
               uVar19 + lVar15 * 0x5555555555555555);
    uVar19 = (ulong)(int)this[1].CCNode_data.m_sInverse.b;
LAB_006d7e3c:
    lVar15 = *(long *)&this[1].CCNode_data.m_sAdditionalTransform.b;
    uVar8 = *(long *)&this[1].CCNode_data.m_sAdditionalTransform.d - lVar15 >> 2;
    bVar4 = uVar8 == uVar19;
    bVar3 = true;
    if (uVar19 <= uVar8) goto LAB_006d7e54;
LAB_006d7ee4:
    std::vector<>::_M_default_append
              ((vector<> *)&this[1].CCNode_data.m_sAdditionalTransform.b,uVar19 - uVar8);
    lVar15 = *(long *)&this[1].CCNode_data.m_sTransform.b;
    puVar20 = *(undefined8 **)&this[1].CCNode_data.m_sTransform.d;
    uVar8 = ((ulong)(long)(int)this[1].CCNode_data.m_sInverse.b >> 5) + 1;
    uVar19 = (long)puVar20 - lVar15 >> 3;
    bVar3 = uVar19 <= uVar8;
    if (uVar19 < uVar8) goto LAB_006d7f14;
  }
  else {
    if (uVar8 <= uVar19) goto LAB_006d7e3c;
    lVar16 = *(long *)&this[1].CCNode_data.m_sAdditionalTransform.d;
    *(ulong *)&this[1].CCNode_data.m_obAnchorPoint.y = lVar18 + uVar19 * 3;
    lVar15 = *(long *)&this[1].CCNode_data.m_sAdditionalTransform.b;
    uVar8 = lVar16 - lVar15 >> 2;
    bVar3 = uVar19 <= uVar8;
    bVar4 = uVar8 == uVar19;
    if (!bVar3) goto LAB_006d7ee4;
LAB_006d7e54:
    if (bVar3 && !bVar4) {
      *(ulong *)&this[1].CCNode_data.m_sAdditionalTransform.d = lVar15 + uVar19 * 4;
    }
    lVar15 = *(long *)&this[1].CCNode_data.m_sTransform.b;
    puVar20 = *(undefined8 **)&this[1].CCNode_data.m_sTransform.d;
    uVar8 = (uVar19 >> 5) + 1;
    uVar19 = (long)puVar20 - lVar15 >> 3;
    bVar3 = uVar19 <= uVar8;
    if (uVar19 < uVar8) {
LAB_006d7f14:
      uVar8 = uVar8 - uVar19;
      if (uVar8 != 0) {
        puVar9 = puVar20;
        uVar19 = uVar8;
        if ((ulong)(*(long *)&this[1].CCNode_data.m_sTransform.ty - (long)puVar20 >> 3) < uVar8) {
          FUN_006c9630();
        }
        else {
          do {
            if (puVar9 != (undefined8 *)0x0) {
              *puVar9 = 0;
            }
            uVar19 = uVar19 - 1;
            puVar9 = puVar9 + 1;
          } while (uVar19 != 0);
          *(undefined8 **)&this[1].CCNode_data.m_sTransform.d = puVar20 + uVar8;
        }
      }
      goto LAB_006d7e8c;
    }
  }
  if (!bVar3) {
    *(ulong *)&this[1].CCNode_data.m_sTransform.d = lVar15 + uVar8 * 8;
  }
LAB_006d7e8c:
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
code_r0x006d7ddc:
  plVar11 = plVar11 + 1;
  operator.delete(puVar20);
  goto joined_r0x006d7d90;
}




void PlayLayer::currencyWillExit(CurrencyRewardLayer *param_1)

{
  if (param_1[0x3956] != (CurrencyRewardLayer)0x0) {
    (**(code **)(*(long *)param_1 + 0x618))();
  }
  return;
}




void PlayLayer::currencyWillExit(PlayLayer *this,CurrencyRewardLayer *param_1)

{
  currencyWillExit((CurrencyRewardLayer *)&this[-1].GJBaseGameLayer_data.m_gameState.m_unkPoint11);
  return;
}




void PlayLayer::delayedFullReset(PlayLayer *this)

{
  CCFiniteTimeAction *pCVar1;
  undefined8 uVar2;
  CCAction *pCVar3;
  
  if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0') {
    *(undefined1 *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity = 0;
    *(undefined1 *)((long)&(this->PlayLayer_data).m_unk383c + 3) = 1;
  }
  pCVar1 = (CCFiniteTimeAction *)
           cocos2d::CCDelayTime::create
                     ((CCDelayTime *)((this->GJBaseGameLayer_data).m_varianceValues + 0x7c5),0.5);
  uVar2 = cocos2d::CCCallFunc::create((CCCallFunc *)this,(CCObject *)fullReset,(_func_void *)0x0);
  pCVar3 = (CCAction *)cocos2d::CCSequence::create(pCVar1,uVar2,0);
  cocos2d::CCNode::runAction((CCNode *)this,pCVar3);
  return;
}




void PlayLayer::delayedResetLevel(PlayLayer *this)

{
  if (*(char *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.last + 1) != '\0') {
    (**(code **)(this->CCCopying + 0x618))();
  }
  return;
}








void PlayLayer::destroyPlayer(PlayLayer *this,PlayerObject *param_1,GameObject *param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  PlayerObject *pPVar12;
  long lVar13;
  GameManager *pGVar14;
  undefined8 uVar15;
  CCFiniteTimeAction *pCVar16;
  CCAction *pCVar17;
  FMODAudioEngine *pFVar18;
  CCDelayTime *this_00;
  GameStatsManager *pGVar19;
  DialogObject *pDVar20;
  DialogLayer *pDVar21;
  GameManager *extraout_x0;
  GJGameLevel *pGVar22;
  long *plVar23;
  int *piVar24;
  bool bVar25;
  float fVar26;
  float fVar27;
  double dVar28;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [8];
  long local_18;
  long local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (param_1 == (PlayerObject *)0x0) {
    pPVar12 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0;
    param_1 = (PlayerObject *)pPVar12;
  }
  else {
    pPVar12 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0;
  }
  if ((*(char *)((long)&(pPVar12->PlayerObject_data).m_lastGroundedPos.x + 3) != '\0') ||
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 2) != '\0'))
  goto LAB_006d1d38;
  if ((param_2 != (GameObject *)0x0) &&
     ((lVar13 = *(long *)((long)&(this->PlayLayer_data).m_statusLabel + 3), lVar13 != 0 &&
      (*(int *)(param_2 + 900) == *(int *)(lVar13 + 900))))) {
    *(undefined1 *)((long)&(this->PlayLayer_data).m_speedObjects + 3) = 1;
    goto LAB_006d1d38;
  }
  cocos2d::CCNode::stopActionByTag((CCNode *)this,0x14);
  (**(code **)(this->CCCopying + 0x588))(0x3f800000,this);
  commitJumps(this);
  GJEffectManager::playerDied((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4)
  ;
  cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_endPortal;
  (this->GJBaseGameLayer_data).m_gameState.m_pauseCounter = 0;
  if (cVar6 == '\0') {
    pGVar14 = (GameManager *)GameManager::sharedState((GameManager *)0x0);
    cVar6 = GameManager::getGameVariable(pGVar14,"0014");
    if (cVar6 == '\0') {
      GJBaseGameLayer::shakeCamera((GJBaseGameLayer *)this,0.15,1.0,0.0);
    }
  }
  cVar6 = *(char *)((long)&(this->PlayLayer_data).m_attemptTime + 4);
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_activeObjects.start = 1;
  if (cVar6 == '\0') {
    pGVar22 = (this->GJBaseGameLayer_data).m_level;
    iVar9 = (pGVar22->GJGameLevel_data).m_levelID.random -
            (pGVar22->GJGameLevel_data).m_levelID.seed;
    if ((((iVar9 == 1) || (iVar9 == 0x3e9)) &&
        (*(char *)&(this->GJBaseGameLayer_data).m_unkdd0[8].CCNode_data.m_fSkewY == '\0')) &&
       (1 < *(int *)&(this->GJBaseGameLayer_data).field_0x2f54)) {
      showHint(this);
      if (*(char *)((long)&(this->PlayLayer_data).m_attemptTime + 4) != '\0') goto LAB_006d1bd4;
      pGVar22 = (this->GJBaseGameLayer_data).m_level;
      iVar9 = (pGVar22->GJGameLevel_data).m_levelID.random -
              (pGVar22->GJGameLevel_data).m_levelID.seed;
    }
    if (((iVar9 == 3) || (iVar9 == 0x3eb)) &&
       ((*(char *)((long)&(this->GJBaseGameLayer_data).m_unkdd0[8].CCNode_data.m_fSkewY + 1) == '\0'
        && (1 < *(int *)&(this->GJBaseGameLayer_data).field_0x2f54)))) {
      showHint(this);
    }
  }
LAB_006d1bd4:
  bVar2 = (this->PlayLayer_data).m_unk376d;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 2) = 1;
  if ((bVar2 != false) &&
     (plVar23 = *(long **)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.last + 3),
     cVar6 = (**(code **)(*plVar23 + 0x150))(plVar23), cVar6 == '\0')) {
    toggleDebugDraw(this);
  }
  PlayerObject::playerDestroyed((PlayerObject *)param_1,false);
  if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode != false) {
    pPVar12 = (PlayerObject *)GJBaseGameLayer::getOtherPlayer((GJBaseGameLayer *)this,param_1);
    GJBaseGameLayer::playExitDualEffect((GJBaseGameLayer *)this,(PlayerObject *)pPVar12);
    PlayerObject::playerDestroyed(pPVar12,true);
  }
  iVar9 = getCurrentPercentInt(this);
  if ((*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth == '\0') &&
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) == '\0')) {
    cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_endPortal;
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    if (99 < iVar9) {
      iVar9 = 99;
    }
    if (cVar6 == '\0') {
      bVar5 = true;
      iVar11 = GJGameLevel::getNormalPercent((this->GJBaseGameLayer_data).m_level);
      cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_endPortal;
      if (iVar9 <= iVar11) goto LAB_006d1e88;
    }
    else {
LAB_006d1e88:
      bVar5 = false;
    }
    bVar25 = false;
    if ((((cVar6 == '\0') &&
         (pGVar22 = (this->GJBaseGameLayer_data).m_level,
         iVar9 <= (pGVar22->GJGameLevel_data).m_orbCompletion.random -
                  (pGVar22->GJGameLevel_data).m_orbCompletion.seed)) &&
        (*(char *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.start + 7) != '\0')) &&
       ((!bVar5 &&
        (bVar25 = bVar5,
        (pGVar22->GJGameLevel_data).m_newNormalPercent2.random -
        (pGVar22->GJGameLevel_data).m_newNormalPercent2.seed < iVar9)))) {
      bVar25 = true;
      bVar5 = bVar25;
    }
    dVar28 = (double)getTempMilliTime();
    GJGameLevel::savePercentage
              ((this->GJBaseGameLayer_data).m_level,iVar9,
               *(bool *)&(this->GJBaseGameLayer_data).m_endPortal,
               (this->GJBaseGameLayer_data).m_particleSystemLimit,
               (int)((dVar28 - *(double *)&this[1].CCObject_data.m_uIndexInArray) -
                    *(double *)&this[1].CCObject_data.m_unknown2),
               *(bool *)((long)&(this->PlayLayer_data).m_speedObjects + 3));
    if ((((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_levelType == Main) {
      pGVar14 = (GameManager *)GameManager::sharedState((GameManager *)0x1);
      pGVar22 = (this->GJBaseGameLayer_data).m_level;
      GameManager::reportPercentageForLevel
                (pGVar14,(pGVar22->GJGameLevel_data).m_levelID.random -
                         (pGVar22->GJGameLevel_data).m_levelID.seed,iVar9,
                 *(bool *)&(this->GJBaseGameLayer_data).m_endPortal);
    }
    if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
      pGVar22 = (this->GJBaseGameLayer_data).m_level;
      if ((0 < (pGVar22->GJGameLevel_data).m_stars.random - (pGVar22->GJGameLevel_data).m_stars.seed
          ) && (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) == '\0')) {
        pGVar19 = (GameStatsManager *)GameStatsManager::sharedState((GameStatsManager *)0x0);
        iVar9 = GameStatsManager::awardCurrencyForLevel
                          (pGVar19,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
        pGVar22 = (this->GJBaseGameLayer_data).m_level;
        uVar4 = (pGVar22->GJGameLevel_data).m_dailyID.random -
                (pGVar22->GJGameLevel_data).m_dailyID.seed;
        pGVar19 = (GameStatsManager *)(ulong)uVar4;
        if (((int)uVar4 < 1) &&
           (bVar2 = (pGVar22->GJGameLevel_data).m_gauntletLevel,
           pGVar19 = (GameStatsManager *)(ulong)bVar2, bVar2 == false)) {
          iVar11 = 0;
          bVar2 = 0 < iVar9;
        }
        else {
          pGVar19 = (GameStatsManager *)GameStatsManager::sharedState(pGVar19);
          iVar11 = GameStatsManager::awardDiamondsForLevel
                             (pGVar19,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
          bVar2 = 0 < iVar9 + iVar11;
        }
        goto LAB_006d1c24;
      }
      bVar2 = false;
      iVar11 = 0;
      iVar9 = 0;
      goto LAB_006d1d84;
    }
    bVar2 = false;
    iVar11 = 0;
    iVar9 = 0;
    if ((this->GJBaseGameLayer_data).m_gameState.m_unkBool22 != false) goto LAB_006d1c34;
LAB_006d1da0:
    bVar7 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1);
    pFVar18 = (FMODAudioEngine *)(ulong)bVar7;
    if (bVar7 != 0) {
LAB_006d1da8:
      pFVar18 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar18);
      pFVar18 = (FMODAudioEngine *)FMODAudioEngine::pauseAllMusic(pFVar18,false);
    }
    pFVar18 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar18);
    FMODAudioEngine::stopAllEffects(pFVar18);
  }
  else {
    bVar2 = false;
    iVar11 = 0;
    iVar9 = 0;
    bVar25 = false;
    bVar5 = false;
LAB_006d1c24:
    if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
LAB_006d1d84:
      uVar10 = getCurrentPercentInt(this);
      *(undefined4 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.last + 3) = uVar10;
      if ((this->GJBaseGameLayer_data).m_gameState.m_unkBool22 == false) {
        bVar7 = *(byte *)&(this->GJBaseGameLayer_data).m_endPortal;
        pFVar18 = (FMODAudioEngine *)(ulong)bVar7;
        if (bVar7 != 0) goto LAB_006d1da0;
        goto LAB_006d1da8;
      }
    }
    else if ((this->GJBaseGameLayer_data).m_gameState.m_unkBool22 == false) goto LAB_006d1da0;
  }
LAB_006d1c34:
  bVar3 = (this->GJBaseGameLayer_data).m_gameState.m_unkBool26;
  pGVar14 = (GameManager *)(ulong)bVar3;
  if (bVar3 == false) {
    uVar15 = FMODAudioEngine::sharedEngine((FMODAudioEngine *)0x0);
    FUN_00e153b8(&local_10,"explode_11.ogg",auStack_20);
                    
    FMODAudioEngine::playEffect(0x3f800000,0,0x3f266666,uVar15,&local_10);
    pGVar14 = (GameManager *)(local_10 + -0x18);
    if (pGVar14 != (GameManager *)&DAT_0134b6b0) {
      piVar24 = (int *)(local_10 + -8);
      do {
        iVar1 = *piVar24;
        cVar6 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar24,0x10);
        if (bVar3) {
          *piVar24 = iVar1 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      if (iVar1 < 1) {
        operator.delete(pGVar14);
        pGVar14 = extraout_x0;
      }
    }
  }
  pGVar14 = (GameManager *)GameManager::sharedState(pGVar14);
  cVar6 = GameManager::getGameVariable(pGVar14,"0026");
  if ((cVar6 == '\0') && (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0')) {
    pGVar14 = (GameManager *)0x0;
    if (bVar2) {
      pGVar14 = (GameManager *)showNewBest(this,(bool)(bVar5 ^ 1),iVar9,iVar11,false,false,false);
    }
    lVar13 = GameManager::sharedState(pGVar14);
    UILayer::disableMenu(*(UILayer **)(*(long *)(lVar13 + 0x1d8) + 0x3540));
    fVar26 = (this->GJBaseGameLayer_data).m_gameState.m_unkUint14;
    _shouldRefreshBanner = 0;
    if (fVar26 <= 0.5) {
      fVar26 = 0.5;
    }
    pCVar16 = (CCFiniteTimeAction *)
              cocos2d::CCDelayTime::create((CCDelayTime *)&_shouldRefreshBanner,fVar26);
    uVar15 = cocos2d::CCCallFunc::create
                       ((CCCallFunc *)this,(CCObject *)showRetryLayer,(_func_void *)0x0);
    pCVar17 = (CCAction *)cocos2d::CCSequence::create(pCVar16,uVar15,0);
    cocos2d::CCNode::runAction((CCNode *)this,pCVar17);
    goto LAB_006d1d38;
  }
  *(undefined1 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.last + 1) = 1;
  pGVar14 = (GameManager *)GameManager::sharedState((GameManager *)0x1);
  bVar7 = GameManager::getGameVariable(pGVar14,"0052");
  if (bVar7 == 0) {
    fVar26 = 1.0;
  }
  else {
    fVar26 = 0.5;
  }
  fVar27 = (this->GJBaseGameLayer_data).m_gameState.m_unkUint14;
  if (fVar26 < fVar27) {
    fVar26 = fVar27;
  }
  if ((bVar2) || (bVar5)) {
    pGVar14 = (GameManager *)GameManager::sharedState((GameManager *)(ulong)bVar7);
    bVar3 = false;
    bVar7 = GameManager::getUGV(pGVar14,"17");
    pGVar19 = (GameStatsManager *)(ulong)bVar7;
    if (bVar7 == 0) {
      pGVar19 = (GameStatsManager *)GameStatsManager::sharedState((GameStatsManager *)0x0);
      pGVar19 = (GameStatsManager *)GameStatsManager::getStat(pGVar19,"14");
      bVar3 = 500 < (int)pGVar19;
    }
    pGVar19 = (GameStatsManager *)GameStatsManager::sharedState(pGVar19);
    bVar8 = (bool)GameStatsManager::awardSecretKey(pGVar19);
    pGVar14 = (GameManager *)showNewBest(this,(bool)(bVar5 ^ 1),iVar9,iVar11,bVar8,bVar3,bVar25);
    if (fVar26 < 1.4) {
      fVar26 = 1.4;
    }
    if (bVar2) {
      if (!bVar3) {
        cocos2d::CCNode::stopActionByTag((CCNode *)this,0x10);
        goto LAB_006d1d38;
      }
    }
    else if (!bVar3) goto LAB_006d1df8;
    pGVar14 = (GameManager *)GameManager::sharedState(pGVar14);
    GameManager::setUGV(pGVar14,"17",true);
    FUN_00e153b8(&local_18,"The Shopkeeper",auStack_30);
                    
    FUN_00e153b8(&local_10,"I see you have a lot of <cl>orbs</c>. You should visit my <cy>shop</c>!"
                 ,auStack_28);
                    
    pDVar20 = (DialogObject *)
              DialogObject::create((DialogObject *)0x3f800000,&local_18,&local_10,5,0,0xffffff);
    pDVar21 = (DialogLayer *)DialogLayer::create(pDVar20,1);
    if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
      piVar24 = (int *)(local_10 + -8);
      do {
        iVar9 = *piVar24;
        cVar6 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(piVar24,0x10);
        if (bVar2) {
          *piVar24 = iVar9 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      if (iVar9 < 1) {
        operator.delete((undefined8 *)(local_10 + -0x18));
      }
    }
    if ((undefined8 *)(local_18 + -0x18) != &DAT_0134b6b0) {
      piVar24 = (int *)(local_18 + -8);
      do {
        iVar9 = *piVar24;
        cVar6 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(piVar24,0x10);
        if (bVar2) {
          *piVar24 = iVar9 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      if (iVar9 < 1) {
        operator.delete((undefined8 *)(local_18 + -0x18));
      }
    }
    (**(code **)(this->CCCopying + 0x1c0))(this,pDVar21,100);
    (**(code **)(*(long *)pDVar21 + 0x480))(pDVar21,0);
    *(undefined1 **)(pDVar21 + 0x270) =
         (undefined1 *)((long)&(this->PlayLayer_data).m_currentCheckpoint + 3);
    DialogLayer::updateChatPlacement(pDVar21,1);
    DialogLayer::animateIn(pDVar21,4);
    cocos2d::CCNode::stopActionByTag((CCNode *)this,0x10);
  }
  else {
LAB_006d1df8:
    this_00 = (CCDelayTime *)cocos2d::CCNode::stopActionByTag((CCNode *)this,0x10);
    pCVar16 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create(this_00,fVar26);
    uVar15 = cocos2d::CCCallFunc::create
                       ((CCCallFunc *)this,(CCObject *)delayedResetLevel,(_func_void *)0x0);
    pCVar17 = (CCAction *)cocos2d::CCSequence::create(pCVar16,uVar15,0);
    (**(code **)(*(long *)pCVar17 + 0x48))(pCVar17,0x10);
    cocos2d::CCNode::runAction((CCNode *)this,pCVar17);
  }
LAB_006d1d38:
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}




void PlayLayer::dialogClosed(DialogLayer *param_1)

{
  if (param_1[0x3956] != (DialogLayer)0x0) {
    (**(code **)(*(long *)param_1 + 0x618))();
  }
  return;
}




void PlayLayer::dialogClosed(PlayLayer *this,DialogLayer *param_1)

{
  dialogClosed((DialogLayer *)&this[-1].GJBaseGameLayer_data.m_gameState.m_unkPoint10);
  return;
}




void PlayLayer::flipArt(PlayLayer *this,bool param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(**(long **)&(this->PlayLayer_data).field_0x1f0 + 0x80);
  if (!param_1) {
    (*pcVar1)(0x3f800000);
    return;
  }
  (*pcVar1)(0xbf800000);
  return;
}





void PlayLayer::fullReset(PlayLayer *this)

{
  char cVar1;
  GameObject **ppGVar2;
  CCNode *pCVar3;
  code *pcVar4;
  long *plVar5;
  float local_18;
  float local_14;
  CCPoint CStack_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  pCVar3 = (this->GJBaseGameLayer_data).m_unkdd0;
  ppGVar2 = (this->GJBaseGameLayer_data).m_unkdd8.start;
  cVar1 = *(char *)&(this->GJBaseGameLayer_data).m_endPortal;
  (this->GJBaseGameLayer_data).m_gameState.m_totalTime = 0.0;
  (this->GJBaseGameLayer_data).m_gameState.m_unkDouble3 = 0.0;
  (this->GJBaseGameLayer_data).m_gameState.m_levelTime = 0.0;
  *(undefined8 *)&pCVar3[8].CCNode_data.m_obContentSize.height = 0;
  ppGVar2[0x14e] = (GameObject *)(this->GJBaseGameLayer_data).m_gameState.m_totalTime;
  *(undefined4 *)&(this->GJBaseGameLayer_data).field_0x2f54 = 0;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_keyOpacities.capacity + 3) = 0;
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_hazardCollisionObjectsCount = 1;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 1) = 1;
  if (cVar1 == '\0') {
    resetLevelFromStart(this);
  }
  else {
    togglePracticeMode(this,false);
  }
  plVar5 = *(long **)&(this->PlayLayer_data).field_0x1f0;
  pcVar4 = *(code **)(*plVar5 + 0xb8);
  cocos2d::CCPoint::CCPoint
            (&CStack_10,(this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.x + local_18 * 0.5
             ,(this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.y + local_14 * 0.5 + 85.0);
  (*pcVar4)(plVar5,&CStack_10);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




float PlayLayer::getCurrentPercent(PlayLayer *this)

{
  int iVar1;
  float *pfVar2;
  CCNode *pCVar3;
  float fVar4;
  float fVar5;
  
  pCVar3 = (this->GJBaseGameLayer_data).m_unkdd0;
  pfVar2 = (float *)(**(code **)(pCVar3->CCCopying + 0xc0))(pCVar3);
  fVar4 = *pfVar2;
  fVar5 = *(float *)&(this->GJBaseGameLayer_data).m_started;
  iVar1 = (((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_timestamp;
  if (0 < iVar1) {
    fVar5 = (float)(iVar1 << 1);
    fVar4 = (float)(this->GJBaseGameLayer_data).m_gameState.m_currentProgress;
  }
  fVar4 = (fVar4 / fVar5) * 100.0;
  if (fVar4 <= 0.0) {
    if (fVar4 <= 0.0) {
      return 0.0;
    }
  }
  else if (100.0 <= fVar4) {
    fVar4 = 100.0;
  }
  return fVar4;
}




int PlayLayer::getCurrentPercentInt(PlayLayer *this)

{
  float fVar1;
  
  fVar1 = (float)getCurrentPercent(this);
  return (int)fVar1;
}




CCPoint * PlayLayer::getEndPosition(void)

{
  long in_x0;
  CCPoint *pCVar1;
  long *plVar2;
  CCPoint *in_x8;
  
  if (((*(char *)(in_x0 + 0x310e) == '\0') &&
      (plVar2 = *(long **)(in_x0 + 0x3288), plVar2 != (long *)0x0)) &&
     (*(long *)(in_x0 + 0x3a58) == 0)) {
    pCVar1 = (CCPoint *)(**(code **)(*plVar2 + 0xc0))(plVar2);
    cocos2d::CCPoint::CCPoint(in_x8,pCVar1);
  }
  else {
    cocos2d::CCPoint::CCPoint(in_x8,(CCPoint *)(in_x0 + 0x3a4c));
  }
  return in_x8;
}




undefined8 PlayLayer::getLastCheckpoint(PlayLayer *this)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = cocos2d::CCArray::count
                    (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
  if (iVar1 != 0) {
    uVar2 = cocos2d::CCArray::lastObject
                      (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
    return uVar2;
  }
  return 0;
}




float
PlayLayer::getRelativeMod(float param_1,float param_2,float param_3,PlayLayer *this,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.x;
  fVar1 = *(float *)&(this->GJBaseGameLayer_data).m_lightBGColor;
  fVar3 = *param_5;
  fVar2 = fVar1 + fVar4;
  if (fVar3 <= fVar2) {
    param_1 = (fVar1 - ((fVar2 - fVar3) - param_3)) * param_2;
  }
  else {
    param_1 = (fVar1 - (((fVar3 - param_3) - fVar4) - fVar1)) * param_1;
  }
  if (0.0 <= param_1) {
    if (param_1 <= 1.0) {
      return param_1;
    }
    return 1.0;
  }
  return 0.0;
}




void
PlayLayer::getRelativeModNew
          (float param_1,float param_2,PlayLayer *this,float *param_4,undefined8 param_5,
          char param_6)

{
  if (param_6 == '\0') {
    cocos2d::clampf(((*param_4 - (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.x) -
                    param_2) / param_1,0.0,1.0);
    return;
  }
  cocos2d::clampf(((((this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.x +
                    *(float *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.capacity + 4)) -
                   *param_4) + param_2) / param_1,0.0,1.0);
  return;
}





void PlayLayer::getTempMilliTime(void)

{
  long local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  time(&local_10);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail((double)local_10);
}




void PlayLayer::gravityEffectFinished(PlayLayer *this)

{
  int iVar1;
  
  iVar1 = *(int *)((long)&(this->PlayLayer_data).m_pauseDelta + 7) + -1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)((long)&(this->PlayLayer_data).m_pauseDelta + 7) = iVar1;
  return;
}




void PlayLayer::incrementJumps(PlayLayer *this)

{
  int iVar1;
  int iVar2;
  GJGameLevel *pGVar3;
  
  iVar1 = *(int *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.start + 3);
  iVar2 = *(int *)((long)&(this->PlayLayer_data).m_keyOpacities.capacity + 3);
  pGVar3 = (this->GJBaseGameLayer_data).m_level;
  *(undefined1 *)((long)&(this->PlayLayer_data).m_keyOpacities.capacity + 7) = 1;
  *(int *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.start + 3) = iVar1 + 1;
  *(int *)((long)&(this->PlayLayer_data).m_keyOpacities.capacity + 3) = iVar2 + 1;
  iVar1 = ((pGVar3->GJGameLevel_data).m_jumps.random - (pGVar3->GJGameLevel_data).m_jumps.seed) + 1;
  (pGVar3->GJGameLevel_data).m_jumps.value = iVar1;
  iVar2 = rand();
  iVar2 = (int)((float)iVar2 * 4.656613e-10 * 1000.0);
  (pGVar3->GJGameLevel_data).m_jumps.seed = iVar2;
  (pGVar3->GJGameLevel_data).m_jumps.random = iVar1 + iVar2;
  return;
}









void PlayLayer::init(PlayLayer *this,GJGameLevel *param_1,bool param_2,bool param_3)

{
  uint uVar1;
  GJLevelType GVar2;
  GJGameLevel GVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  long *plVar9;
  GameManager *pGVar10;
  long lVar11;
  long lVar12;
  CCObject *pCVar13;
  CCObject *pCVar14;
  OBB2D *pOVar15;
  CCDirector *pCVar16;
  CCDrawNode *this_00;
  GJGameLevel *pGVar17;
  CCCopying *pCVar18;
  GJMGLayer *pGVar19;
  CCDictionary *pCVar20;
  int *piVar21;
  CCArray *this_01;
  code *pcVar22;
  float fVar23;
  float fVar24;
  undefined1 auStack_48 [16];
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  long local_28;
  long local_20;
  timespec local_18;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  bVar5 = GJBaseGameLayer::init((GJBaseGameLayer *)this);
  if (bVar5 == 0) goto LAB_006e601c;
  (this->GJBaseGameLayer_data).m_level = (GJGameLevel *)param_1;
  cocos2d::CCObject::retain((CCObject *)param_1);
  plVar9 = (long *)cocos2d::CCDirector::sharedDirector();
  pGVar10 = (GameManager *)(**(code **)(*plVar9 + 0xc0))();
  pGVar10[0x5c] = (GameManager)0x1;
  pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
  cVar6 = GameManager::getGameVariable(pGVar10,"0128");
  if (cVar6 == '\0') {
    pGVar10 = (GameManager *)GameManager::sharedState((GameManager *)0x0);
    cVar6 = GameManager::getGameVariable(pGVar10,"0024");
    if (cVar6 == '\0') {
      PlatformToolbox::hideCursor();
    }
  }
  else {
    PlatformToolbox::toggleLockCursor(true);
  }
  pGVar10 = (GameManager *)(**(code **)(this->CCCopying + 0x608))(this);
  lVar11 = GameManager::sharedState(pGVar10);
  pGVar17 = (this->GJBaseGameLayer_data).m_level;
  *(undefined1 *)(lVar11 + 0x3ac) = 1;
  iVar8 = *(int *)&pGVar17->field_0x3fc;
  if (iVar8 != 0) {
    if (iVar8 == 1) {
      *(undefined1 *)&(this->PlayLayer_data).m_unk3784 = 1;
    }
    else if (iVar8 == 2) {
      *(undefined1 *)&(this->PlayLayer_data).m_unk3784 = 0;
    }
  }
  *(undefined1 *)((long)&(this->PlayLayer_data).m_speedObjects + 3) = 0;
  this[1].CCNode_data.m_sInverse.b = 1.4013e-45;
  pGVar10 = (GameManager *)(ulong)(uint)bVar5;
  (this->PlayLayer_data).m_skipAudioStep = false;
  if ((pGVar17->GJGameLevel_data).m_disableShakeToggled == false) {
    pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
    bVar4 = GameManager::getGameVariable(pGVar10,"0172");
    pGVar10 = (GameManager *)(ulong)bVar4;
  }
  *(char *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 1) = (char)pGVar10;
  pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
  pGVar10 = (GameManager *)GameManager::getGameVariable(pGVar10,"0095");
  *(char *)((long)&(this->PlayLayer_data).m_infoLabel + 3) = (char)pGVar10;
  pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
  pGVar10 = (GameManager *)GameManager::getGameVariable(pGVar10,"0099");
  *(char *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.start + 7) = (char)pGVar10;
  pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
  pGVar10 = (GameManager *)GameManager::getGameVariable(pGVar10,"0126");
  GVar3 = param_1[0x1fd];
  *(char *)((long)&(this->PlayLayer_data).m_attemptTime + 3) = (char)pGVar10;
  (this->GJBaseGameLayer_data).m_lowDetailMode = (bool)GVar3;
  lVar11 = GameManager::sharedState(pGVar10);
  bVar7 = (this->GJBaseGameLayer_data).m_lowDetailMode;
  pGVar10 = (GameManager *)(ulong)bVar7;
  if ((bVar7 == false) ||
     (bVar7 = (this->GJBaseGameLayer_data).m_extraLDM, pGVar10 = (GameManager *)(ulong)bVar7,
     bVar7 == false)) {
    lVar12 = GameManager::sharedState(pGVar10);
    pGVar10 = (GameManager *)(ulong)*(byte *)(lVar12 + 0x335);
  }
  *(char *)(lVar11 + 0x336) = (char)pGVar10;
  pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
  pGVar10[0x38d] = (GameManager)0x1;
  lVar11 = GameManager::sharedState(pGVar10);
  if (*(byte *)(lVar11 + 0x211) == 0) {
    pGVar10 = (GameManager *)0x0;
  }
  else {
    lVar11 = GameManager::sharedState((GameManager *)(ulong)*(byte *)(lVar11 + 0x211));
    clock_gettime(0,&local_18);
    *(double *)(lVar11 + 0x198) =
         (((double)local_18.tv_sec + (double)local_18.tv_nsec / 1000000000.0) - 180.0) + 180.0;
    pGVar10 = (GameManager *)GameManager::sharedState((GameManager *)local_18.tv_sec);
    pGVar10[0x211] = (GameManager)0x0;
  }
  lVar11 = GameManager::sharedState(pGVar10);
  if (*(char *)(lVar11 + 0x333) == '\0') {
    iVar8 = *(int *)(param_1 + 0x364);
    *(undefined1 *)&(this->GJBaseGameLayer_data).m_halfCameraWidth = 0;
    if (iVar8 == 1) goto LAB_006e65ac;
LAB_006e61a4:
    bVar4 = bVar5;
    if (iVar8 != 2) {
      bVar4 = *(int *)(param_1 + 0x2a0) - *(int *)(param_1 + 0x2a4) == 1;
    }
  }
  else {
    stopRecording(this);
    iVar8 = *(int *)(param_1 + 0x364);
    *(undefined1 *)&(this->GJBaseGameLayer_data).m_halfCameraWidth = 0;
    if (iVar8 != 1) goto LAB_006e61a4;
LAB_006e65ac:
    bVar4 = 0;
  }
  *(byte *)&(this->GJBaseGameLayer_data).m_currentStep = bVar4;
  *(undefined4 *)&(this->GJBaseGameLayer_data).field_0x2f54 = 0;
  GJBaseGameLayer::resetActiveEnterEffects((GJBaseGameLayer *)this);
  *(undefined4 *)((long)&(this->PlayLayer_data).m_keyOpacities.capacity + 3) = 0;
  (this->GJBaseGameLayer_data).m_gameState.m_totalTime = 0.0;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_unk38c0 + 3) = 0;
  (this->GJBaseGameLayer_data).m_gameState.m_unkDouble3 = 0.0;
  (this->GJBaseGameLayer_data).m_gameState.m_levelTime = 0.0;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_cameraWidth + 1) = 1;
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start = 0;
  (this->GJBaseGameLayer_data).m_gameState.m_isDualMode = false;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_pauseDelta + 3) = 4;
  lVar11 = AppDelegate::get();
  if ((*(char *)(lVar11 + 0x23) != '\0') ||
     (lVar11 = AppDelegate::get(), *(char *)(lVar11 + 0x24) != '\0')) {
    *(undefined4 *)((long)&(this->PlayLayer_data).m_pauseDelta + 3) = 2;
  }
  pCVar13 = (CCObject *)cocos2d::CCArray::create();
  *(CCObject **)&(this->PlayLayer_data).field_0x230 = pCVar13;
  iVar8 = 0;
  cocos2d::CCObject::retain(pCVar13);
  uVar1 = *(uint *)((long)&(this->PlayLayer_data).m_pauseDelta + 3);
  if (0 < (int)uVar1) {
    do {
      this_01 = *(CCArray **)&(this->PlayLayer_data).field_0x230;
      pCVar14 = (CCObject *)GravityEffectSprite::create((GravityEffectSprite *)(ulong)uVar1);
      iVar8 = iVar8 + 1;
      cocos2d::CCArray::addObject(this_01,pCVar14);
      uVar1 = *(uint *)((long)&(this->PlayLayer_data).m_pauseDelta + 3);
    } while (iVar8 < (int)uVar1);
  }
  pCVar13 = (CCObject *)cocos2d::CCArray::create();
  *(CCObject **)((long)&(this->PlayLayer_data).m_unk38b0 + 3) = pCVar13;
  pGVar10 = (GameManager *)cocos2d::CCObject::retain(pCVar13);
  pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
  pGVar10[0x25a] = (GameManager)0x0;
  pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
  *(PlayLayer **)(pGVar10 + 0x1d8) = this;
  lVar11 = GameManager::sharedState(pGVar10);
  *(undefined1 *)(lVar11 + 0x259) = 0;
  pCVar13 = (CCObject *)cocos2d::CCDictionary::create();
  *(CCObject **)&this[1].CCNode_data.m_fSkewY = pCVar13;
  cocos2d::CCObject::retain(pCVar13);
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  pCVar13 = (CCObject *)cocos2d::CCArray::create();
  *(CCObject **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3) = pCVar13;
  cocos2d::CCObject::retain(pCVar13);
  pCVar13 = (CCObject *)cocos2d::CCArray::create();
  *(CCObject **)((long)&(this->PlayLayer_data).m_blendingColors.single + 3) = pCVar13;
  cocos2d::CCObject::retain(pCVar13);
  pCVar13 = (CCObject *)cocos2d::CCArray::create();
  *(CCObject **)&(this->PlayLayer_data).field_0x1d0 = pCVar13;
  cocos2d::CCObject::retain(pCVar13);
  pCVar13 = (CCObject *)cocos2d::CCArray::create();
  *(CCObject **)((long)&(this->PlayLayer_data).m_lastAttemptPercent + 3) = pCVar13;
  cocos2d::CCObject::retain(pCVar13);
  GJBaseGameLayer::setupLayers((GJBaseGameLayer *)this);
  iVar8 = rand();
  *(int *)((long)&(this->PlayLayer_data).m_unk38b8 + 7) =
       (int)((float)(int)((float)iVar8 * 4.656613e-10 + (float)iVar8 * 4.656613e-10) + 1.0);
  pOVar15 = (OBB2D *)cocos2d::CCParticleSystemQuad::create("glitterEffect.plist",false);
  pCVar18 = pOVar15->CCCopying;
  (this->GJBaseGameLayer_data).m_cameraObb2 = pOVar15;
  (**(code **)(pCVar18 + 0x610))(pOVar15,1);
  pGVar19 = (this->GJBaseGameLayer_data).m_middleground;
  (**(code **)(pGVar19->CCCopying + 0x1c0))(pGVar19,(this->GJBaseGameLayer_data).m_cameraObb2,0);
  pOVar15 = (this->GJBaseGameLayer_data).m_cameraObb2;
  pcVar22 = *(code **)(pOVar15->CCCopying + 0x3b0);
  pCVar16 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
  fVar23 = (float)cocos2d::CCDirector::getScreenScaleFactorW(pCVar16);
  pCVar16 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
  fVar24 = (float)cocos2d::CCDirector::getScreenScaleFactorH(pCVar16);
  cocos2d::CCPoint::CCPoint((CCPoint *)&local_18,(fVar23 * 480.0) / 1.8,fVar24 * 320.0 * 0.5);
  (*pcVar22)(pOVar15,&local_18);
  cocos2d::CCParticleSystem::stopSystem
            ((CCParticleSystem *)(this->GJBaseGameLayer_data).m_cameraObb2);
  this_00 = (CCDrawNode *)cocos2d::CCDrawNode::create();
  *(CCDrawNode **)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.last + 3) = this_00;
  local_30 = 0x302;
  local_2c = 0x303;
  cocos2d::CCDrawNode::setBlendFunc(this_00,(_ccBlendFunc *)&local_30);
  plVar9 = *(long **)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.last + 3);
  (**(code **)(*plVar9 + 0x48))(plVar9,0xffffd8f1);
  pCVar20 = (this->GJBaseGameLayer_data).m_objectsToDeactivate;
  pcVar22 = *(code **)(*(long *)pCVar20 + 0x1c0);
  (*pcVar22)(pCVar20,*(undefined8 *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.last + 3),
             0x579);
  iVar8 = (int)pcVar22;
  updateDebugDrawSettings(this);
  GJBaseGameLayer::createPlayer((GJBaseGameLayer *)this);
  pGVar17 = (this->GJBaseGameLayer_data).m_level;
  if ((pGVar17->GJGameLevel_data).m_levelType == Editor) {
    pGVar10 = (GameManager *)GameManager::sharedState((GameManager *)0x2);
    bVar4 = GameManager::getGameVariable(pGVar10,"0174");
    pGVar10 = (GameManager *)(ulong)bVar4;
    if (bVar4 == 0) {
      plVar9 = (long *)cocos2d::CCLabelBMFont::create("Ignore Damage","bigFont.fnt");
      lVar11 = *plVar9;
      *(long **)&(this->PlayLayer_data).field_0x170 = plVar9;
      (**(code **)(lVar11 + 0x3f0))(plVar9,0x32);
      plVar9 = *(long **)&(this->PlayLayer_data).field_0x170;
      (**(code **)(*plVar9 + 0xa0))(0x3ecccccd,plVar9);
      pcVar22 = *(code **)(this->CCCopying + 0x1c0);
      (*pcVar22)(this,*(undefined8 *)&(this->PlayLayer_data).field_0x170,1000);
      iVar8 = (int)pcVar22;
      plVar9 = *(long **)&(this->PlayLayer_data).field_0x170;
      pcVar22 = *(code **)(*plVar9 + 0x118);
      cocos2d::CCPoint::CCPoint((CCPoint *)&local_18,0.0,1.0);
      (*pcVar22)(plVar9,&local_18);
      plVar9 = *(long **)&(this->PlayLayer_data).field_0x170;
      pcVar22 = *(code **)(*plVar9 + 0xb8);
      pCVar16 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
      fVar23 = (float)cocos2d::CCDirector::getScreenTop(pCVar16);
      cocos2d::CCPoint::CCPoint((CCPoint *)&local_18,5.0,(fVar23 - 5.0) + 1.0);
      (*pcVar22)(plVar9,&local_18);
      plVar9 = *(long **)&(this->PlayLayer_data).field_0x170;
      pGVar10 = (GameManager *)(**(code **)(*plVar9 + 0x148))(plVar9,0);
    }
    pGVar10 = (GameManager *)GameManager::sharedState(pGVar10);
    bVar7 = (bool)GameManager::getGameVariable(pGVar10,"0173");
    toggleIgnoreDamage(this,bVar7);
    pGVar17 = (this->GJBaseGameLayer_data).m_level;
  }
  *(undefined1 *)((long)&(this->PlayLayer_data).m_circleWaveArray + 3) = 1;
  FUN_00e18d28(&local_20,&(pGVar17->GJGameLevel_data).m_levelString);
                    
  FUN_00e153b8(&local_18,local_20,auStack_48);
                    
  cocos2d::ZipUtils::decompressString((ZipUtils *)&local_18,(string *)0x0,true,iVar8);
  if ((GameManager *)(local_18.tv_sec + -0x18) != (GameManager *)&DAT_0134b6b0) {
    pGVar10 = (GameManager *)(local_18.tv_sec + -8);
    do {
      iVar8 = *(int *)pGVar10;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(pGVar10,0x10);
      if (bVar7) {
        *(int *)pGVar10 = iVar8 + -1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    if (iVar8 < 1) {
      operator.delete((GameManager *)(local_18.tv_sec + -0x18));
    }
  }
  if ((undefined8 *)(local_20 + -0x18) != &DAT_0134b6b0) {
    piVar21 = (int *)(local_20 + -8);
    do {
      iVar8 = *piVar21;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar21,0x10);
      if (bVar7) {
        *piVar21 = iVar8 + -1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    if (iVar8 < 1) {
      operator.delete((undefined8 *)(local_20 + -0x18));
    }
  }
  pGVar17 = (this->GJBaseGameLayer_data).m_level;
  GVar2 = (pGVar17->GJGameLevel_data).m_levelType;
  if (GVar2 == Main) {
                    
    FUN_00e18d28(&local_18,(string *)&local_28);
    pGVar17 = (this->GJBaseGameLayer_data).m_level;
                    
    cVar6 = LevelTools::verifyLevelIntegrity
                      (&local_18,
                       (pGVar17->GJGameLevel_data).m_levelID.random -
                       (pGVar17->GJGameLevel_data).m_levelID.seed);
    *(char *)((long)&(this->PlayLayer_data).m_circleWaveArray + 3) = cVar6;
    if ((GameManager *)(local_18.tv_sec + -0x18) != (GameManager *)&DAT_0134b6b0) {
      pGVar10 = (GameManager *)(local_18.tv_sec + -8);
      do {
        iVar8 = *(int *)pGVar10;
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(pGVar10,0x10);
        if (bVar7) {
          *(int *)pGVar10 = iVar8 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      if (0 < iVar8) goto LAB_006e6630;
      operator.delete((GameManager *)(local_18.tv_sec + -0x18));
      cVar6 = *(char *)((long)&(this->PlayLayer_data).m_circleWaveArray + 3);
    }
  }
  else if ((GVar2 == Editor) &&
          ((pGVar17->GJGameLevel_data).m_stars.random - (pGVar17->GJGameLevel_data).m_stars.seed < 1
          )) {
LAB_006e6630:
    cVar6 = *(char *)((long)&(this->PlayLayer_data).m_circleWaveArray + 3);
  }
  else {
    cVar6 = *(long *)(local_28 + -0x18) != 0;
    *(char *)((long)&(this->PlayLayer_data).m_circleWaveArray + 3) = cVar6;
  }
  if (cVar6 == '\0') {
                    
    plVar9 = (long *)cocos2d::CCLabelBMFont::create("Load Failed!","bigFont.fnt");
    (**(code **)(this->CCCopying + 0x1c0))(this,plVar9,100);
    pcVar22 = *(code **)(*plVar9 + 0xb8);
    cocos2d::CCPoint::CCPoint((CCPoint *)&local_18,local_38 * 0.5,local_34 * 0.5);
    (*pcVar22)(plVar9,&local_18);
  }
  prepareCreateObjectsFromSetup(this,(string *)&local_28);
  if (!param_3) {
    while (*(float *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 4) < 1.0) {
      processCreateObjectsFromSetup(this);
    }
  }
  if ((undefined8 *)(local_28 + -0x18) != &DAT_0134b6b0) {
    piVar21 = (int *)(local_28 + -8);
    do {
      iVar8 = *piVar21;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar21,0x10);
      if (bVar7) {
        *piVar21 = iVar8 + -1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    if (iVar8 < 1) {
      operator.delete((undefined8 *)(local_28 + -0x18));
    }
  }
LAB_006e601c:
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail(bVar5);
  }
  return;
}




byte PlayLayer::isGameplayActive(PlayLayer *this)

{
  byte bVar1;
  
  bVar1 = 0;
  if ((*(char *)&(this->PlayLayer_data).m_keyPulses.m_bits.last == '\0') &&
     (bVar1 = 0, *(char *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity != '\0')) {
    bVar1 = *(byte *)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pParent ^ 1;
  }
  return bVar1;
}









void PlayLayer::levelComplete(PlayLayer *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  undefined1 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  CCGridBase *pCVar11;
  GJGameLevel *pGVar12;
  CCArray *this_00;
  CCString *this_01;
  undefined8 uVar13;
  long *plVar14;
  CCFiniteTimeAction *pCVar15;
  CCAction *pCVar16;
  GameLevelManager *pGVar17;
  GameManager *pGVar18;
  GameStatsManager *pGVar19;
  long lVar20;
  CCCopying *pCVar21;
  GameObject **ppGVar22;
  int *piVar23;
  CCNode *pCVar24;
  GJMGLayer *pGVar25;
  CCDictionary *this_02;
  char cVar26;
  code *pcVar27;
  uint uVar28;
  int iVar29;
  float fVar30;
  double dVar31;
  long local_28;
  long local_20;
  long local_18;
  long local_10;
  long local_8;
  
  pCVar11 = this[1].CCNode_data.m_pGrid;
  local_8 = ___stack_chk_guard;
  if (pCVar11 == (CCGridBase *)0x0) {
    uVar7 = false;
    cVar26 = '\0';
    if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0') {
      bVar5 = false;
      goto LAB_006d0bac;
    }
  }
  else {
    uVar7 = (undefined1)pCVar11[0x20].CCObject_data.m_eObjType;
    bVar5 = *(byte *)((long)&pCVar11[0x20].CCObject_data.m_eObjType + 2);
LAB_006d0bac:
    PlayerObject::playCompleteEffect
              ((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0,(bool)uVar7,(bool)bVar5);
    PlayerObject::playCompleteEffect
              ((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start,(bool)uVar7,(bool)bVar5);
    cVar26 = uVar7;
  }
  if (*(double *)&this[1].CCObject_data.m_nTag < *(double *)&this[1].CCObject_data) {
    *(double *)&this[1].CCObject_data.m_nTag = *(double *)&this[1].CCObject_data;
  }
  pGVar12 = (this->GJBaseGameLayer_data).m_level;
  if ((((((pGVar12->GJGameLevel_data).m_levelType != Main) &&
        (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0')) &&
       (*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth == '\0')) &&
      ((((this->PlayLayer_data).field_0x16e == '\0' &&
        (0 < (pGVar12->GJGameLevel_data).m_stars.random - (pGVar12->GJGameLevel_data).m_stars.seed))
       && ((*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) == '\0' ||
           ((double)(this->GJBaseGameLayer_data).m_sectionSizes.last < 10.0)))))) &&
     (*(double *)&this[1].CCObject_data.m_nTag < 10.0)) {
    *(undefined1 *)&(this->PlayLayer_data).m_speedObjects = 1;
  }
  pCVar21 = this->CCCopying;
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start = 1;
  (**(code **)(pCVar21 + 0x588))(0x3f800000,this);
  cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth;
  if (cVar6 == '\0') {
    if ((this->PlayLayer_data).field_0x16e == '\0') {
      if ((((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_levelType == Editor) {
        GJBaseGameLayer::getCapacityString();
        pGVar12 = (this->GJBaseGameLayer_data).m_level;
                    
        FUN_00e18d28(&local_10,&local_18);
                    
        FUN_00e18ea8(&(pGVar12->GJGameLevel_data).m_capacityString,&local_10);
        if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
          piVar23 = (int *)(local_10 + -8);
          do {
            iVar9 = *piVar23;
            cVar6 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar23,0x10);
            if (bVar4) {
              *piVar23 = iVar9 + -1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          if (iVar9 < 1) {
            operator.delete((undefined8 *)(local_10 + -0x18));
          }
        }
        if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
          ppGVar22 = (this->GJBaseGameLayer_data).m_unkdd8.last;
          iVar9 = (this->GJBaseGameLayer_data).m_gameState.m_commandIndex / 2;
          if (ppGVar22 != (GameObject **)0x0) {
            *(int *)(ppGVar22 + 0x34) = iVar9;
          }
          (((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_timestamp = iVar9;
        }
        if ((undefined8 *)(local_18 + -0x18) != &DAT_0134b6b0) {
          piVar23 = (int *)(local_18 + -8);
          do {
            iVar9 = *piVar23;
            cVar6 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar23,0x10);
            if (bVar4) {
              *piVar23 = iVar9 + -1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          if (iVar9 < 1) {
            operator.delete((undefined8 *)(local_18 + -0x18));
          }
        }
        if (*(char *)&(this->PlayLayer_data).m_speedObjects == '\0') {
          if (*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth == '\0') {
            if ((this->PlayLayer_data).field_0x16e != '\0') {
              cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth;
              goto LAB_006d0cf4;
            }
            goto LAB_006d0c3c;
          }
          goto LAB_006d0d00;
        }
      }
      else if (*(char *)&(this->PlayLayer_data).m_speedObjects == '\0') {
LAB_006d0c3c:
        if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
          uVar28 = 0;
          this_00 = (CCArray *)
                    cocos2d::CCDictionary::allKeys
                              ((CCDictionary *)(this->GJBaseGameLayer_data).m_extraDelta);
          while (uVar8 = cocos2d::CCArray::count(this_00), uVar28 < uVar8) {
            this_01 = (CCString *)cocos2d::CCArray::objectAtIndex(this_00,uVar28);
            uVar13 = cocos2d::CCString::getCString(this_01);
            this_02 = (CCDictionary *)(this->GJBaseGameLayer_data).m_extraDelta;
            FUN_00e153b8((string *)&local_10,uVar13,&local_20);
                    
            plVar14 = (long *)cocos2d::CCDictionary::objectForKey(this_02,(string *)&local_10);
            if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
              piVar23 = (int *)(local_10 + -8);
              do {
                iVar9 = *piVar23;
                cVar6 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(piVar23,0x10);
                if (bVar4) {
                  *piVar23 = iVar9 + -1;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
              if (iVar9 < 1) {
                operator.delete((undefined8 *)(local_10 + -0x18));
              }
            }
            iVar9 = (**(code **)(*plVar14 + 0x6f8))(plVar14);
            if (iVar9 == 0x1f) {
              iVar9 = (int)plVar14[0xde];
              if (iVar9 == 2) {
                pGVar12 = (this->GJBaseGameLayer_data).m_level;
                uVar28 = uVar28 + 1;
                (pGVar12->GJGameLevel_data).m_secondCoinVerified.value = 1;
                iVar9 = rand();
                iVar9 = (int)((float)iVar9 * 4.656613e-10 * 1000.0);
                (pGVar12->GJGameLevel_data).m_secondCoinVerified.seed = iVar9;
                (pGVar12->GJGameLevel_data).m_secondCoinVerified.random = iVar9 + 1;
              }
              else if (iVar9 == 3) {
                pGVar12 = (this->GJBaseGameLayer_data).m_level;
                uVar28 = uVar28 + 1;
                (pGVar12->GJGameLevel_data).m_thirdCoinVerified.value = 1;
                iVar9 = rand();
                iVar9 = (int)((float)iVar9 * 4.656613e-10 * 1000.0);
                (pGVar12->GJGameLevel_data).m_thirdCoinVerified.seed = iVar9;
                (pGVar12->GJGameLevel_data).m_thirdCoinVerified.random = iVar9 + 1;
              }
              else {
                if (iVar9 != 1) goto LAB_006d0ce4;
                pGVar12 = (this->GJBaseGameLayer_data).m_level;
                uVar28 = uVar28 + 1;
                (pGVar12->GJGameLevel_data).m_firstCoinVerified.value = 1;
                iVar9 = rand();
                iVar9 = (int)((float)iVar9 * 4.656613e-10 * 1000.0);
                (pGVar12->GJGameLevel_data).m_firstCoinVerified.seed = iVar9;
                (pGVar12->GJGameLevel_data).m_firstCoinVerified.random = iVar9 + 1;
              }
            }
            else {
LAB_006d0ce4:
              uVar28 = uVar28 + 1;
            }
          }
          pGVar12 = (this->GJBaseGameLayer_data).m_level;
          if (((pGVar12->GJGameLevel_data).m_levelType == Editor) &&
             (cVar6 = GJGameLevel::areCoinsVerified(pGVar12), cVar6 != '\0')) {
            pGVar12 = (this->GJBaseGameLayer_data).m_level;
            (pGVar12->GJGameLevel_data).m_isVerifiedRaw = true;
            iVar10 = rand();
            iVar9 = (this->GJBaseGameLayer_data).m_currentStep;
            iVar10 = (int)((float)iVar10 * 4.656613e-10 * 1000.0);
            (pGVar12->GJGameLevel_data).m_isVerified.seed = iVar10;
            (pGVar12->GJGameLevel_data).m_isVerified.random = iVar10 + 1;
            if ((char)iVar9 != '\0') {
              pGVar12 = (this->GJBaseGameLayer_data).m_level;
              GJBaseGameLayer::getRecordString(SUB81(this,0));
                    
              FUN_00e163d4(&(pGVar12->GJGameLevel_data).m_recordString,&local_10);
              if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
                FUN_006c93b8((undefined8 *)(local_10 + -0x18),&local_18);
              }
            }
          }
          if (*(char *)&(this->PlayLayer_data).m_speedObjects != '\0') goto LAB_006d0fe0;
        }
LAB_006d0ed4:
        cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth;
        goto LAB_006d0cf4;
      }
    }
    else if (*(char *)&(this->PlayLayer_data).m_speedObjects == '\0') goto LAB_006d0ed4;
  }
  else if (*(char *)&(this->PlayLayer_data).m_speedObjects == '\0') {
LAB_006d0cf4:
    if ((cVar6 == '\0') && ((this->PlayLayer_data).field_0x16e == '\0')) {
      dVar31 = (double)getTempMilliTime();
      GJGameLevel::savePercentage
                ((this->GJBaseGameLayer_data).m_level,100,
                 *(bool *)&(this->GJBaseGameLayer_data).m_endPortal,
                 (this->GJBaseGameLayer_data).m_particleSystemLimit,
                 (int)((dVar31 - *(double *)&this[1].CCObject_data.m_uIndexInArray) -
                      *(double *)&this[1].CCObject_data.m_unknown2),
                 *(bool *)((long)&(this->PlayLayer_data).m_speedObjects + 3));
      if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
        GJBaseGameLayer::getRecordString(SUB81(this,0));
                    
        iVar9 = GJBaseGameLayer::countCollectedUserCoins((GJBaseGameLayer *)this);
        iVar10 = GJBaseGameLayer::getPlayTimerMilli((GJBaseGameLayer *)this);
        bVar5 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
        if (bVar5 == 0) {
          uVar1 = *(undefined4 *)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity;
          uVar2 = *(undefined4 *)((long)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity + 4);
                    
          FUN_00e18d28(&local_10,&local_28);
          pGVar12 = (this->GJBaseGameLayer_data).m_level;
                    
          GJGameLevel::saveNewScore
                    (pGVar12,iVar10,0,uVar1,uVar2,iVar9,&local_10,
                     (pGVar12->GJGameLevel_data).m_unk520 <= iVar9);
          if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
            FUN_006c93b8((undefined8 *)(local_10 + -0x18),&local_18);
          }
        }
        else {
          pGVar18 = (GameManager *)GameManager::sharedState((GameManager *)(ulong)bVar5);
          *(int *)(pGVar18 + 0x5d8) =
               (((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_M_ID;
          pGVar18 = (GameManager *)GameManager::sharedState(pGVar18);
          bVar4 = (this->GJBaseGameLayer_data).m_gameState.m_unkBool32;
          *(int *)(pGVar18 + 0x5dc) = iVar10;
          if (bVar4 == false) {
                    
            lVar20 = GameManager::sharedState(pGVar18);
            *(undefined4 *)(lVar20 + 0x5e0) = 0;
          }
          else {
            iVar29 = (this->GJBaseGameLayer_data).m_gameState.m_points;
            if (*(char *)((long)(this->GJBaseGameLayer_data).m_unkdd8.last + 0x19e) == '\0') {
              iVar29 = iVar29 - iVar10;
              (this->GJBaseGameLayer_data).m_gameState.m_points = iVar29;
            }
            pGVar12 = (this->GJBaseGameLayer_data).m_level;
            uVar1 = *(undefined4 *)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity;
            uVar2 = *(undefined4 *)((long)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity + 4)
            ;
            FUN_00e18d28(&local_20,&local_28);
                    
            GJGameLevel::saveNewScore(pGVar12,iVar29,1,uVar1,uVar2,iVar9,&local_20,0);
            pGVar18 = (GameManager *)(local_20 + -0x18);
            if (pGVar18 != (GameManager *)&DAT_0134b6b0) {
              pGVar18 = (GameManager *)FUN_006c93b8(pGVar18,&local_10);
            }
                    
            lVar20 = GameManager::sharedState(pGVar18);
            *(int *)(lVar20 + 0x5e0) = (this->GJBaseGameLayer_data).m_gameState.m_points;
          }
          uVar1 = *(undefined4 *)((long)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity + 4);
          pGVar12 = (this->GJBaseGameLayer_data).m_level;
          uVar2 = *(undefined4 *)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity;
          FUN_00e18d28(&local_18,&local_28);
                    
          GJGameLevel::saveNewScore(pGVar12,iVar10,0,uVar2,uVar1,iVar9,&local_18,0);
          if ((undefined8 *)(local_18 + -0x18) != &DAT_0134b6b0) {
            FUN_006c93b8((undefined8 *)(local_18 + -0x18),&local_10);
          }
        }
        if ((undefined8 *)(local_28 + -0x18) != &DAT_0134b6b0) {
          piVar23 = (int *)(local_28 + -8);
          do {
            iVar9 = *piVar23;
            cVar6 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar23,0x10);
            if (bVar4) {
              *piVar23 = iVar9 + -1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          if (iVar9 < 1) {
            operator.delete((undefined8 *)(local_28 + -0x18));
          }
        }
        if ((((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_levelType == Main)
        goto LAB_006d1154;
      }
      else {
        if ((((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_levelType != Main)
        goto LAB_006d0d00;
LAB_006d1154:
        pGVar18 = (GameManager *)GameManager::sharedState((GameManager *)0x1);
        pGVar12 = (this->GJBaseGameLayer_data).m_level;
        GameManager::reportPercentageForLevel
                  (pGVar18,(pGVar12->GJGameLevel_data).m_levelID.random -
                           (pGVar12->GJGameLevel_data).m_levelID.seed,100,
                   *(bool *)&(this->GJBaseGameLayer_data).m_endPortal);
      }
      if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
        pGVar12 = (this->GJBaseGameLayer_data).m_level;
        if ((pGVar12->GJGameLevel_data).m_levelType != Editor) {
          uVar28 = (pGVar12->GJGameLevel_data).m_stars.random -
                   (pGVar12->GJGameLevel_data).m_stars.seed;
          if (0 < (int)uVar28) {
            pGVar19 = (GameStatsManager *)
                      GameStatsManager::sharedState((GameStatsManager *)(ulong)uVar28);
            bVar5 = GameStatsManager::hasCompletedStarLevel
                              (pGVar19,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
            pGVar19 = (GameStatsManager *)(ulong)bVar5;
            if (bVar5 == 0) {
              pGVar19 = (GameStatsManager *)0x1;
              *(undefined1 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.last + 7) = 1;
            }
            pGVar19 = (GameStatsManager *)GameStatsManager::sharedState(pGVar19);
            iVar9 = GameStatsManager::awardCurrencyForLevel
                              (pGVar19,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
            *(int *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.capacity + 3) = iVar9;
            pGVar12 = (this->GJBaseGameLayer_data).m_level;
            uVar28 = (pGVar12->GJGameLevel_data).m_dailyID.random -
                     (pGVar12->GJGameLevel_data).m_dailyID.seed;
            pGVar19 = (GameStatsManager *)(ulong)uVar28;
            if (((int)uVar28 < 1) &&
               (bVar4 = (pGVar12->GJGameLevel_data).m_gauntletLevel,
               pGVar19 = (GameStatsManager *)(ulong)bVar4, bVar4 == false)) {
              pGVar19 = (GameStatsManager *)0x0;
            }
            else {
              pGVar19 = (GameStatsManager *)GameStatsManager::sharedState(pGVar19);
              pGVar19 = (GameStatsManager *)
                        GameStatsManager::awardDiamondsForLevel
                                  (pGVar19,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
              *(int *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.capacity + 7) = (int)pGVar19
              ;
              iVar9 = *(int *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.capacity + 3);
            }
            if (0 < iVar9) {
              pGVar19 = (GameStatsManager *)GameStatsManager::sharedState(pGVar19);
              uVar7 = GameStatsManager::awardSecretKey(pGVar19);
              *(undefined1 *)((long)&(this->PlayLayer_data).m_nextColorKey + 3) = uVar7;
            }
          }
          pGVar19 = (GameStatsManager *)GJBaseGameLayer::processItems((GJBaseGameLayer *)this);
          pGVar19 = (GameStatsManager *)GameStatsManager::sharedState(pGVar19);
          pGVar19 = (GameStatsManager *)
                    GameStatsManager::completedLevel
                              (pGVar19,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
          pGVar19 = (GameStatsManager *)GameStatsManager::sharedState(pGVar19);
          GameStatsManager::checkCoinAchievement
                    (pGVar19,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
          if ((*(char *)&(this->GJBaseGameLayer_data).m_endPortal != '\0') ||
             (pGVar12 = (this->GJBaseGameLayer_data).m_level,
             (pGVar12->GJGameLevel_data).m_levelType != Editor)) goto LAB_006d0d00;
        }
        (pGVar12->GJGameLevel_data).m_autoLevel =
             (bool)(*(byte *)((long)&(this->PlayLayer_data).m_keyOpacities.capacity + 7) ^ 1);
      }
    }
LAB_006d0d00:
    commitJumps(this);
    pGVar12 = (this->GJBaseGameLayer_data).m_level;
    if (((((pGVar12->GJGameLevel_data).m_savedTime != false) ||
         ((pGVar12->GJGameLevel_data).m_savedPoints != false)) &&
        ((pGVar12->GJGameLevel_data).m_levelType != Editor)) &&
       (uVar28 = (pGVar12->GJGameLevel_data).m_demon.random -
                 (pGVar12->GJGameLevel_data).m_demon.seed, pGVar12 = (GJGameLevel *)(ulong)uVar28,
       uVar28 == 1)) {
      bVar5 = PlatformToolbox::isNetworkAvailable();
      pGVar12 = (GJGameLevel *)(ulong)bVar5;
      if (bVar5 != 0) {
        pGVar12 = (this->GJBaseGameLayer_data).m_level;
        if ((pGVar12->GJGameLevel_data).m_savedTime != false) {
          pGVar17 = (GameLevelManager *)GameLevelManager::sharedState((GameLevelManager *)pGVar12);
          GameLevelManager::getLevelLeaderboard(pGVar17,(this->GJBaseGameLayer_data).m_level,4,0);
          pGVar12 = (this->GJBaseGameLayer_data).m_level;
        }
        bVar4 = (pGVar12->GJGameLevel_data).m_savedPoints;
        pGVar12 = (GJGameLevel *)(ulong)bVar4;
        if (bVar4 != false) {
          pGVar17 = (GameLevelManager *)GameLevelManager::sharedState((GameLevelManager *)pGVar12);
          pGVar12 = (GJGameLevel *)
                    GameLevelManager::getLevelLeaderboard
                              (pGVar17,(this->GJBaseGameLayer_data).m_level,4,1);
        }
      }
    }
    if (cVar26 == '\0') {
      iVar9 = 0;
      do {
        fVar30 = (float)iVar9;
        iVar9 = iVar9 + 1;
        pCVar15 = (CCFiniteTimeAction *)
                  cocos2d::CCDelayTime::create((CCDelayTime *)pGVar12,fVar30 * 0.05);
        uVar13 = cocos2d::CCCallFunc::create
                           ((CCCallFunc *)this,(CCObject *)spawnCircle,(_func_void *)0x0);
        pCVar16 = (CCAction *)cocos2d::CCSequence::create(pCVar15,uVar13,0);
        pGVar12 = (GJGameLevel *)cocos2d::CCNode::runAction((CCNode *)this,pCVar16);
      } while (iVar9 != 5);
      plVar14 = (long *)CCCircleWave::create(10.0,250.0,0.5,false);
      pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
      *(undefined4 *)((long)plVar14 + 0x164) = 4;
      uVar7 = *(undefined1 *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 2);
      uVar3 = *(undefined1 *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 3);
      *(undefined1 *)((long)plVar14 + 0x156) =
           *(undefined1 *)&pCVar24[8].CCNode_data.m_obAnchorPointInPoints.x;
      *(undefined1 *)((long)plVar14 + 0x154) = uVar7;
      *(undefined1 *)((long)plVar14 + 0x155) = uVar3;
      pcVar27 = *(code **)(*plVar14 + 0xb8);
      getEndPosition();
      (*pcVar27)(plVar14,&local_10);
      pGVar25 = (this->GJBaseGameLayer_data).m_middleground;
      (**(code **)(pGVar25->CCCopying + 0x1c0))(pGVar25,plVar14,0);
    }
    bVar5 = *(byte *)&(this->GJBaseGameLayer_data).m_endPortal;
    if (bVar5 == 0) {
      showCompleteEffect(this);
    }
    else {
      pCVar15 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create((CCDelayTime *)(ulong)bVar5,0.1);
      uVar13 = cocos2d::CCCallFunc::create
                         ((CCCallFunc *)this,(CCObject *)showCompleteText,(_func_void *)0x0);
      pCVar16 = (CCAction *)cocos2d::CCSequence::create(pCVar15,uVar13,0);
      cocos2d::CCNode::runAction((CCNode *)this,pCVar16);
    }
    goto LAB_006d0e38;
  }
LAB_006d0fe0:
  onQuit(this);
LAB_006d0e38:
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}


/* PlayLayer::loadActiveSaveObjects(std::vector<SavedActiveObjectState,
   std::allocator<SavedActiveObjectState> >&, std::vector<SavedSpecialObjectState,
   std::allocator<SavedSpecialObjectState> >&) */

void PlayLayer::loadActiveSaveObjects(PlayLayer *this,vector *param_1,vector *param_2)

{
  long *plVar1;
  AnimatedGameObject *this_00;
  long lVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  plVar3 = *(long **)(param_1 + 8);
  for (plVar1 = *(long **)param_1; plVar3 != plVar1; plVar1 = plVar1 + 2) {
    lVar2 = *plVar1;
    *(char *)(lVar2 + 0x594) = (char)plVar1[1];
    *(undefined1 *)(lVar2 + 0x595) = *(undefined1 *)((long)plVar1 + 9);
  }
  puVar5 = *(undefined8 **)(param_2 + 8);
  puVar4 = *(undefined8 **)param_2;
  do {
    if (puVar5 == puVar4) {
      return;
    }
    while (this_00 = (AnimatedGameObject *)*puVar4, *(int *)(this_00 + 0x4d0) != 2) {
      if (*(int *)(this_00 + 0x3f4) != 0x64f) goto LAB_006d05c8;
      puVar4 = puVar4 + 2;
      this_00[0x750] = (AnimatedGameObject)0x1;
      if (puVar5 == puVar4) {
        return;
      }
    }
    AnimatedGameObject::playAnimation(this_00,*(int *)(puVar4 + 1));
LAB_006d05c8:
    puVar4 = puVar4 + 2;
  } while( true );
}





void PlayLayer::loadDefaultColors(PlayLayer *this)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  CCArray *pCVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  _Hashtable<> *local_50;
  undefined1 *local_48;
  undefined8 *local_40;
  long local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20 [2];
  undefined8 local_18;
  undefined8 local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  local_30 = 0;
  local_28 = 0;
  local_20[0] = 0x3f800000;
  local_18 = 0;
  local_38 = FUN_00e146dc(local_20,10);
  if (local_38 == 1) {
    local_10 = 0;
    local_40 = &local_10;
  }
  else {
    local_40 = (undefined8 *)FUN_006c99c0();
  }
                    
  pCVar4 = (CCArray *)
           GJEffectManager::getAllColorActions
                     ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4);
  uVar7 = 0;
  while (uVar3 = cocos2d::CCArray::count(pCVar4), uVar7 < uVar3) {
    lVar5 = cocos2d::CCArray::objectAtIndex(pCVar4,uVar7);
    if (*(char *)(lVar5 + 0x54) == '\0') {
      uVar7 = uVar7 + 1;
    }
    else {
      local_48 = (undefined1 *)CONCAT44(local_48._4_4_,*(undefined4 *)(lVar5 + 0x5c));
      local_50 = (_Hashtable<> *)&local_40;
      std::_Hashtable<>::_M_insert<>((_Hashtable<> *)&local_40,&local_48,&local_50,0);
      uVar7 = uVar7 + 1;
    }
  }
  GJEffectManager::reset((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4);
  pCVar4 = (CCArray *)
           GJEffectManager::getAllColorActions
                     ((GJEffectManager *)(this->GJBaseGameLayer_data).m_unkdd8.last[0x28]);
  for (uVar7 = 0; uVar3 = cocos2d::CCArray::count(pCVar4), uVar7 < uVar3; uVar7 = uVar7 + 1) {
    lVar5 = cocos2d::CCArray::objectAtIndex(pCVar4,uVar7);
    (**(code **)(this->CCCopying + 0x4c0))
              (0,*(undefined4 *)(lVar5 + 0x60),this,lVar5 + 0x48,*(undefined4 *)(lVar5 + 0x5c),
               *(undefined1 *)(lVar5 + 0x54),lVar5 + 0x68,*(undefined4 *)(lVar5 + 0x78),
               *(undefined1 *)(lVar5 + 0x7d),0,*(undefined4 *)(lVar5 + 0x80),
               *(undefined4 *)(lVar5 + 0x84));
  }
  pCVar4 = (CCArray *)
           GJEffectManager::getAllColorActions
                     ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4);
  puVar1 = (undefined1 *)((long)&(this->PlayLayer_data).m_unk3920.x + 3);
  for (uVar7 = 0; uVar3 = cocos2d::CCArray::count(pCVar4), uVar7 < uVar3; uVar7 = uVar7 + 1) {
    lVar5 = cocos2d::CCArray::objectAtIndex(pCVar4,uVar7);
    uVar2 = *(undefined4 *)(lVar5 + 0x5c);
    lVar6 = FUN_006c955c((_Hashtable<> *)&local_40,uVar2);
    if ((bool)*(char *)(lVar5 + 0x54) != (lVar6 != 0)) {
      local_50 = (_Hashtable<> *)CONCAT44(local_50._4_4_,uVar2);
      local_48 = puVar1;
      std::_Hashtable<>::_M_insert<>(puVar1,&local_50,&local_48,0);
    }
  }
  GJEffectManager::updateEffects
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,0.0);
  GJEffectManager::calculateBaseActiveColors
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4);
  GJEffectManager::processInheritedColors
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4);
  std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_40);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}



/* PlayLayer::loadDynamicSaveObjects(std::vector<SavedObjectStateRef,
   std::allocator<SavedObjectStateRef> >&) */

void PlayLayer::loadDynamicSaveObjects(PlayLayer *this,vector *param_1)

{
  undefined8 *puVar1;
  float fVar2;
  CCCopying *pCVar3;
  double dVar4;
  GameObject *this_00;
  undefined8 *puVar5;
  undefined8 *puVar6;
  code *pcVar7;
  CCPoint aCStack_10 [8];
  long local_8;
  
  puVar6 = *(undefined8 **)(param_1 + 8);
  local_8 = ___stack_chk_guard;
  if (puVar6 != *(undefined8 **)param_1) {
    puVar5 = *(undefined8 **)param_1;
    do {
      this_00 = (GameObject *)*puVar5;
      fVar2 = *(float *)(puVar5 + 3);
      puVar1 = puVar5 + 6;
      (this_00->GameObject_data).m_positionX = (double)puVar5[1];
      dVar4 = (double)puVar5[2];
      (this_00->GameObject_data).m_rotationXOffset = fVar2;
      fVar2 = *(float *)((long)puVar5 + 0x1c);
      (this_00->GameObject_data).m_positionY = dVar4;
      (this_00->GameObject_data).m_rotationYOffset = fVar2;
      GameObject::addToCustomScaleX(this_00,*(float *)(puVar5 + 4));
      GameObject::addToCustomScaleY(this_00,*(float *)((long)puVar5 + 0x24));
      (**(code **)(this_00->CCCopying + 0x5b8))(0,this_00);
      (**(code **)(this_00->CCCopying + 0x5a0))(0x3f800000,this_00);
      (this_00->GameObject_data).m_unk4C4 = -1;
      pCVar3 = this_00->CCCopying;
      (this_00->GameObject_data).m_unk4CC = -1;
      pcVar7 = *(code **)(pCVar3 + 0xb8);
      (**(code **)(pCVar3 + 0x540))(aCStack_10,this_00);
      (*pcVar7)(this_00,aCStack_10);
      (**(code **)(this_00->CCCopying + 0x540))(aCStack_10,this_00);
      GameObject::setLastPosition(this_00,aCStack_10);
      (**(code **)(this_00->CCCopying + 0x6e0))(this_00,1);
      (this_00->GameObject_data).m_isDirty = true;
      (**(code **)(this_00->CCCopying + 0x6f0))(this_00,1);
      (**(code **)(this->CCCopying + 0x528))(this,this_00);
      puVar5 = puVar1;
    } while (puVar6 != puVar1);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void PlayLayer::loadFromCheckpoint(PlayLayer *this,CheckpointObject *param_1)

{
  _Hashtable<> *this_00;
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  CheckpointObject CVar17;
  CheckpointObject CVar18;
  CheckpointObject CVar19;
  CheckpointObject CVar20;
  CheckpointObject CVar21;
  CheckpointObject CVar22;
  CheckpointObject CVar23;
  CheckpointObject CVar24;
  byte bVar25;
  undefined2 uVar26;
  PlayerCheckpoint PVar27;
  char cVar28;
  bool bVar29;
  uint uVar30;
  int iVar31;
  GameObject *pGVar32;
  GameObject *pGVar33;
  _Hashtable *p_Var34;
  PlayerObject *pPVar35;
  GradientTriggerObject *pGVar36;
  long *plVar37;
  FMODAudioEngine *pFVar38;
  uint *puVar39;
  PlayerCheckpoint *pPVar40;
  uint uVar41;
  long lVar42;
  undefined8 *puVar43;
  CCDictionary *pCVar44;
  CCDictionary *pCVar45;
  CCArray *this_01;
  GameObject **ppGVar46;
  CCDictionary *pCVar47;
  GameObject *pGVar48;
  GameObject **local_20;
  GameObject *local_18;
  _Hashtable<> *local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (param_1 == (CheckpointObject *)0x0) goto LAB_006e4ebc;
  GJGameState::operator=(&(this->GJBaseGameLayer_data).m_gameState,(GJGameState *)(param_1 + 0x140))
  ;
  ppGVar46 = (this->GJBaseGameLayer_data).m_solidCollisionObjects.capacity;
  if (ppGVar46 != (GameObject **)0x0) {
    this_00 = (_Hashtable<> *)(ppGVar46 + 0x3a);
    std::_Hashtable<>::operator=((_Hashtable<> *)(ppGVar46 + 0x33),(_Hashtable *)(param_1 + 0x838));
    if (this_00 != (_Hashtable<> *)(param_1 + 0x870)) {
      if (ppGVar46[0x3b] == *(GameObject **)(param_1 + 0x878)) {
        pGVar48 = (GameObject *)0x0;
        memset(ppGVar46[0x3a],0,(long)ppGVar46[0x3b] << 3);
      }
      else {
        pGVar48 = ppGVar46[0x3a];
        if (*(GameObject **)(param_1 + 0x878) == (GameObject *)0x1) {
          ppGVar46[0x40] = (GameObject *)0x0;
          pGVar32 = (GameObject *)(ppGVar46 + 0x40);
          pGVar33 = (GameObject *)0x1;
        }
        else {
          pGVar32 = (GameObject *)FUN_006c9a0c();
          pGVar33 = *(GameObject **)(param_1 + 0x878);
        }
        ppGVar46[0x3a] = pGVar32;
        ppGVar46[0x3b] = pGVar33;
      }
      pGVar32 = *(GameObject **)(param_1 + 0x890);
      pGVar33 = *(GameObject **)(param_1 + 0x898);
      local_18 = ppGVar46[0x3c];
      local_20 = &local_18;
      ppGVar46[0x3d] = *(GameObject **)(param_1 + 0x888);
      ppGVar46[0x3e] = pGVar32;
      ppGVar46[0x3f] = pGVar33;
      ppGVar46[0x3c] = (GameObject *)0x0;
      local_10 = this_00;
                    
      std::_Hashtable<>::operator=
                (this_00,(_Hashtable *)(param_1 + 0x870),
                 ({lambda(std::__detail::_Hash_node<>_const*)#2} *)&local_20);
      pGVar32 = local_18;
      if ((pGVar48 != (GameObject *)0x0) && (pGVar48 != (GameObject *)(ppGVar46 + 0x40))) {
        operator.delete(pGVar48);
        pGVar32 = local_18;
      }
      while (pGVar32 != (GameObject *)0x0) {
        pGVar48 = (GameObject *)pGVar32->CCCopying;
        operator.delete(pGVar32);
        pGVar32 = pGVar48;
      }
    }
    uVar26 = *(undefined2 *)(param_1 + 0x8c8);
    pGVar32 = *(GameObject **)(param_1 + 0x8b0);
    uVar2 = *(undefined4 *)(param_1 + 0x8d0);
    pGVar48 = *(GameObject **)(param_1 + 0x8b8);
    CVar17 = param_1[0x8d4];
    uVar3 = *(undefined4 *)(param_1 + 0x8c0);
    uVar4 = *(undefined4 *)(param_1 + 0x8c4);
    ppGVar46[0x41] = *(GameObject **)(param_1 + 0x8a8);
    ppGVar46[0x42] = pGVar32;
    ppGVar46[0x43] = pGVar48;
    *(undefined4 *)(ppGVar46 + 0x44) = uVar3;
    *(undefined4 *)((long)ppGVar46 + 0x224) = uVar4;
    *(undefined2 *)(ppGVar46 + 0x45) = uVar26;
    uVar3 = *(undefined4 *)(param_1 + 0x8d8);
    *(CheckpointObject *)((long)ppGVar46 + 0x22a) = param_1[0x8ca];
    uVar4 = *(undefined4 *)(param_1 + 0x8dc);
    uVar5 = *(undefined4 *)(param_1 + 0x8cc);
    *(undefined4 *)(ppGVar46 + 0x46) = uVar2;
    uVar2 = *(undefined4 *)(param_1 + 0x8e0);
    *(CheckpointObject *)((long)ppGVar46 + 0x234) = CVar17;
    uVar6 = *(undefined4 *)(param_1 + 0x8e4);
    uVar7 = *(undefined4 *)(param_1 + 0x8e8);
    uVar8 = *(undefined4 *)(param_1 + 0x8ec);
    uVar9 = *(undefined4 *)(param_1 + 0x8f0);
    *(undefined4 *)((long)ppGVar46 + 0x22c) = uVar5;
    *(undefined4 *)(ppGVar46 + 0x47) = uVar3;
    *(undefined4 *)((long)ppGVar46 + 0x23c) = uVar4;
    *(undefined4 *)(ppGVar46 + 0x48) = uVar2;
    *(undefined4 *)((long)ppGVar46 + 0x244) = uVar6;
    *(undefined4 *)(ppGVar46 + 0x49) = uVar7;
    *(undefined4 *)((long)ppGVar46 + 0x24c) = uVar8;
    *(undefined4 *)(ppGVar46 + 0x4a) = uVar9;
    uVar2 = *(undefined4 *)(param_1 + 0x8f4);
    uVar3 = *(undefined4 *)(param_1 + 0x908);
    uVar4 = *(undefined4 *)(param_1 + 0x8f8);
    CVar17 = param_1[0x90c];
    uVar5 = *(undefined4 *)(param_1 + 0x900);
    CVar18 = param_1[0x90d];
    uVar6 = *(undefined4 *)(param_1 + 0x904);
    CVar19 = param_1[0x90e];
    uVar7 = *(undefined4 *)(param_1 + 0x910);
    *(CheckpointObject *)((long)ppGVar46 + 0x25c) = param_1[0x8fc];
    *(undefined4 *)(ppGVar46 + 0x4d) = uVar3;
    *(CheckpointObject *)((long)ppGVar46 + 0x26c) = CVar17;
    *(CheckpointObject *)((long)ppGVar46 + 0x26d) = CVar18;
    *(CheckpointObject *)((long)ppGVar46 + 0x26e) = CVar19;
    *(undefined4 *)((long)ppGVar46 + 0x254) = uVar2;
    *(undefined4 *)(ppGVar46 + 0x4b) = uVar4;
    *(undefined4 *)(ppGVar46 + 0x4c) = uVar5;
    *(undefined4 *)((long)ppGVar46 + 0x264) = uVar6;
    *(undefined4 *)(ppGVar46 + 0x4e) = uVar7;
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x274),(CCPoint *)(param_1 + 0x914));
    *(CheckpointObject *)((long)ppGVar46 + 0x27c) = param_1[0x91c];
    cocos2d::CCPoint::operator=((CCPoint *)(ppGVar46 + 0x50),(CCPoint *)(param_1 + 0x920));
    pGVar48 = *(GameObject **)(param_1 + 0x928);
    CVar17 = param_1[0x93d];
    CVar18 = param_1[0x93e];
    uVar2 = *(undefined4 *)(param_1 + 0x930);
    uVar3 = *(undefined4 *)(param_1 + 0x958);
    uVar4 = *(undefined4 *)(param_1 + 0x940);
    CVar19 = param_1[0x95c];
    uVar5 = *(undefined4 *)(param_1 + 0x944);
    CVar20 = param_1[0x93f];
    uVar6 = *(undefined4 *)(param_1 + 0x948);
    uVar7 = *(undefined4 *)(param_1 + 0x934);
    uVar8 = *(undefined4 *)(param_1 + 0x938);
    *(CheckpointObject *)((long)ppGVar46 + 0x29c) = param_1[0x93c];
    *(CheckpointObject *)((long)ppGVar46 + 0x29d) = CVar17;
    uVar9 = *(undefined4 *)(param_1 + 0x94c);
    *(CheckpointObject *)((long)ppGVar46 + 0x29e) = CVar18;
    uVar10 = *(undefined4 *)(param_1 + 0x950);
    *(CheckpointObject *)((long)ppGVar46 + 0x29f) = CVar20;
    uVar11 = *(undefined4 *)(param_1 + 0x954);
    CVar17 = param_1[0x95d];
    ppGVar46[0x51] = pGVar48;
    *(undefined4 *)(ppGVar46 + 0x57) = uVar3;
    *(undefined4 *)(ppGVar46 + 0x52) = uVar2;
    *(CheckpointObject *)((long)ppGVar46 + 700) = CVar19;
    *(undefined4 *)(ppGVar46 + 0x54) = uVar4;
    *(undefined4 *)((long)ppGVar46 + 0x2a4) = uVar5;
    *(undefined4 *)(ppGVar46 + 0x55) = uVar6;
    *(undefined4 *)((long)ppGVar46 + 0x2ac) = uVar9;
    *(undefined4 *)(ppGVar46 + 0x56) = uVar10;
    *(undefined4 *)((long)ppGVar46 + 0x294) = uVar7;
    *(undefined4 *)(ppGVar46 + 0x53) = uVar8;
    *(undefined4 *)((long)ppGVar46 + 0x2b4) = uVar11;
    *(CheckpointObject *)((long)ppGVar46 + 0x2bd) = CVar17;
    uVar2 = *(undefined4 *)(param_1 + 0x960);
    *(CheckpointObject *)((long)ppGVar46 + 0x2be) = param_1[0x95e];
    *(undefined4 *)(ppGVar46 + 0x58) = uVar2;
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x2c4),(CCPoint *)(param_1 + 0x964));
    *(CheckpointObject *)((long)ppGVar46 + 0x2cc) = param_1[0x96c];
    cocos2d::CCPoint::operator=((CCPoint *)(ppGVar46 + 0x5a),(CCPoint *)(param_1 + 0x970));
    uVar2 = *(undefined4 *)(param_1 + 0x978);
    CVar17 = param_1[0x99c];
    uVar3 = *(undefined4 *)(param_1 + 0x97c);
    uVar4 = *(undefined4 *)(param_1 + 0x980);
    uVar5 = *(undefined4 *)(param_1 + 0x984);
    uVar6 = *(undefined4 *)(param_1 + 0x988);
    uVar7 = *(undefined4 *)(param_1 + 0x98c);
    *(CheckpointObject *)(ppGVar46 + 0x5e) = param_1[0x990];
    uVar8 = *(undefined4 *)(param_1 + 0x994);
    uVar9 = *(undefined4 *)(param_1 + 0x998);
    *(CheckpointObject *)((long)ppGVar46 + 0x2fc) = CVar17;
    uVar10 = *(undefined4 *)(param_1 + 0x9a0);
    uVar11 = *(undefined4 *)(param_1 + 0x9a4);
    uVar12 = *(undefined4 *)(param_1 + 0x9a8);
    uVar13 = *(undefined4 *)(param_1 + 0x9ac);
    uVar14 = *(undefined4 *)(param_1 + 0x9b0);
    uVar15 = *(undefined4 *)(param_1 + 0x9b4);
    uVar16 = *(undefined4 *)(param_1 + 0x9b8);
    *(undefined4 *)(ppGVar46 + 0x5b) = uVar2;
    *(undefined4 *)((long)ppGVar46 + 0x2dc) = uVar3;
    *(undefined4 *)(ppGVar46 + 0x5c) = uVar4;
    *(undefined4 *)((long)ppGVar46 + 0x2e4) = uVar5;
    *(undefined4 *)(ppGVar46 + 0x5d) = uVar6;
    *(undefined4 *)((long)ppGVar46 + 0x2ec) = uVar7;
    *(undefined4 *)((long)ppGVar46 + 0x2f4) = uVar8;
    *(undefined4 *)(ppGVar46 + 0x5f) = uVar9;
    *(undefined4 *)(ppGVar46 + 0x60) = uVar10;
    *(undefined4 *)((long)ppGVar46 + 0x304) = uVar11;
    *(undefined4 *)(ppGVar46 + 0x61) = uVar12;
    *(undefined4 *)((long)ppGVar46 + 0x30c) = uVar13;
    *(undefined4 *)(ppGVar46 + 0x62) = uVar14;
    *(undefined4 *)((long)ppGVar46 + 0x314) = uVar15;
    *(undefined4 *)(ppGVar46 + 99) = uVar16;
    CVar17 = param_1[0x9c0];
    uVar2 = *(undefined4 *)(param_1 + 0x9bc);
    CVar18 = param_1[0x9c1];
    uVar3 = *(undefined4 *)(param_1 + 0x9c4);
    CVar19 = param_1[0x9c2];
    uVar4 = *(undefined4 *)(param_1 + 0x9c8);
    CVar20 = param_1[0x9c3];
    uVar5 = *(undefined4 *)(param_1 + 0x9d0);
    CVar21 = param_1[0x9cc];
    uVar6 = *(undefined4 *)(param_1 + 0x9d4);
    CVar22 = param_1[0x9cd];
    uVar7 = *(undefined4 *)(param_1 + 0x9d8);
    CVar23 = param_1[0x9ce];
    CVar24 = param_1[0x9cf];
    uVar8 = *(undefined4 *)(param_1 + 0x9dc);
    *(undefined4 *)(ppGVar46 + 0x68) = *(undefined4 *)(param_1 + 0x9e0);
    *(undefined4 *)((long)ppGVar46 + 0x31c) = uVar2;
    *(CheckpointObject *)(ppGVar46 + 100) = CVar17;
    *(CheckpointObject *)((long)ppGVar46 + 0x321) = CVar18;
    *(CheckpointObject *)((long)ppGVar46 + 0x322) = CVar19;
    *(CheckpointObject *)((long)ppGVar46 + 0x323) = CVar20;
    *(undefined4 *)((long)ppGVar46 + 0x324) = uVar3;
    *(CheckpointObject *)((long)ppGVar46 + 0x32c) = CVar21;
    *(undefined4 *)(ppGVar46 + 0x65) = uVar4;
    *(CheckpointObject *)((long)ppGVar46 + 0x32d) = CVar22;
    *(CheckpointObject *)((long)ppGVar46 + 0x32e) = CVar23;
    *(CheckpointObject *)((long)ppGVar46 + 0x32f) = CVar24;
    *(undefined4 *)(ppGVar46 + 0x66) = uVar5;
    *(undefined4 *)((long)ppGVar46 + 0x33c) = uVar8;
    *(undefined4 *)((long)ppGVar46 + 0x334) = uVar6;
    *(undefined4 *)(ppGVar46 + 0x67) = uVar7;
    *(CheckpointObject *)((long)ppGVar46 + 0x344) = param_1[0x9e4];
    *(CheckpointObject *)((long)ppGVar46 + 0x345) = param_1[0x9e5];
    *(undefined2 *)((long)ppGVar46 + 0x346) = *(undefined2 *)(param_1 + 0x9e6);
    *(CheckpointObject *)(ppGVar46 + 0x69) = param_1[0x9e8];
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x34c),(CCPoint *)(param_1 + 0x9ec));
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x354),(CCPoint *)(param_1 + 0x9f4));
    uVar2 = *(undefined4 *)(param_1 + 0x9fc);
    uVar3 = *(undefined4 *)(param_1 + 0xa00);
    CVar17 = param_1[0xa04];
    *(undefined4 *)(ppGVar46 + 0x6d) = *(undefined4 *)(param_1 + 0xa08);
    *(CheckpointObject *)((long)ppGVar46 + 0x364) = CVar17;
    *(undefined4 *)((long)ppGVar46 + 0x35c) = uVar2;
    *(undefined4 *)(ppGVar46 + 0x6c) = uVar3;
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x36c),(CCPoint *)(param_1 + 0xa0c));
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x374),(CCPoint *)(param_1 + 0xa14));
    uVar2 = *(undefined4 *)(param_1 + 0xa1c);
    uVar3 = *(undefined4 *)(param_1 + 0xa48);
    uVar4 = *(undefined4 *)(param_1 + 0xa20);
    uVar5 = *(undefined4 *)(param_1 + 0xa38);
    uVar6 = *(undefined4 *)(param_1 + 0xa24);
    CVar17 = param_1[0xa3d];
    CVar18 = param_1[0xa44];
    uVar7 = *(undefined4 *)(param_1 + 0xa28);
    CVar19 = param_1[0xa3c];
    uVar8 = *(undefined4 *)(param_1 + 0xa2c);
    uVar9 = *(undefined4 *)(param_1 + 0xa30);
    uVar10 = *(undefined4 *)(param_1 + 0xa40);
    *(undefined4 *)((long)ppGVar46 + 0x394) = *(undefined4 *)(param_1 + 0xa34);
    uVar11 = *(undefined4 *)(param_1 + 0xa4c);
    *(undefined4 *)(ppGVar46 + 0x75) = uVar3;
    *(undefined4 *)(ppGVar46 + 0x73) = uVar5;
    *(CheckpointObject *)((long)ppGVar46 + 0x39d) = CVar17;
    *(CheckpointObject *)((long)ppGVar46 + 0x3a4) = CVar18;
    *(CheckpointObject *)((long)ppGVar46 + 0x39c) = CVar19;
    *(undefined4 *)((long)ppGVar46 + 0x37c) = uVar2;
    *(undefined4 *)(ppGVar46 + 0x70) = uVar4;
    *(undefined4 *)((long)ppGVar46 + 900) = uVar6;
    *(undefined4 *)(ppGVar46 + 0x71) = uVar7;
    *(undefined4 *)((long)ppGVar46 + 0x38c) = uVar8;
    *(undefined4 *)(ppGVar46 + 0x72) = uVar9;
    *(undefined4 *)(ppGVar46 + 0x74) = uVar10;
    *(undefined4 *)((long)ppGVar46 + 0x3ac) = uVar11;
    cocos2d::CCPoint::operator=((CCPoint *)(ppGVar46 + 0x76),(CCPoint *)(param_1 + 0xa50));
    cocos2d::CCPoint::operator=((CCPoint *)(ppGVar46 + 0x77),(CCPoint *)(param_1 + 0xa58));
    uVar2 = *(undefined4 *)(param_1 + 0xa60);
    CVar17 = param_1[0xa69];
    uVar3 = *(undefined4 *)(param_1 + 0xa64);
    uVar4 = *(undefined4 *)(param_1 + 0xa6c);
    uVar5 = *(undefined4 *)(param_1 + 0xa70);
    *(CheckpointObject *)(ppGVar46 + 0x79) = param_1[0xa68];
    *(CheckpointObject *)((long)ppGVar46 + 0x3c9) = CVar17;
    *(undefined4 *)((long)ppGVar46 + 0x3cc) = uVar4;
    *(undefined4 *)(ppGVar46 + 0x7a) = uVar5;
    *(undefined4 *)(ppGVar46 + 0x78) = uVar2;
    *(undefined4 *)((long)ppGVar46 + 0x3c4) = uVar3;
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x3d4),(CCPoint *)(param_1 + 0xa74));
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x3dc),(CCPoint *)(param_1 + 0xa7c));
    uVar2 = *(undefined4 *)(param_1 + 0xa88);
    *(CheckpointObject *)((long)ppGVar46 + 0x3e4) = param_1[0xa84];
    *(undefined4 *)(ppGVar46 + 0x7d) = uVar2;
    cocos2d::CCPoint::operator=((CCPoint *)((long)ppGVar46 + 0x3ec),(CCPoint *)(param_1 + 0xa8c));
    uVar2 = *(undefined4 *)(param_1 + 0xa94);
    uVar3 = *(undefined4 *)(param_1 + 0xa9c);
    uVar26 = *(undefined2 *)(param_1 + 0xaa0);
    *(CheckpointObject *)(ppGVar46 + 0x7f) = param_1[0xa98];
    *(undefined4 *)((long)ppGVar46 + 0x3f4) = uVar2;
    *(undefined4 *)((long)ppGVar46 + 0x3fc) = uVar3;
    *(undefined2 *)(ppGVar46 + 0x80) = uVar26;
    uVar2 = *(undefined4 *)(param_1 + 0xaa8);
    CVar17 = param_1[0xab8];
    *(CheckpointObject *)((long)ppGVar46 + 0x402) = param_1[0xaa2];
    uVar3 = *(undefined4 *)(param_1 + 0xaac);
    uVar4 = *(undefined4 *)(param_1 + 0xab0);
    uVar5 = *(undefined4 *)(param_1 + 0xab4);
    uVar6 = *(undefined4 *)(param_1 + 0xaa4);
    *(CheckpointObject *)(ppGVar46 + 0x83) = CVar17;
    uVar7 = *(undefined4 *)(param_1 + 0xabc);
    uVar8 = *(undefined4 *)(param_1 + 0xac0);
    uVar9 = *(undefined4 *)(param_1 + 0xac4);
    uVar10 = *(undefined4 *)(param_1 + 0xac8);
    uVar11 = *(undefined4 *)(param_1 + 0xacc);
    uVar12 = *(undefined4 *)(param_1 + 0xad0);
    *(undefined4 *)((long)ppGVar46 + 0x40c) = uVar3;
    *(undefined4 *)(ppGVar46 + 0x82) = uVar4;
    *(undefined4 *)((long)ppGVar46 + 0x414) = uVar5;
    *(undefined4 *)((long)ppGVar46 + 0x41c) = uVar7;
    *(undefined4 *)(ppGVar46 + 0x84) = uVar8;
    *(undefined4 *)((long)ppGVar46 + 0x424) = uVar9;
    *(undefined4 *)(ppGVar46 + 0x85) = uVar10;
    *(undefined4 *)((long)ppGVar46 + 0x42c) = uVar11;
    *(undefined4 *)((long)ppGVar46 + 0x404) = uVar6;
    *(undefined4 *)(ppGVar46 + 0x81) = uVar2;
    *(undefined4 *)(ppGVar46 + 0x86) = uVar12;
    CVar17 = param_1[0xae0];
    uVar2 = *(undefined4 *)(param_1 + 0xad4);
    uVar3 = *(undefined4 *)(param_1 + 0xae4);
    uVar4 = *(undefined4 *)(param_1 + 0xad8);
    uVar5 = *(undefined4 *)(param_1 + 0xae8);
    uVar6 = *(undefined4 *)(param_1 + 0xadc);
    CVar18 = param_1[0xaec];
    CVar19 = param_1[0xaed];
    *(CheckpointObject *)((long)ppGVar46 + 0x44e) = param_1[0xaee];
    *(CheckpointObject *)(ppGVar46 + 0x88) = CVar17;
    *(undefined4 *)((long)ppGVar46 + 0x444) = uVar3;
    *(undefined4 *)(ppGVar46 + 0x89) = uVar5;
    *(CheckpointObject *)((long)ppGVar46 + 0x44c) = CVar18;
    *(CheckpointObject *)((long)ppGVar46 + 0x44d) = CVar19;
    *(undefined4 *)((long)ppGVar46 + 0x434) = uVar2;
    *(undefined4 *)(ppGVar46 + 0x87) = uVar4;
    *(undefined4 *)((long)ppGVar46 + 0x43c) = uVar6;
  }
  if ((*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') ||
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) != '\0')) {
    bVar25 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
    if (bVar25 == 0) {
      pFVar38 = (FMODAudioEngine *)GJBaseGameLayer::pauseAudio();
      pFVar38 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar38);
      FMODAudioEngine::loadAudioState(pFVar38,(FMODAudioState *)(param_1 + 0xaf0));
      bVar25 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
    }
    else {
      pFVar38 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)(ulong)bVar25);
      pFVar38 = (FMODAudioEngine *)FMODAudioEngine::pauseAllMusic(pFVar38,false);
      pFVar38 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar38);
      FMODAudioEngine::loadAudioState(pFVar38,(FMODAudioState *)(param_1 + 0xaf0));
      bVar25 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
    }
    if (bVar25 != 0) {
      pFVar38 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)(ulong)bVar25);
      cVar28 = FMODAudioEngine::isAnyPersistentPlaying(pFVar38);
      if (cVar28 == '\0') {
        pFVar38 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)0x0);
        FMODAudioEngine::fadeInBackgroundMusic(pFVar38,_FUN_006e5100);
      }
    }
    GJBaseGameLayer::processActivatedAudioTriggers
              ((GJBaseGameLayer *)this,(float)(this->GJBaseGameLayer_data).m_gameState.m_levelTime);
    *(undefined1 *)&this[1].CCNode_data.m_sInverse.ty = 0;
    *(undefined1 *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.start + 1) = 1;
  }
  pCVar44 = *(CCDictionary **)&(this->GJBaseGameLayer_data).m_updateGroundShadows;
  pCVar47 = (this->GJBaseGameLayer_data).m_collectedItems;
  if (pCVar47 != pCVar44) {
    do {
      pCVar45 = pCVar44 + 8;
      lVar42 = *(long *)pCVar44;
      local_18 = (GameObject *)CONCAT44(local_18._4_4_,*(undefined4 *)(lVar42 + 900));
      p_Var34 = (_Hashtable *)
                std::__detail::_Map_base<>::operator[]
                          ((_Map_base<> *)(param_1 + 0x11f8),(int *)&local_18);
      std::_Hashtable<>::operator=((_Hashtable<> *)(lVar42 + 0x738),p_Var34);
      std::_Hashtable<>::operator=((_Hashtable<> *)(lVar42 + 0x770),p_Var34 + 0x38);
      pCVar44 = pCVar45;
    } while (pCVar47 != pCVar45);
  }
  if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode != false) {
    (this->GJBaseGameLayer_data).m_gameState.m_isDualMode = false;
    GJBaseGameLayer::toggleDualMode
              ((GJBaseGameLayer *)this,(GameObject *)0x0,true,(PlayerObject *)0x0,true);
  }
  PVar27 = (PlayerCheckpoint)
           UILayer::isJumpButtonPressed
                     ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
  if ((PVar27 == (PlayerCheckpoint)0x0) ||
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0')) {
    pPVar40 = *(PlayerCheckpoint **)(param_1 + 0xe70);
    pPVar35 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0;
    pPVar40[0x180] = (PlayerCheckpoint)0x0;
    PlayerObject::loadFromCheckpoint(pPVar35,pPVar40);
    if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode != false) {
      pPVar40 = *(PlayerCheckpoint **)(param_1 + 0xe78);
LAB_006e4fc0:
      PVar27 = (PlayerCheckpoint)0x0;
      goto LAB_006e4fc4;
    }
  }
  else {
    pPVar40 = *(PlayerCheckpoint **)(param_1 + 0xe70);
    if (pPVar40[0x429] == (PlayerCheckpoint)0x0) {
      pPVar35 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0;
      pPVar40[0x180] = (PlayerCheckpoint)0x1;
      PlayerObject::loadFromCheckpoint(pPVar35,pPVar40);
      cVar28 = (this->GJBaseGameLayer_data).m_gameState.m_isDualMode;
    }
    else {
      pPVar35 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0;
      pPVar40[0x180] = (PlayerCheckpoint)0x0;
      PlayerObject::loadFromCheckpoint(pPVar35,pPVar40);
      cVar28 = (this->GJBaseGameLayer_data).m_gameState.m_isDualMode;
    }
    if (cVar28 != '\0') {
      pPVar40 = *(PlayerCheckpoint **)(param_1 + 0xe78);
      if (pPVar40[0x429] != (PlayerCheckpoint)0x0) goto LAB_006e4fc0;
LAB_006e4fc4:
      pPVar35 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start;
      pPVar40[0x180] = PVar27;
      PlayerObject::loadFromCheckpoint(pPVar35,pPVar40);
      cVar28 = PlayerObject::isFlying((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
      if ((cVar28 == '\0') &&
         (*(char *)((long)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pChildren + 3) ==
          '\0')) {
        GJBaseGameLayer::enterDualMode
                  ((GameObject *)this,
                   SUB81((this->GJBaseGameLayer_data).m_gameState.m_lastActivatedPortal1,0));
      }
    }
  }
  uVar41 = 0;
  GJEffectManager::loadFromState
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,
             (EffectManagerState *)(param_1 + 0xee0));
  this_01 = *(CCArray **)(param_1 + 0x11e8);
  if (this_01 != (CCArray *)0x0) {
    for (; uVar30 = cocos2d::CCArray::count(this_01), uVar41 < uVar30; uVar41 = uVar41 + 1) {
      pGVar36 = (GradientTriggerObject *)cocos2d::CCArray::objectAtIndex(this_01,uVar41);
      GJBaseGameLayer::triggerGradientCommand((GJBaseGameLayer *)this,pGVar36);
    }
  }
  processLoadedMoveActions(this);
  loadDynamicSaveObjects(this,(vector *)(param_1 + 0xe98));
  loadActiveSaveObjects(this,(vector *)(param_1 + 0xeb0),(vector *)(param_1 + 0xec8));
  (**(code **)(this->CCCopying + 0x538))(this,(byte)param_1[0xe8c] ^ 1);
  GJBaseGameLayer::togglePlayerStreakBlend
            ((GJBaseGameLayer *)this,(this->GJBaseGameLayer_data).m_gameState.m_playerStreakBlend,
             true);
  lVar42 = *(long *)((long)&(this->PlayLayer_data).m_unk38b0 + 3);
  if (lVar42 != 0) {
    puVar39 = *(uint **)(lVar42 + 0x38);
    uVar41 = *puVar39;
    if (uVar41 != 0) {
      puVar43 = *(undefined8 **)(puVar39 + 4);
      puVar1 = puVar43 + ((ulong)uVar41 - 1);
      for (; (puVar43 <= puVar1 && (pGVar48 = (GameObject *)*puVar43, pGVar48 != (GameObject *)0x0))
          ; puVar43 = puVar43 + 1) {
        cVar28 = GJEffectManager::hasBeenTriggered
                           ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,
                            (pGVar48->GameObject_data).m_uniqueID,0);
        if (cVar28 != '\0') {
          GameObject::disableObject(pGVar48);
          iVar31 = (**(code **)(pGVar48->CCCopying + 0x6f8))(pGVar48);
          if (iVar31 == 0x1f) {
            GJBaseGameLayer::pickupItem((GJBaseGameLayer *)this,(EffectGameObject *)pGVar48);
          }
        }
      }
    }
  }
  iVar31 = 0;
LAB_006e4e14:
  do {
    cVar28 = GJEffectManager::isGroupEnabled
                       ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,iVar31
                       );
    if ((cVar28 == '\0') &&
       (lVar42 = GJBaseGameLayer::getGroup((GJBaseGameLayer *)this,iVar31), lVar42 != 0)) {
      uVar41 = **(uint **)(lVar42 + 0x38);
      if (uVar41 != 0) {
        puVar43 = *(undefined8 **)(*(uint **)(lVar42 + 0x38) + 4);
        puVar1 = puVar43 + ((ulong)uVar41 - 1);
        if (puVar43 <= puVar1) {
          do {
            pGVar48 = (GameObject *)*puVar43;
            if (pGVar48 == (GameObject *)0x0) goto LAB_006e4e08;
            puVar43 = puVar43 + 1;
            GameObject::groupWasDisabled(pGVar48);
          } while (puVar43 <= puVar1);
          iVar31 = iVar31 + 1;
          if (iVar31 == 10000) break;
          goto LAB_006e4e14;
        }
      }
    }
LAB_006e4e08:
    iVar31 = iVar31 + 1;
  } while (iVar31 != 10000);
  bVar29 = (bool)PlayerObject::getActiveMode((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
  GJBaseGameLayer::updateDualGround
            ((PlayerObject *)this,(int)(this->GJBaseGameLayer_data).m_unkdd0,bVar29,0.0);
  (this->GJBaseGameLayer_data).m_gameState.m_timeWarpRelated =
       (this->GJBaseGameLayer_data).m_gameState.m_timeWarp;
  plVar37 = (long *)cocos2d::CCDirector::sharedDirector();
  lVar42 = (**(code **)(*plVar37 + 0x80))();
  *(float *)(lVar42 + 0x38) = (this->GJBaseGameLayer_data).m_gameState.m_timeWarpRelated;
LAB_006e4ebc:
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




CheckpointObject * PlayLayer::loadLastCheckpoint(PlayLayer *this)

{
  int iVar1;
  CheckpointObject *pCVar2;
  
  iVar1 = cocos2d::CCArray::count
                    (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
  if (iVar1 != 0) {
    pCVar2 = (CheckpointObject *)
             cocos2d::CCArray::lastObject
                       (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
    loadFromCheckpoint(this,pCVar2);
    return pCVar2;
  }
  return (CheckpointObject *)0x0;
}




void PlayLayer::manualUpdateObjectColors(PlayLayer *this,GameObject *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  GameObject::updateBlendMode((GameObject *)param_1);
  pcVar2 = *(code **)(*(long *)param_1 + 0x620);
  uVar1 = GameObject::colorForMode((GameObject *)param_1,*(int *)(param_1 + 0x290),true);
  (*pcVar2)(param_1,uVar1);
  pcVar2 = *(code **)(*(long *)param_1 + 0x628);
  uVar1 = GameObject::colorForMode((GameObject *)param_1,*(int *)(param_1 + 0x294),false);
  (*pcVar2)(param_1,uVar1);
  return;
}




CheckpointObject * PlayLayer::markCheckpoint(PlayLayer *this)

{
  uint uVar1;
  int iVar2;
  CheckpointObject *this_00;
  long *plVar3;
  long lVar4;
  CCArray *this_01;
  
  if (*(char *)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pParent == '\0') {
    this_00 = (CheckpointObject *)createCheckpoint(this);
    storeCheckpoint(this,(CheckpointObject *)this_00);
    plVar3 = (long *)CheckpointObject::getObject(this_00);
    (**(code **)(*plVar3 + 0x508))();
    if (((*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0') &&
        (*(char *)&(this->GJBaseGameLayer_data).m_endPortal != '\0')) &&
       (uVar1 = cocos2d::CCArray::count
                          (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3))
       , 1 < uVar1)) {
      this_01 = *(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3);
      iVar2 = cocos2d::CCArray::count(this_01);
      lVar4 = cocos2d::CCArray::objectAtIndex(this_01,iVar2 - 2);
      GameObject::makeInvisible(*(GameObject **)(lVar4 + 0xe68));
    }
    *(undefined1 *)&this[1].CCNode_data.m_sInverse.c = 0;
    return this_00;
  }
  return (CheckpointObject *)0x0;
}




void PlayLayer::onEnterTransitionDidFinish(PlayLayer *this)

{
  long lVar1;
  
  if (*(char *)((long)&this[1].CCObject_data.m_unknown5 + 3) == '\0') {
    lVar1 = AppDelegate::get();
    *(undefined1 *)(lVar1 + 0x11) = 0;
  }
  cocos2d::CCLayer::onEnterTransitionDidFinish((CCLayer *)this);
  return;
}




void PlayLayer::onExit(PlayLayer *this)

{
  long lVar1;
  
  lVar1 = AppDelegate::get();
  if (*(char *)(lVar1 + 0x11) != '\0') {
    return;
  }
  lVar1 = cocos2d::CCDirector::sharedDirector();
  *(undefined1 *)(lVar1 + 0xaa) = 0;
  lVar1 = AppDelegate::get();
  *(undefined1 *)(lVar1 + 0x11) = 1;
  cocos2d::CCLayer::onExit((CCLayer *)this);
  return;
}




void PlayLayer::onQuit(PlayLayer *this)

{
  long *plVar1;
  long lVar2;
  GameManager *pGVar3;
  FMODAudioEngine *pFVar4;
  
  plVar1 = (long *)cocos2d::CCDirector::sharedDirector();
  lVar2 = (**(code **)(*plVar1 + 0x80))();
  *(undefined4 *)(lVar2 + 0x38) = 0x3f800000;
  pGVar3 = (GameManager *)cocos2d::CCDirector::sharedDirector();
  pGVar3[0xaa] = (GameManager)0x0;
  pGVar3 = (GameManager *)GameManager::sharedState(pGVar3);
  GameManager::didExitPlayscene(pGVar3);
  PlatformToolbox::showCursor();
  UILayer::disableMenu((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
  stopRecording(this);
  cocos2d::CCNode::stopAllActions((CCNode *)this);
  cocos2d::CCNode::unscheduleAllSelectors((CCNode *)this);
  pFVar4 = (FMODAudioEngine *)GJBaseGameLayer::resetAudio();
  pFVar4 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar4);
  pGVar3 = (GameManager *)FMODAudioEngine::unloadAllEffects(pFVar4);
  pGVar3 = (GameManager *)GameManager::sharedState(pGVar3);
  pGVar3 = (GameManager *)
           GameManager::returnToLastScene
                     (pGVar3,(GJGameLevel *)(this->GJBaseGameLayer_data).m_level);
  pGVar3 = (GameManager *)GameManager::sharedState(pGVar3);
  GameManager::fadeInMenuMusic(pGVar3);
  return;
}




void PlayLayer::opacityForObject(PlayLayer *this,GameObject *param_1)

{
  GameObject::groupOpacityMod((GameObject *)param_1);
  return;
}





void PlayLayer::optimizeColorGroups(PlayLayer *this)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  long lVar4;
  CCArray *this_00;
  GameObject *this_01;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  int local_3c;
  _Rb_tree<> a_Stack_38 [8];
  undefined4 local_30 [2];
  void *local_28;
  undefined4 *local_20;
  undefined4 *local_18;
  undefined8 local_10;
  long local_8;
  
  local_20 = local_30;
  local_8 = ___stack_chk_guard;
  uVar7 = 0;
  local_30[0] = 0;
  local_28 = (void *)0x0;
  local_10 = 0;
  local_18 = local_20;
                    
  while (uVar3 = cocos2d::CCArray::count((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity),
        uVar7 < uVar3) {
    lVar4 = cocos2d::CCArray::objectAtIndex
                      ((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity,uVar7);
    if (*(int *)(lVar4 + 0x3f4) == 0x3ee) {
      local_3c = *(int *)(lVar4 + 0x5a8);
      std::_Rb_tree<>::_M_insert_unique<int>(a_Stack_38,&local_3c);
      uVar7 = uVar7 + 1;
    }
    else {
      uVar7 = uVar7 + 1;
    }
  }
  GJBaseGameLayer::addRemapTargets((GJBaseGameLayer *)this,(set *)a_Stack_38);
  for (puVar5 = local_20; pvVar2 = local_28, puVar5 != local_30;
      puVar5 = (undefined4 *)FUN_00dfab74(puVar5)) {
    iVar1 = puVar5[8];
    this_00 = (CCArray *)GJBaseGameLayer::getGroup((GJBaseGameLayer *)this,iVar1);
    for (uVar7 = 0; uVar3 = cocos2d::CCArray::count(this_00), uVar7 < uVar3; uVar7 = uVar7 + 1) {
      this_01 = (GameObject *)cocos2d::CCArray::objectAtIndex(this_00,uVar7);
      GameObject::addToColorGroup(this_01,iVar1);
    }
  }
  while (pvVar2 != (void *)0x0) {
    std::_Rb_tree<>::_M_erase(a_Stack_38,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
    pvVar6 = *(void **)((long)pvVar2 + 0x10);
    operator.delete(pvVar2);
    pvVar2 = pvVar6;
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void PlayLayer::optimizeOpacityGroups(PlayLayer *this)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  long lVar4;
  CCArray *this_00;
  GameObject *this_01;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  int local_3c;
  _Rb_tree<> a_Stack_38 [8];
  undefined4 local_30 [2];
  void *local_28;
  undefined4 *local_20;
  undefined4 *local_18;
  undefined8 local_10;
  long local_8;
  
  local_20 = local_30;
  local_8 = ___stack_chk_guard;
  uVar7 = 0;
  local_30[0] = 0;
  local_28 = (void *)0x0;
  local_10 = 0;
  local_18 = local_20;
                    
  while (uVar3 = cocos2d::CCArray::count((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity),
        uVar7 < uVar3) {
    lVar4 = cocos2d::CCArray::objectAtIndex
                      ((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity,uVar7);
    if (*(int *)(lVar4 + 0x3f4) == 0x3ef) {
      local_3c = *(int *)(lVar4 + 0x5a8);
      std::_Rb_tree<>::_M_insert_unique<int>(a_Stack_38,&local_3c);
      uVar7 = uVar7 + 1;
    }
    else {
      uVar7 = uVar7 + 1;
    }
  }
  GJBaseGameLayer::addRemapTargets((GJBaseGameLayer *)this,(set *)a_Stack_38);
  for (puVar5 = local_20; pvVar2 = local_28, puVar5 != local_30;
      puVar5 = (undefined4 *)FUN_00dfab74(puVar5)) {
    iVar1 = puVar5[8];
    this_00 = (CCArray *)GJBaseGameLayer::getGroup((GJBaseGameLayer *)this,iVar1);
    for (uVar7 = 0; uVar3 = cocos2d::CCArray::count(this_00), uVar7 < uVar3; uVar7 = uVar7 + 1) {
      this_01 = (GameObject *)cocos2d::CCArray::objectAtIndex(this_00,uVar7);
      GameObject::addToOpacityGroup(this_01,iVar1);
    }
  }
  while (pvVar2 != (void *)0x0) {
    std::_Rb_tree<>::_M_erase(a_Stack_38,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
    pvVar6 = *(void **)((long)pvVar2 + 0x10);
    operator.delete(pvVar2);
    pvVar2 = pvVar6;
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::pauseGame(PlayLayer *this,bool param_1)

{
  char cVar1;
  long lVar2;
  GameManager *this_00;
  long *plVar3;
  undefined8 uVar4;
  
  cVar1 = canPauseGame(this);
  if ((cVar1 != '\0') && (lVar2 = AppDelegate::get(), *(char *)(lVar2 + 0x11) == '\0')) {
    (**(code **)(this->CCCopying + 0x590))(0x3f800000,this);
    *(undefined1 *)((long)&this[1].CCObject_data.m_unknown5 + 3) = 1;
    *(undefined8 *)((long)&(this->PlayLayer_data).m_activatedCheckpoint + 3) = 0;
    *(undefined8 *)&(this->PlayLayer_data).field_0x2b0 = 0;
    *(undefined8 *)((long)&(this->PlayLayer_data).m_endPosition.y + 3) = 0;
    uVar4 = getTempMilliTime();
    this[1].CCObject_data.m_uAutoReleaseCount = (int)uVar4;
    this[1].CCObject_data.m_eObjType = (int)((ulong)uVar4 >> 0x20);
    lVar2 = cocos2d::CCDirector::sharedDirector();
    *(undefined1 *)(lVar2 + 0xaa) = 0;
    PlatformToolbox::showCursor();
    GJBaseGameLayer::processQueuedButtons((GJBaseGameLayer *)this,0.0,true);
    PlayerObject::releaseAllButtons((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
    this_00 = (GameManager *)GJBaseGameLayer::pauseAudio();
    GameManager::sharedState(this_00);
    PlayerObject::releaseAllButtons((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
    UILayer::resetAllButtons
              ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
    UILayer::toggleMenuVisibility
              ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last,false);
    uVar4 = PauseLayer::create(param_1);
    plVar3 = (long *)(**(code **)(this->CCCopying + 0x1f0))(this);
    (**(code **)(*plVar3 + 0x1c0))(plVar3,uVar4,10);
    (**(code **)(this->CCCopying + 0x2c0))(this);
    return;
  }
  return;
}





void PlayLayer::playEndAnimationToPos(PlayLayer *this,CCPoint *param_2)

{
  long lVar1;
  CCPoint *pCVar2;
  CCEaseIn *pCVar3;
  CCAction *pCVar4;
  CCRotateBy *this_00;
  undefined8 uVar5;
  _ccBezierConfig *extraout_x1;
  PlayerObject *this_01;
  int iVar6;
  int iVar7;
  float fVar8;
  CCPoint local_38;
  float local_30;
  float local_2c;
  CCPoint CStack_28;
  CCPoint CStack_20;
  CCPoint CStack_18;
  CCPoint CStack_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (*(char *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start == '\0') {
    fVar8 = (this->GJBaseGameLayer_data).m_gameState.m_unkPoint6.y;
    *(undefined1 *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start = 1;
    if (fVar8 != 0.0) {
      cocos2d::CCDirector::sharedDirector();
      cocos2d::CCDirector::getWinSize();
      fVar8 = (this->GJBaseGameLayer_data).m_gameState.m_cameraZoom;
      cocos2d::CCPoint::CCPoint(&CStack_20,(local_30 * 0.5) / fVar8,(local_2c * 0.5) / fVar8);
      cocos2d::CCPoint::operator+
                (&(this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2,(CCPoint *)&CStack_20);
      cocos2d::CCPoint::operator-
                (&CStack_28,(CCPoint *)&(this->GJBaseGameLayer_data).m_gameState.m_cameraOffset);
      cocos2d::CCPoint::operator=(&CStack_28,(CCPoint *)&CStack_20);
      param_2->y = CStack_28.y;
    }
    iVar6 = 0;
    (**(code **)(this->CCCopying + 0x588))(0x3f800000,this);
    GJBaseGameLayer::updateCameraOffsetX
              ((GJBaseGameLayer *)this,(this->GJBaseGameLayer_data).m_gameState.m_cameraOffset.x,0.0
               ,0,0.0,-1,-1);
    GJBaseGameLayer::updateCameraOffsetY
              ((GJBaseGameLayer *)this,(this->GJBaseGameLayer_data).m_gameState.m_cameraOffset.y,0.0
               ,0,0.0,-1,-1);
    cocos2d::CCPoint::CCPoint(&CStack_20,(CCPoint *)param_2);
    GJBaseGameLayer::updateStaticCameraPos
              ((GJBaseGameLayer *)0x3f99999a,0x3fe66666,this,&CStack_20,0,1,0,1);
    iVar7 = 2;
    if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode == false) {
      iVar7 = 1;
    }
    do {
      if (iVar6 == 0) {
        this_01 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0;
      }
      else {
        this_01 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start;
      }
      PlayerObject::lockPlayer(this_01);
      PlayerObject::playingEndEffect(this_01);
      PlayerObject::toggleGhostEffect(this_01,1);
      lVar1 = *(long *)&(this->GJBaseGameLayer_data).m_cameraHeight;
      if ((lVar1 == 0) || (*(char *)(lVar1 + 0x540) == '\0')) {
        fVar8 = 1.0;
      }
      else {
        fVar8 = -1.0;
      }
      pCVar2 = (CCPoint *)(**(code **)(this_01->CCCopying + 0xc0))(this_01);
      cocos2d::CCPoint::CCPoint(&local_38,pCVar2);
      cocos2d::CCPoint::CCPoint(&CStack_20,fVar8 * 50.0,0.0);
      cocos2d::CCPoint::operator+(param_2,(CCPoint *)&CStack_20);
      cocos2d::CCPoint::CCPoint(&CStack_20);
      cocos2d::CCPoint::CCPoint(&CStack_18);
      cocos2d::CCPoint::CCPoint(&CStack_10);
      cocos2d::CCPoint::CCPoint(&CStack_28,local_38.x,local_38.y);
      cocos2d::CCPoint::operator=(&CStack_18,(CCPoint *)&CStack_28);
      cocos2d::CCPoint::CCPoint(&CStack_28,local_38.x + fVar8 * 40.0,local_2c + 150.0);
      cocos2d::CCPoint::operator=(&CStack_10,(CCPoint *)&CStack_28);
      cocos2d::CCPoint::CCPoint(&CStack_28,local_30,local_2c - 20.0);
      cocos2d::CCPoint::operator=(&CStack_20,(CCPoint *)&CStack_28);
      pCVar3 = (CCEaseIn *)cocos2d::CCBezierTo::create((CCBezierTo *)&CStack_20,1.0,extraout_x1);
      pCVar4 = (CCAction *)cocos2d::CCEaseIn::create(pCVar3,1.2);
      if (iVar6 == 0) {
        uVar5 = cocos2d::CCCallFunc::create
                          ((CCCallFunc *)this,(CCObject *)levelComplete,(_func_void *)0x0);
        pCVar4 = (CCAction *)cocos2d::CCSequence::create((CCFiniteTimeAction *)pCVar4,uVar5,0);
        this_00 = (CCRotateBy *)cocos2d::CCNode::runAction((CCNode *)this_01,pCVar4);
      }
      else {
        this_00 = (CCRotateBy *)cocos2d::CCNode::runAction((CCNode *)this_01,pCVar4);
      }
      iVar6 = iVar6 + 1;
      pCVar3 = (CCEaseIn *)cocos2d::CCRotateBy::create(this_00,1.0,360.0);
      pCVar4 = (CCAction *)cocos2d::CCEaseIn::create(pCVar3,1.5);
      cocos2d::CCNode::runAction((CCNode *)this_01,pCVar4);
    } while (iVar6 != iVar7);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void PlayLayer::playGravityEffect(PlayLayer *this,bool param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  CCSprite *this_00;
  CCFiniteTimeAction *pCVar4;
  undefined8 uVar5;
  CCAction *pCVar6;
  CCDelayTime *this_01;
  CCCopying *pCVar7;
  CCPoint *extraout_x1;
  undefined1 local_38;
  undefined1 uStack_36;
  undefined5 uStack_35;
  float local_30;
  float local_2c;
  CCPoint CStack_28;
  CCPoint CStack_20;
  CCPoint CStack_18;
  CCPoint CStack_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (((*(char *)&this[1].CCNode_data.m_fRotationX != '\0') ||
      (lVar3 = GameManager::sharedState((GameManager *)0x0), *(char *)(lVar3 + 0x335) != '\0')) ||
     (iVar1 = *(int *)((long)&(this->PlayLayer_data).m_pauseDelta + 7),
     *(int *)((long)&(this->PlayLayer_data).m_pauseDelta + 3) <= iVar1)) goto LAB_006d2f98;
  *(int *)((long)&(this->PlayLayer_data).m_pauseDelta + 7) = iVar1 + 1;
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  this_00 = (CCSprite *)
            cocos2d::CCArray::objectAtIndex
                      (*(CCArray **)&(this->PlayLayer_data).field_0x230,
                       *(uint *)((long)&(this->PlayLayer_data).m_unk3900 + 3));
  (**(code **)(this_00->CCCopying + 0x200))(this_00,1);
  iVar2 = *(int *)((long)&(this->PlayLayer_data).m_unk3900 + 3);
  iVar1 = 0;
  if (iVar2 < *(int *)((long)&(this->PlayLayer_data).m_pauseDelta + 3) + -1) {
    iVar1 = iVar2 + 1;
  }
  *(int *)((long)&(this->PlayLayer_data).m_unk3900 + 3) = iVar1;
  cocos2d::CCPoint::CCPoint(&CStack_28,local_30 * 0.5,local_2c + 95.0);
  cocos2d::CCPoint::CCPoint(&CStack_20,local_30 * 0.5,-95.0);
  if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pParent + 3) != '\0')
  {
    cocos2d::CCPoint::CCPoint(&CStack_10,local_30 + 95.0,local_2c * 0.5);
    cocos2d::CCPoint::operator=(&CStack_20,(CCPoint *)&CStack_10);
    cocos2d::CCPoint::CCPoint(&CStack_10,-95.0,local_2c * 0.5);
    cocos2d::CCPoint::operator=(&CStack_28,(CCPoint *)&CStack_10);
  }
  cocos2d::CCPoint::CCPoint(&CStack_18);
  cocos2d::CCPoint::CCPoint(&CStack_10);
  if (param_1) {
    cocos2d::CCPoint::operator=(&CStack_18,(CCPoint *)&CStack_20);
    cocos2d::CCPoint::operator=(&CStack_10,(CCPoint *)&CStack_28);
    uStack_36 = 0;
    local_38 = 0xff;
    pCVar7 = this_00->CCCopying;
    if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pParent + 3) != '\0'
       ) goto LAB_006d30d4;
LAB_006d31dc:
    (**(code **)(pCVar7 + 0x158))(0,this_00);
  }
  else {
    cocos2d::CCPoint::operator=(&CStack_18,(CCPoint *)&CStack_28);
    cocos2d::CCPoint::operator=(&CStack_10,(CCPoint *)&CStack_20);
    cocos2d::CCSprite::setFlipY(this_00,true);
    local_38 = 0;
    uStack_36 = 0xff;
    pCVar7 = this_00->CCCopying;
    if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pParent + 3) == '\0'
       ) goto LAB_006d31dc;
LAB_006d30d4:
    (**(code **)(pCVar7 + 0x158))(0x42b40000,this_00);
  }
  (**(code **)(this->CCCopying + 0x1c0))(this,this_00,0);
  (**(code **)(this_00->CCCopying + 0xb8))(this_00,&CStack_18);
  GravityEffectSprite::updateSpritesColor
            ((GravityEffectSprite *)this_00,
             CONCAT53(uStack_35,CONCAT12(uStack_36,CONCAT11(0xff,local_38))));
  pCVar4 = (CCFiniteTimeAction *)cocos2d::CCMoveTo::create((CCMoveTo *)&CStack_10,0.4,extraout_x1);
  uVar5 = cocos2d::CCCallFunc::create((CCCallFunc *)this_00,(CCObject *)0x208,(_func_void *)0x1);
  pCVar6 = (CCAction *)cocos2d::CCSequence::create(pCVar4,uVar5,0);
  this_01 = (CCDelayTime *)cocos2d::CCNode::runAction((CCNode *)this_00,pCVar6);
  pCVar4 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create(this_01,0.4);
  uVar5 = cocos2d::CCCallFunc::create
                    ((CCCallFunc *)this,(CCObject *)gravityEffectFinished,(_func_void *)0x0);
  pCVar6 = (CCAction *)cocos2d::CCSequence::create(pCVar4,uVar5,0);
  cocos2d::CCNode::runAction((CCNode *)this,pCVar6);
LAB_006d2f98:
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void
PlayLayer::playPlatformerEndAnimationToPos(PlayLayer *this,CCPoint *param_2,char param_3)

{
  CCGridBase *pCVar1;
  CCPoint *pCVar2;
  CCEaseIn *pCVar3;
  CCAction *pCVar4;
  CCRotateBy *this_00;
  undefined8 uVar5;
  _ccBezierConfig *extraout_x1;
  PlayerObject *this_01;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  CCPoint local_38;
  CCPoint local_30;
  CCPoint CStack_28;
  CCPoint CStack_20;
  CCPoint CStack_18;
  CCPoint CStack_10;
  long local_8;
  
  pCVar1 = this[1].CCNode_data.m_pGrid;
  local_8 = ___stack_chk_guard;
  if (pCVar1 == (CCGridBase *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = (undefined1)pCVar1[0x20].CCObject_data.m_eObjType;
  }
  iVar6 = 0;
  cocos2d::CCPoint::operator=((CCPoint *)&this[1].CCNode_data.field_0x84,param_2);
  (**(code **)(this->CCCopying + 0x588))(0x3f800000,this);
  GJBaseGameLayer::updateCameraOffsetX
            ((GJBaseGameLayer *)this,(this->GJBaseGameLayer_data).m_gameState.m_cameraOffset.x,0.0,0
             ,0.0,-1,-1);
  GJBaseGameLayer::updateCameraOffsetY
            ((GJBaseGameLayer *)this,(this->GJBaseGameLayer_data).m_gameState.m_cameraOffset.y,0.0,0
             ,0.0,-1,-1);
  iVar7 = 2;
  if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode == false) {
    iVar7 = 1;
  }
  do {
    if (iVar6 == 0) {
      this_01 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0;
    }
    else {
      this_01 = (PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start;
    }
    PlayerObject::lockPlayer(this_01);
    PlayerObject::playingEndEffect(this_01);
    if (uVar8 == 0) {
      PlayerObject::toggleGhostEffect(this_01,1);
    }
    if (param_3 == '\0') {
      pCVar2 = (CCPoint *)(**(code **)(this_01->CCCopying + 0xc0))(this_01);
      cocos2d::CCPoint::CCPoint(&local_38,pCVar2);
      cocos2d::CCPoint::CCPoint(&local_30,param_2);
      cocos2d::CCPoint::CCPoint(&CStack_20);
      cocos2d::CCPoint::CCPoint(&CStack_18);
      cocos2d::CCPoint::CCPoint(&CStack_10);
      cocos2d::CCPoint::CCPoint(&CStack_28,local_38.x,local_38.y);
      cocos2d::CCPoint::operator=(&CStack_18,(CCPoint *)&CStack_28);
      cocos2d::CCPoint::CCPoint
                (&CStack_28,local_38.x + (local_30.x - local_38.x) * 0.5,
                 local_38.y + (local_30.y - local_38.y) * 0.5);
      cocos2d::CCPoint::operator=(&CStack_10,(CCPoint *)&CStack_28);
      cocos2d::CCPoint::operator=(&CStack_20,(CCPoint *)&local_30);
      pCVar3 = (CCEaseIn *)cocos2d::CCBezierTo::create((CCBezierTo *)&CStack_20,1.0,extraout_x1);
      pCVar4 = (CCAction *)cocos2d::CCEaseIn::create(pCVar3,1.8);
      if (iVar6 == 0) {
        uVar5 = cocos2d::CCCallFunc::create
                          ((CCCallFunc *)this,(CCObject *)levelComplete,(_func_void *)0x0);
        pCVar4 = (CCAction *)cocos2d::CCSequence::create((CCFiniteTimeAction *)pCVar4,uVar5,0);
        this_00 = (CCRotateBy *)cocos2d::CCNode::runAction((CCNode *)this_01,pCVar4);
      }
      else {
        this_00 = (CCRotateBy *)cocos2d::CCNode::runAction((CCNode *)this_01,pCVar4);
      }
      pCVar3 = (CCEaseIn *)cocos2d::CCRotateBy::create(this_00,1.0,360.0);
      pCVar4 = (CCAction *)cocos2d::CCEaseIn::create(pCVar3,1.8);
      cocos2d::CCNode::runAction((CCNode *)this_01,pCVar4);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != iVar7);
  if (param_3 != '\0') {
    levelComplete(this);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::playReplay(void)

{
  return;
}




void PlayLayer::posForTime(float param_1)

{
  long in_x0;
  int *in_x4;
  
  LevelTools::posForTime
            (*(LevelTools **)(in_x0 + 0x3870),param_1,
             (CCArray *)(ulong)*(uint *)(*(long *)(in_x0 + 0xe08) + 0x14c),
             (uint)*(byte *)(*(long *)(in_x0 + 0xdf8) + 0xb40),(bool)((char)in_x0 + '@'),in_x4);
  return;
}




void PlayLayer::postUpdate(PlayLayer *this,float param_1)

{
  uint uVar1;
  long *plVar2;
  uint uVar3;
  
  if (*(char *)((long)&(this->PlayLayer_data).m_unk3918.x + 3) == '\0') {
    AudioEffectsLayer::audioStep
              (*(AudioEffectsLayer **)&(this->GJBaseGameLayer_data).m_recordInputs,param_1);
  }
  (**(code **)(this->CCCopying + 0x498))(param_1,this);
  GJBaseGameLayer::updateLevelColors((GJBaseGameLayer *)this);
  updateProgressbar(this);
  updateInfoLabel(this);
  updateEffectPositions(this);
  uVar3 = 0;
  if ((this->GJBaseGameLayer_data).m_keepGroupParents == false) {
    return;
  }
  while( true ) {
    uVar1 = cocos2d::CCArray::count((CCArray *)(this->GJBaseGameLayer_data).m_labelObjects.resize);
    if (uVar1 <= uVar3) break;
    plVar2 = (long *)cocos2d::CCArray::objectAtIndex
                               ((CCArray *)(this->GJBaseGameLayer_data).m_labelObjects.resize,uVar3)
    ;
    (**(code **)(*plVar2 + 0x148))(plVar2,0);
    uVar3 = uVar3 + 1;
  }
  onQuit(this);
  return;
}









void PlayLayer::prepareCreateObjectsFromSetup(PlayLayer *this,string *param_1)

{
  undefined3 *puVar1;
  string *psVar2;
  size_t sVar3;
  char cVar4;
  bool bVar5;
  void *pvVar6;
  bool bVar7;
  int iVar8;
  CCObject *pCVar9;
  long lVar10;
  long lVar11;
  undefined8 *puVar12;
  GameManager *pGVar13;
  undefined8 uVar14;
  int *piVar15;
  CCNode *pCVar16;
  long lVar17;
  ulong uVar18;
  ulong uVar19;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [16];
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined5 uStack_15;
  string local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined5 uStack_d;
  long local_8;
  
  local_8 = ___stack_chk_guard;
                    
  FUN_00e153b8(&local_18," ",auStack_30);
  pvVar6 = (void *)CONCAT53(uStack_15,CONCAT12(uStack_16,CONCAT11(uStack_17,local_18)));
  uVar18 = *(ulong *)((long)*(void **)param_1 + -0x18);
  uVar19 = *(ulong *)((long)pvVar6 + -0x18);
  sVar3 = uVar19;
  if (uVar18 < uVar19) {
    sVar3 = uVar18;
  }
  iVar8 = memcmp(*(void **)param_1,pvVar6,sVar3);
  if (((iVar8 != 0) || (0xffffffff < (uVar18 - uVar19) + 0x80000000)) ||
     (bVar7 = false, (int)(uVar18 - uVar19) != 0)) {
                    
    FUN_00e153b8(&local_10,&DAT_010288a0,auStack_28);
    bVar7 = true;
    pvVar6 = (void *)CONCAT53(uStack_d,CONCAT12(uStack_e,CONCAT11(uStack_f,local_10)));
    uVar18 = *(ulong *)((long)*(void **)param_1 + -0x18);
    uVar19 = *(ulong *)((long)pvVar6 + -0x18);
    sVar3 = uVar19;
    if (uVar18 < uVar19) {
      sVar3 = uVar18;
    }
    iVar8 = memcmp(*(void **)param_1,pvVar6,sVar3);
    if ((iVar8 == 0) && ((uVar18 - uVar19) + 0x80000000 < 0x100000000)) {
      bVar7 = (int)(uVar18 - uVar19) != 0;
    }
    if ((undefined8 *)((long)pvVar6 + -0x18) != &DAT_0134b6b0) {
      piVar15 = (int *)((long)pvVar6 + -8);
      do {
        iVar8 = *piVar15;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar15,0x10);
        if (bVar5) {
          *piVar15 = iVar8 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (iVar8 < 1) {
        operator.delete((undefined8 *)((long)pvVar6 + -0x18));
      }
    }
    pvVar6 = (void *)CONCAT53(uStack_15,CONCAT12(uStack_16,CONCAT11(uStack_17,local_18)));
  }
  if ((undefined8 *)((long)pvVar6 + -0x18) != &DAT_0134b6b0) {
    piVar15 = (int *)((long)pvVar6 + -8);
    do {
      iVar8 = *piVar15;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar15,0x10);
      if (bVar5) {
        *piVar15 = iVar8 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (iVar8 < 1) {
      operator.delete((undefined8 *)((long)pvVar6 + -0x18));
    }
  }
  if (bVar7) {
    uVar18 = 0;
    lVar10 = FUN_00e168e0(param_1,&DAT_00fa4078,0,1);
    uVar19 = *(ulong *)(*(long *)param_1 + -0x18);
    lVar17 = lVar10;
    while( true ) {
      FUN_00e14f84(&local_10,param_1,uVar18,lVar10);
      if ((uVar19 != uVar18) ||
         (*(long *)(CONCAT53(uStack_d,CONCAT12(uStack_e,CONCAT11(uStack_f,local_10))) + -0x18) != 0)
         ) {
        lVar10 = *(long *)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3);
        if (lVar10 == *(long *)((long)&(this->PlayLayer_data).m_unk37c0 + 3)) {
          std::vector<>::_M_emplace_back_aux<>
                    ((vector<> *)&(this->PlayLayer_data).field_0xe0,&local_10);
        }
        else {
          lVar11 = 0;
          if (lVar10 != 0) {
                    
            FUN_00e18d28(lVar10,&local_10);
            lVar11 = *(long *)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3);
          }
          *(long *)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3) = lVar11 + 8;
        }
      }
      if (lVar17 == -1) break;
      uVar18 = lVar17 + 1;
      lVar17 = FUN_00e168e0(param_1,&DAT_00fa4078,uVar18,1);
      lVar10 = CONCAT53(uStack_d,CONCAT12(uStack_e,CONCAT11(uStack_f,local_10)));
      puVar12 = (undefined8 *)(lVar10 + -0x18);
      if (puVar12 != &DAT_0134b6b0) {
        piVar15 = (int *)(lVar10 + -8);
        do {
          iVar8 = *piVar15;
          cVar4 = '\x01';
          bVar7 = (bool)ExclusiveMonitorPass(piVar15,0x10);
          if (bVar7) {
            *piVar15 = iVar8 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        if (iVar8 < 1) {
          operator.delete(puVar12);
        }
      }
      lVar10 = lVar17 - uVar18;
      if (*(ulong *)(*(long *)param_1 + -0x18) < uVar18) {
        uVar14 = FUN_00e13c5c("%s: __pos (which is %zu) > this->size() (which is %zu)",
                              "basic_string::substr",uVar18,*(ulong *)(*(long *)param_1 + -0x18));
                    
                    
        _Unwind_Resume(uVar14);
      }
    }
    lVar17 = CONCAT53(uStack_d,CONCAT12(uStack_e,CONCAT11(uStack_f,local_10)));
    puVar12 = (undefined8 *)(lVar17 + -0x18);
    if (puVar12 != &DAT_0134b6b0) {
      piVar15 = (int *)(lVar17 + -8);
      do {
        iVar8 = *piVar15;
        cVar4 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(piVar15,0x10);
        if (bVar7) {
          *piVar15 = iVar8 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (iVar8 < 1) {
        operator.delete(puVar12);
      }
    }
    pCVar9 = (CCObject *)
             LevelSettingsObject::objectFromString(*(string **)&(this->PlayLayer_data).field_0xe0);
    (this->GJBaseGameLayer_data).m_unkdd8.last = (GameObject **)pCVar9;
    cocos2d::CCObject::retain(pCVar9);
    (this->GJBaseGameLayer_data).m_unkdd8.last[0x30] =
         (GameObject *)(this->GJBaseGameLayer_data).m_level;
    GJBaseGameLayer::loadLevelSettings((GJBaseGameLayer *)this);
    pCVar16 = (this->GJBaseGameLayer_data).m_unkdd0;
    puVar1 = (undefined3 *)((long)&pCVar16[8].CCNode_data.m_fSkewY + 2);
    local_18 = *(undefined1 *)puVar1;
    uStack_17 = *(undefined1 *)((long)&pCVar16[8].CCNode_data.m_fSkewY + 3);
    uStack_16 = *(undefined1 *)&pCVar16[8].CCNode_data.m_obAnchorPointInPoints.x;
    uStack_f = *(undefined1 *)((long)&pCVar16[8].CCNode_data.m_obAnchorPointInPoints.x + 2);
    uStack_e = *(undefined1 *)((long)&pCVar16[8].CCNode_data.m_obAnchorPointInPoints.x + 3);
    psVar2 = (string *)((long)&pCVar16[8].CCNode_data.m_obAnchorPointInPoints.x + 1);
    local_10 = *psVar2;
    pGVar13 = (GameManager *)
              GJEffectManager::updateColors
                        ((GJEffectManager *)(this->GJBaseGameLayer_data).m_unkdd8.last[0x28],
                         CONCAT53(uStack_15,*puVar1),CONCAT53(uStack_d,*(undefined3 *)psVar2));
    pGVar13 = (GameManager *)GameManager::sharedState(pGVar13);
    GameManager::loadFont(pGVar13,*(int *)((this->GJBaseGameLayer_data).m_unkdd8.last + 0x2d));
  }
  pCVar9 = (CCObject *)cocos2d::CCArray::create();
  *(CCObject **)&(this->PlayLayer_data).field_0xf8 = pCVar9;
  cocos2d::CCObject::retain(pCVar9);
  lVar17 = *(long *)param_1;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_circleWaveArray + 7) = 1;
  FUN_00e174b8(param_1,0,*(undefined8 *)(lVar17 + -0x18),0);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}






void PlayLayer::prepareMusic(PlayLayer *this,bool param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  FMODAudioEngine *pFVar5;
  int *piVar6;
  float fVar7;
  double dVar8;
  long local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (((*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') ||
      (*(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) != '\0')) &&
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 2) == '\0')) {
    uVar4 = FMODAudioEngine::sharedEngine((FMODAudioEngine *)0x0);
    GJGameLevel::getAudioFileName();
                    
    FMODAudioEngine::loadMusic
              ((FMODAudioEngine *)0x3f800000,0,0x3f800000,uVar4,&local_10,
               *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6),0,0,
               *(undefined1 *)((long)(this->GJBaseGameLayer_data).m_unkdd8.last + 0x15e));
    if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
      piVar6 = (int *)(local_10 + -8);
      do {
        iVar1 = *piVar6;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar6,0x10);
        if (bVar3) {
          *piVar6 = iVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (iVar1 < 1) {
        operator.delete((undefined8 *)(local_10 + -0x18));
      }
    }
    pFVar5 = (FMODAudioEngine *)(this->GJBaseGameLayer_data).m_unkdd8.last;
    dVar8 = (this->GJBaseGameLayer_data).m_gameState.m_levelTime;
    fVar7 = *(float *)(pFVar5 + 0x158);
    if (pFVar5[0x15e] == (FMODAudioEngine)0x0) {
      pFVar5 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar5);
      FMODAudioEngine::setMusicTimeMS(pFVar5,(int)(((double)fVar7 + dVar8) * 1000.0),param_1,0);
    }
    *(undefined1 *)&this[1].CCNode_data.m_sInverse.ty = 1;
  }
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}





void PlayLayer::processCheckpoints(PlayLayer *this)

{
  int iVar1;
  char cVar2;
  GameManager *pGVar3;
  CheckpointObject *this_00;
  long lVar4;
  GameObject *this_01;
  CCPoint *pCVar5;
  long *plVar6;
  CCNode *pCVar7;
  code *pcVar8;
  CCPoint CStack_28;
  CCPoint local_20;
  undefined8 local_18;
  undefined8 local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (*(char *)&this[1].CCNode_data.m_sInverse.c != '\0') {
    *(undefined1 *)&this[1].CCNode_data.m_sInverse.c = 0;
    markCheckpoint(this);
  }
  pGVar3 = *(GameManager **)&this[1].CCNode_data.m_sInverse.d;
  if (pGVar3 != (GameManager *)0x0) {
    pGVar3 = (GameManager *)GameManager::sharedState(pGVar3);
    cVar2 = GameManager::getGameVariable(pGVar3,"0146");
    if ((cVar2 == '\0') &&
       (this_00 = (CheckpointObject *)markCheckpoint(this), this_00 != (CheckpointObject *)0x0)) {
      plVar6 = *(long **)&this[1].CCNode_data.m_sInverse.d;
      (**(code **)(*plVar6 + 0x540))(&CStack_28,plVar6);
      lVar4 = *(long *)&this[1].CCNode_data.m_sInverse.d;
      if (*(char *)(lVar4 + 0x684) == '\0') {
        iVar1 = *(int *)(lVar4 + 0x5ac);
        if ((0 < iVar1) &&
           (plVar6 = (long *)GJBaseGameLayer::tryGetMainObject((GJBaseGameLayer *)this,iVar1),
           plVar6 != (long *)0x0)) {
          (**(code **)(*plVar6 + 0x540))(&local_20);
          cocos2d::CCPoint::operator=(&CStack_28,(CCPoint *)&local_20);
        }
      }
      else {
        pCVar7 = (this->GJBaseGameLayer_data).m_unkdd0;
        pCVar5 = (CCPoint *)(**(code **)(pCVar7->CCCopying + 0xc0))(pCVar7);
        cocos2d::CCPoint::operator=(&CStack_28,pCVar5);
      }
      plVar6 = (long *)CheckpointObject::getObject(this_00);
      pcVar8 = *(code **)(*plVar6 + 0x548);
      cocos2d::CCPoint::CCPoint(&local_20,(CCPoint *)&CStack_28);
      (*pcVar8)(plVar6,&local_20);
      lVar4 = *(long *)(this_00 + 0xe70);
      cocos2d::CCPoint::CCPoint(&local_20,(CCPoint *)&CStack_28);
      cocos2d::CCPoint::operator=((CCPoint *)(lVar4 + 0x13c),(CCPoint *)&local_20);
      *(undefined1 *)(*(long *)(this_00 + 0xe70) + 0x1b0) = 1;
      this_01 = (GameObject *)CheckpointObject::getObject(this_00);
      GameObject::makeInvisible(this_01);
      lVar4 = *(long *)&this[1].CCNode_data.m_sInverse.d;
      *(undefined4 *)(this_00 + 0xe90) = *(undefined4 *)(lVar4 + 900);
      *(undefined4 *)(this_00 + 0xe94) = *(undefined4 *)(lVar4 + 0x720);
    }
    else {
      lVar4._0_4_ = this[1].CCNode_data.m_sInverse.d;
      lVar4._4_4_ = this[1].CCNode_data.m_sInverse.tx;
    }
    if (0 < *(int *)(lVar4 + 0x5a8)) {
      local_20.x = 0.0;
      local_20.y = 0.0;
      local_18 = 0;
      local_10 = 0;
                    
      (**(code **)(this->CCCopying + 0x4d8))
                (0,this,*(int *)(lVar4 + 0x5a8),0,&local_20,*(undefined4 *)(lVar4 + 900),
                 *(undefined4 *)(lVar4 + 0x678));
      if (local_20 != (CCPoint)0x0) {
        operator.delete((void *)local_20);
      }
    }
    GJBaseGameLayer::gameEventTriggered((GJBaseGameLayer *)this,0x3c,0,0);
    this[1].CCNode_data.m_sInverse.d = 0.0;
    this[1].CCNode_data.m_sInverse.tx = 0.0;
  }
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}












void PlayLayer::processCreateObjectsFromSetup(PlayLayer *this)

{
  uint uVar1;
  GJLevelType GVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  long *plVar7;
  char *pcVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  long *plVar16;
  long *plVar17;
  long *plVar18;
  undefined8 *puVar19;
  void *__dest;
  ulong uVar20;
  char *pcVar21;
  StartPosObject *this_00;
  CCObject *this_01;
  undefined8 uVar22;
  undefined8 *puVar23;
  int *piVar25;
  CCDictionary *this_02;
  GJGameLevel *pGVar26;
  long *plVar27;
  long *plVar28;
  size_t __n;
  long lVar29;
  ulong uVar30;
  ulong uVar31;
  ulong uVar32;
  float fVar33;
  float fVar34;
  ulong local_80;
  long local_78;
  char *local_50;
  long local_48;
  long local_40;
  long *local_38;
  long *local_30;
  long *local_28;
  void *local_20;
  undefined8 *local_18;
  long local_10;
  long local_8;
  undefined8 *puVar24;
  
  local_8 = ___stack_chk_guard;
  local_38 = (long *)0x0;
  local_30 = (long *)0x0;
  local_28 = (long *)0x0;
                    
  plVar16 = operator.new((void *)0x12c8);
  plVar7 = local_30;
  plVar18 = plVar16;
  plVar17 = local_38;
  if (local_38 != local_30) {
    do {
      if (plVar18 != (long *)0x0) {
        *plVar18 = *plVar17;
        *plVar17 = (long)&DAT_0134b6c8;
      }
      plVar17 = plVar17 + 1;
      plVar18 = plVar18 + 1;
    } while (local_30 != plVar17);
    plVar18 = (long *)((long)plVar16 +
                      ((long)local_30 - (long)(local_38 + 1) & 0xfffffffffffffff8U) + 8);
  }
  plVar17 = plVar18 + 0x259;
  do {
    if (plVar18 != (long *)0x0) {
      *plVar18 = (long)&DAT_0134b6c8;
    }
    plVar18 = plVar18 + 1;
    plVar28 = local_38;
    plVar27 = local_30;
  } while (plVar18 != plVar17);
joined_r0x006dd138:
  if (plVar28 != plVar7) {
    do {
      puVar19 = (undefined8 *)(*plVar28 + -0x18);
      if (puVar19 != &DAT_0134b6b0) {
        piVar25 = (int *)(*plVar28 + -8);
        do {
          iVar11 = *piVar25;
          cVar9 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar25,0x10);
          if (bVar3) {
            *piVar25 = iVar11 + -1;
            cVar9 = ExclusiveMonitorsStatus();
          }
        } while (cVar9 != '\0');
        if (iVar11 < 1) goto code_r0x006dd190;
      }
      plVar28 = plVar28 + 1;
      plVar27 = local_38;
      if (plVar7 == plVar28) break;
    } while( true );
  }
  if (plVar27 != (long *)0x0) {
    operator.delete(plVar27);
  }
  local_28 = plVar16 + 0x259;
  local_20 = (void *)0x0;
  local_18 = (undefined8 *)0x0;
  local_10 = 0;
  local_38 = plVar16;
  local_30 = plVar17;
                    
  __dest = operator.new((void *)0x12c8);
  __n = (long)local_18 - (long)local_20;
  if ((long)__n >> 3 != 0) {
    memmove(__dest,local_20,__n);
  }
  puVar19 = (undefined8 *)((long)__dest + __n);
  puVar23 = puVar19;
  do {
    puVar24 = puVar23 + 2;
    puVar23[1] = 0;
    *puVar23 = 0;
    puVar23 = puVar24;
  } while (puVar24 != puVar19 + 600);
  puVar19[600] = 0;
  puVar19 = puVar19 + 0x259;
  if (local_20 != (void *)0x0) {
    operator.delete(local_20);
  }
  local_10 = (long)__dest + 0x12c8;
  lVar29 = *(long *)&(this->PlayLayer_data).field_0xe0;
  pGVar26 = (this->GJBaseGameLayer_data).m_level;
  uVar31 = *(long *)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3) - lVar29 >> 3;
  GVar2 = (pGVar26->GJGameLevel_data).m_levelType;
  bVar3 = (pGVar26->GJGameLevel_data).m_lowDetailModeToggled;
  fVar33 = (float)(int)(float)(uVar31 / 1000) + 10.0;
  if (100.0 < fVar33) {
    fVar33 = 100.0;
  }
  fVar34 = (float)uVar31;
  iVar11 = *(int *)((long)&(this->PlayLayer_data).m_circleWaveArray + 7);
  local_80 = (ulong)iVar11;
  iVar10 = (int)(fVar34 / fVar33);
  local_20 = __dest;
  local_18 = puVar19;
  if (local_80 < uVar31) {
    iVar12 = iVar10 + iVar11;
    if (iVar11 < iVar12) {
      iVar11 = 0;
      local_78 = local_80 << 3;
      do {
        plVar17 = (long *)(lVar29 + local_78);
        lVar29 = 0;
        do {
          *(undefined8 *)((long)local_20 + lVar29) = 0;
          lVar29 = lVar29 + 8;
        } while (lVar29 != 0x12c8);
        uVar20 = FUN_00e16674(plVar17,0x2c,0);
        if (uVar20 != 0xffffffffffffffff) {
          uVar30 = (ulong)(int)*(undefined8 *)(*plVar17 + -0x18);
          bVar6 = false;
          bVar5 = true;
          uVar32 = 0;
LAB_006dd380:
          if (uVar32 != uVar30) {
            if (bVar5) {
              if (*(ulong *)(*plVar17 + -0x18) < uVar32) {
                    
                uVar22 = FUN_00e13c5c("%s: __pos (which is %zu) > this->size() (which is %zu)",
                                      "basic_string::substr",uVar32,*(ulong *)(*plVar17 + -0x18));
                    
LAB_006dd9c8:
                if (local_20 != (void *)0x0) {
                  operator.delete(local_20);
                }
                FUN_005db410(local_38,local_30);
                if (local_38 != (long *)0x0) {
                  operator.delete(local_38);
                }
                    
                _Unwind_Resume(uVar22);
              }
                    
              FUN_00e14f84(&local_50,plVar17,uVar32,uVar20 - uVar32);
              pcVar8 = local_50;
              iVar11 = atoi(local_50);
              pcVar21 = pcVar8 + -0x18;
              if (pcVar21 != (char *)&DAT_0134b6b0) {
                piVar25 = (int *)(pcVar8 + -8);
                do {
                  iVar12 = *piVar25;
                  cVar9 = '\x01';
                  bVar4 = (bool)ExclusiveMonitorPass(piVar25,0x10);
                  if (bVar4) {
                    *piVar25 = iVar12 + -1;
                    cVar9 = ExclusiveMonitorsStatus();
                  }
                } while (cVar9 != '\0');
                if (iVar12 < 1) {
                  bVar5 = (bool)(bVar5 ^ 1);
                  operator.delete(pcVar21);
                  goto LAB_006dd3d4;
                }
              }
            }
            else if (iVar11 - 1U < 600) {
              plVar18 = local_38 + iVar11;
              if (*(ulong *)(*plVar17 + -0x18) < uVar32) {
                    
                uVar22 = FUN_00e13c5c("%s: __pos (which is %zu) > this->size() (which is %zu)",
                                      "basic_string::substr",uVar32,*(ulong *)(*plVar17 + -0x18));
                    /* catch() { ... } // from try @ 006dd750 with catch @ 006dda78
                       catch() { ... } // from try @ 006dd828 with catch @ 006dda78 */
                if ((undefined8 *)(local_40 + -0x18) != &DAT_0134b6b0) {
                  FUN_006c93b8((undefined8 *)(local_40 + -0x18),&local_48);
                }
                goto LAB_006dd9c8;
              }
                    
              FUN_00e14f84(&local_48,plVar17,uVar32,uVar20 - uVar32);
                    
              FUN_00e163d4(plVar18,&local_48);
              if ((undefined8 *)(local_48 + -0x18) != &DAT_0134b6b0) {
                piVar25 = (int *)(local_48 + -8);
                do {
                  iVar12 = *piVar25;
                  cVar9 = '\x01';
                  bVar4 = (bool)ExclusiveMonitorPass(piVar25,0x10);
                  if (bVar4) {
                    *piVar25 = iVar12 + -1;
                    cVar9 = ExclusiveMonitorsStatus();
                  }
                } while (cVar9 != '\0');
                if (iVar12 < 1) {
                  operator.delete((undefined8 *)(local_48 + -0x18));
                }
              }
              bVar5 = (bool)(bVar5 ^ 1);
              *(PlayLayer **)((long)local_20 + (long)iVar11 * 8) = this;
              goto LAB_006dd3d4;
            }
            bVar5 = (bool)(bVar5 ^ 1);
          }
LAB_006dd3d4:
          if (!bVar6) {
            uVar32 = uVar20 + 1;
            uVar20 = FUN_00e16674(plVar17,0x2c,uVar32);
            if (uVar20 == 0xffffffffffffffff) {
              bVar6 = true;
              uVar20 = uVar30;
            }
            goto LAB_006dd380;
          }
        }
                    
        this_00 = (StartPosObject *)
                  GameObject::objectFromVector
                            ((vector *)&local_38,(vector *)&local_20,(GJBaseGameLayer *)this,bVar3);
        if (this_00 != (StartPosObject *)0x0) {
          iVar12 = (this_00->GameObject_data).m_objectID;
          if (iVar12 == 0x1f) {
                    
            FUN_00e18d28((string *)&local_40,plVar17);
                    
            StartPosObject::loadSettingsFromString(this_00,(string *)&local_40);
            if ((undefined8 *)(local_40 + -0x18) != &DAT_0134b6b0) {
              piVar25 = (int *)(local_40 + -8);
              do {
                iVar12 = *piVar25;
                cVar9 = '\x01';
                bVar5 = (bool)ExclusiveMonitorPass(piVar25,0x10);
                if (bVar5) {
                  *piVar25 = iVar12 + -1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (iVar12 < 1) {
                operator.delete((undefined8 *)(local_40 + -0x18));
              }
            }
          }
          else if (iVar12 == 0x811) {
                    
            ParticleGameObject::updateParticleStruct((ParticleGameObject *)this_00);
          }
                    
          iVar12 = (**(code **)(this_00->CCCopying + 0x6f8))(this_00);
          if ((iVar12 != 0x16) || (GVar2 == Main)) {
            fVar33 = (float)(this_00->GameObject_data).m_mainColorKeyIndex;
            if ((int)fVar33 < 1) {
                    
              cVar9 = GameObject::hasSecondaryColor((GameObject *)this_00);
              uVar14 = 0;
              uVar15 = 2;
              if (cVar9 == '\0') {
                uVar15 = 1;
              }
              do {
                uVar1 = (uVar14 ^ 1) & 1;
                    
                GameObject::getColorKey(SUB81(this_00,0),SUB41(uVar1,0));
                    
                lVar29 = cocos2d::CCDictionary::objectForKey
                                   (*(CCDictionary **)&this[1].CCNode_data.m_fSkewY,
                                    (string *)&local_40);
                if (lVar29 == 0) {
                  fVar33 = this[1].CCNode_data.m_sInverse.b;
                  this_02 = *(CCDictionary **)&this[1].CCNode_data.m_fSkewY;
                  this_01 = operator.new((void *)0x40);
                    
                  cocos2d::CCObject::CCObject(this_01);
                  *(float *)&this_01[1].CCCopying = fVar33;
                  this_01->CCCopying = (CCCopying *)cocos2d::CCInteger::vftable;
                    
                  cocos2d::CCObject::autorelease(this_01);
                  cocos2d::CCDictionary::setObject(this_02,(CCObject *)this_01,(string *)&local_40);
                  this[1].CCNode_data.m_sInverse.b =
                       (float)((int)this[1].CCNode_data.m_sInverse.b + 1);
                }
                else {
                  lVar29 = cocos2d::CCDictionary::objectForKey
                                     (*(CCDictionary **)&this[1].CCNode_data.m_fSkewY,
                                      (string *)&local_40);
                  fVar33 = *(float *)(lVar29 + 0x38);
                }
                if (uVar1 == 0) {
                  (this_00->GameObject_data).m_detailColorKeyIndex = (int)fVar33;
                }
                else {
                  (this_00->GameObject_data).m_mainColorKeyIndex = (int)fVar33;
                }
                if ((undefined8 *)(local_40 + -0x18) != &DAT_0134b6b0) {
                  piVar25 = (int *)(local_40 + -8);
                  do {
                    iVar12 = *piVar25;
                    cVar9 = '\x01';
                    bVar5 = (bool)ExclusiveMonitorPass(piVar25,0x10);
                    if (bVar5) {
                      *piVar25 = iVar12 + -1;
                      cVar9 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar9 != '\0');
                  if (iVar12 < 1) {
                    operator.delete((undefined8 *)(local_40 + -0x18));
                  }
                }
                uVar14 = uVar14 + 1;
              } while (uVar14 != uVar15);
            }
            else {
              fVar34 = this[1].CCNode_data.m_sInverse.b;
              if ((int)fVar34 < (int)fVar33) {
                this[1].CCNode_data.m_sInverse.b = fVar33;
                fVar34 = fVar33;
              }
              fVar33 = (float)(this_00->GameObject_data).m_detailColorKeyIndex;
              if ((int)fVar34 < (int)fVar33) {
                this[1].CCNode_data.m_sInverse.b = fVar33;
              }
            }
                    
            iVar12 = (**(code **)(this_00->CCCopying + 0x6f8))(this_00);
            if (iVar12 == 0x1f) {
                    
              uVar14 = cocos2d::CCArray::count(*(CCArray **)&(this->PlayLayer_data).field_0xf8);
              if (uVar14 < 3) {
                    
                cocos2d::CCArray::addObject
                          (*(CCArray **)&(this->PlayLayer_data).field_0xf8,(CCObject *)this_00);
                    
                addObject(this,(GameObject *)this_00);
              }
            }
            else {
                    
              addObject(this,(GameObject *)this_00);
            }
          }
        }
                    
        FUN_00e174b8(plVar17,0,*(undefined8 *)(*plVar17 + -0x18),0);
        iVar13 = (int)local_80;
        if (local_80 == uVar31 - 1) {
          uVar31 = *(long *)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3) -
                   *(long *)&(this->PlayLayer_data).field_0xe0 >> 3;
          iVar12 = iVar10 + *(int *)((long)&(this->PlayLayer_data).m_circleWaveArray + 7);
          fVar34 = (float)uVar31;
          break;
        }
        local_80 = local_80 + 1;
        local_78 = local_78 + 8;
        iVar12 = iVar10 + *(int *)((long)&(this->PlayLayer_data).m_circleWaveArray + 7);
        if (iVar12 <= iVar13 + 1) goto LAB_006dd964;
        lVar29 = *(long *)&(this->PlayLayer_data).field_0xe0;
      } while( true );
    }
  }
  else {
    iVar12 = iVar10 + iVar11;
  }
LAB_006dd868:
  *(int *)((long)&(this->PlayLayer_data).m_circleWaveArray + 7) = iVar12;
  fVar34 = (float)(iVar12 + -1) / fVar34;
  if (1.0 < fVar34) {
    fVar34 = 1.0;
  }
  *(float *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 4) = fVar34;
  if (uVar31 <= (ulong)(long)iVar12) {
                    
    createObjectsFromSetupFinished(this);
    *(undefined4 *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 4) = 0x3f800000;
                    
    setupHasCompleted(this);
  }
  plVar18 = local_38;
  plVar7 = local_30;
  plVar16 = local_30;
  plVar17 = local_30;
  if (local_20 != (void *)0x0) {
    operator.delete(local_20);
    plVar18 = local_38;
    plVar7 = local_30;
    plVar16 = local_30;
    plVar17 = local_30;
  }
  do {
    while( true ) {
      local_30 = plVar16;
      plVar16 = local_30;
      if (plVar18 == local_30) {
        local_30 = plVar17;
        if (plVar7 != (long *)0x0) {
          operator.delete(plVar7);
        }
        if (local_8 == ___stack_chk_guard) {
          return;
        }
                    
        __stack_chk_fail();
      }
      puVar19 = (undefined8 *)(*plVar18 + -0x18);
      if (puVar19 != &DAT_0134b6b0) break;
LAB_006dd8c8:
      plVar18 = plVar18 + 1;
      plVar7 = local_38;
    }
    piVar25 = (int *)(*plVar18 + -8);
    do {
      iVar11 = *piVar25;
      cVar9 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar25,0x10);
      if (bVar3) {
        *piVar25 = iVar11 + -1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    if (0 < iVar11) goto LAB_006dd8c8;
    local_30 = plVar17;
    operator.delete(puVar19);
    plVar18 = plVar18 + 1;
    plVar7 = local_38;
    plVar17 = local_30;
  } while( true );
code_r0x006dd190:
  operator.delete(puVar19);
  plVar28 = plVar28 + 1;
  plVar27 = local_38;
  goto joined_r0x006dd138;
LAB_006dd964:
  uVar31 = *(long *)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3) -
           *(long *)&(this->PlayLayer_data).field_0xe0 >> 3;
  fVar34 = (float)uVar31;
  goto LAB_006dd868;
}





void PlayLayer::processLoadedMoveActions(PlayLayer *this)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  void *this_00;
  CCCopying *pCVar6;
  GameObject *this_01;
  long *plVar7;
  CCPoint aCStack_48 [8];
  undefined8 *local_40;
  ulong local_38;
  long *local_30;
  undefined8 local_28;
  undefined4 local_20 [2];
  undefined8 local_18;
  undefined8 local_10;
  long local_8;
  
  local_30 = (long *)0x0;
  local_8 = ___stack_chk_guard;
  local_28 = 0;
  local_20[0] = 0x3f800000;
  local_18 = 0;
  local_38 = FUN_00e146dc(local_20,10);
  if (local_38 == 1) {
    local_10 = 0;
    puVar3 = &local_10;
  }
  else {
    if (0x1fffffffffffffff < local_38) {
      uVar5 = FUN_00e1383c();
                    
      std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_40);
                    
      _Unwind_Resume(uVar5);
    }
    this_00 = (void *)(local_38 << 3);
    puVar3 = operator.new(this_00);
    memset(puVar3,0,(size_t)this_00);
  }
  local_40 = puVar3;
                    
  GJEffectManager::getLoadedMoveOffset
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,
             (unordered_map *)&local_40);
  if (local_30 != (long *)0x0) {
    plVar7 = local_30;
    do {
      lVar4 = GJBaseGameLayer::getGroup((GJBaseGameLayer *)this,(int)plVar7[1]);
      if (lVar4 != 0) {
        uVar2 = **(uint **)(lVar4 + 0x38);
        if (uVar2 != 0) {
          puVar3 = *(undefined8 **)(*(uint **)(lVar4 + 0x38) + 4);
          puVar1 = puVar3 + ((ulong)uVar2 - 1);
          for (; (puVar3 <= puVar1 &&
                 (this_01 = (GameObject *)*puVar3, this_01 != (GameObject *)0x0));
              puVar3 = puVar3 + 1) {
            if ((this_01->GameObject_data).m_unk530 == false) {
              GameObject::addToTempOffset(this_01,(double)plVar7[2],(double)plVar7[3]);
              (**(code **)(this_01->CCCopying + 0x6e0))(this_01,1);
              pCVar6 = this_01->CCCopying;
              (this_01->GameObject_data).m_isDirty = true;
              (**(code **)(pCVar6 + 0x6f0))(this_01,1);
              (**(code **)(this->CCCopying + 0x528))(this,this_01);
              pCVar6 = this_01->CCCopying;
              (this_01->GameObject_data).m_unk4C4 = -1;
              (**(code **)(pCVar6 + 0x540))(aCStack_48,this_01);
              GameObject::setLastPosition(this_01,aCStack_48);
            }
          }
        }
      }
      plVar7 = (long *)*plVar7;
    } while (plVar7 != (long *)0x0);
  }
  std::_Hashtable<>::~_Hashtable((_Hashtable<> *)&local_40);
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}




void PlayLayer::queueCheckpoint(PlayLayer *this)

{
  *(undefined1 *)&this[1].CCNode_data.m_sInverse.c = 1;
  return;
}




void PlayLayer::removeAllCheckpoints(PlayLayer *this)

{
  int iVar1;
  
  while (iVar1 = cocos2d::CCArray::count
                           (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3)
                           ), iVar1 != 0) {
    removeCheckpoint(this,false);
  }
  return;
}




void PlayLayer::removeAllObjects(PlayLayer *this)

{
  undefined8 *puVar1;
  uint uVar2;
  UILayer *this_00;
  CCArray *this_01;
  CCNode *pCVar3;
  GameObject **ppGVar4;
  long *plVar5;
  undefined8 *puVar6;
  
  this_00 = (UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last;
  (this->PlayLayer_data).m_skipAudioStep = false;
  UILayer::disableMenu(this_00);
  pCVar3 = (this->GJBaseGameLayer_data).m_unkdd0;
  (**(code **)(pCVar3->CCCopying + 0x510))(pCVar3,1);
  PlayerObject::deactivateParticle((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
  PlayerObject::deactivateStreak((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0,true);
  PlayerObject::toggleGhostEffect((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0,0);
  if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode != false) {
    ppGVar4 = (this->GJBaseGameLayer_data).m_unkdd8.start;
    (**(code **)&((*ppGVar4)->GameObject_data).m_pixelScaleX)(ppGVar4,1);
    PlayerObject::deactivateParticle((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start);
    PlayerObject::deactivateStreak((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start,true)
    ;
    PlayerObject::toggleGhostEffect((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start,0);
  }
  this_01 = (CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity;
  if (this_01 != (CCArray *)0x0) {
    uVar2 = *(uint *)&(*(GameObject **)(this_01 + 0x38))->CCCopying;
    if (uVar2 != 0) {
      puVar6 = *(undefined8 **)&((*(GameObject **)(this_01 + 0x38))->CCObject_data).m_nTag;
      puVar1 = puVar6 + ((ulong)uVar2 - 1);
      if ((puVar6 <= puVar1) && (plVar5 = (long *)*puVar6, plVar5 != (long *)0x0)) {
        do {
          puVar6 = puVar6 + 1;
          (**(code **)(*plVar5 + 0x510))(plVar5,1);
          (**(code **)(*plVar5 + 0x2d0))(plVar5);
          if (puVar1 < puVar6) break;
          plVar5 = (long *)*puVar6;
        } while (plVar5 != (long *)0x0);
        this_01 = (CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity;
      }
    }
  }
  cocos2d::CCArray::removeAllObjects(this_01);
  return;
}




void PlayLayer::removeCheckpoint(PlayLayer *this,bool param_1)

{
  int iVar1;
  CCArray *this_00;
  CheckpointObject *pCVar2;
  GameObject *pGVar3;
  long lVar4;
  
  iVar1 = cocos2d::CCArray::count
                    (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
  if (iVar1 != 0) {
    this_00 = *(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3);
    if (param_1) {
      pCVar2 = (CheckpointObject *)cocos2d::CCArray::objectAtIndex(this_00,0);
      pGVar3 = (GameObject *)CheckpointObject::getObject(pCVar2);
      GJBaseGameLayer::removeObjectFromSection((GJBaseGameLayer *)this,(GameObject *)pGVar3);
      GameObject::removeGlow(pGVar3);
      (**(code **)(pGVar3->CCCopying + 0x208))(pGVar3);
      cocos2d::CCArray::removeObjectAtIndex
                (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3),0,true);
      return;
    }
    pCVar2 = (CheckpointObject *)cocos2d::CCArray::lastObject(this_00);
    pGVar3 = (GameObject *)CheckpointObject::getObject(pCVar2);
    GJBaseGameLayer::removeObjectFromSection((GJBaseGameLayer *)this,(GameObject *)pGVar3);
    GameObject::removeGlow(pGVar3);
    (**(code **)(pGVar3->CCCopying + 0x208))(pGVar3);
    cocos2d::CCArray::removeLastObject
              (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3),true);
    if (((*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0') &&
        (*(char *)&(this->GJBaseGameLayer_data).m_endPortal != '\0')) &&
       (iVar1 = cocos2d::CCArray::count
                          (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3))
       , iVar1 != 0)) {
      lVar4 = cocos2d::CCArray::lastObject
                        (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
      GameObject::makeVisible(*(GameObject **)(lVar4 + 0xe68));
      *(int *)(lVar4 + 0x1230) = (this->GJBaseGameLayer_data).m_gameState.m_commandIndex;
    }
  }
  return;
}




void PlayLayer::removeFromGroupOld(PlayLayer *this,GameObject *param_1)

{
  int iVar1;
  int iVar2;
  CCArray *this_00;
  
  iVar2 = 0;
  if (0 < *(short *)(param_1 + 0x480)) {
    do {
      iVar1 = iVar2 + 1;
      iVar2 = GameObject::getGroupID((GameObject *)param_1,iVar2);
      this_00 = (CCArray *)GJBaseGameLayer::getGroup((GJBaseGameLayer *)this,iVar2);
      cocos2d::CCArray::removeObject(this_00,(CCObject *)param_1,true);
      iVar2 = iVar1;
    } while (iVar1 < *(short *)(param_1 + 0x480));
  }
  return;
}






void PlayLayer::resetLevel(PlayLayer *this)

{
  undefined8 *puVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  FMODAudioEngine *pFVar9;
  PlayerButtonCommand *pPVar10;
  UILayer *pUVar11;
  GameObject *pGVar12;
  CCPoint *pCVar13;
  GameStatsManager *pGVar14;
  GameManager *this_00;
  long lVar15;
  CCFiniteTimeAction *pCVar16;
  undefined8 uVar17;
  CCAction *pCVar18;
  int iVar19;
  long *plVar20;
  ulong uVar21;
  uint *puVar22;
  CheckpointObject *pCVar23;
  long lVar24;
  code *pcVar25;
  CCCopying *pCVar26;
  int *piVar27;
  CCNode *pCVar28;
  GameObject **ppGVar29;
  undefined8 *puVar30;
  GameObject *pGVar31;
  uint uVar32;
  GJGameLevel *pGVar33;
  double dVar34;
  float fVar35;
  float local_30;
  float local_2c;
  float local_28 [2];
  undefined1 local_20 [8];
  long local_18;
  undefined8 local_10;
  long local_8;
  
  bVar2 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 1);
  pFVar9 = (FMODAudioEngine *)(ulong)bVar2;
  local_8 = ___stack_chk_guard;
  if ((bVar2 == 0) &&
     ((*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0' ||
      (*(char *)&(this->GJBaseGameLayer_data).m_endPortal != '\0')))) {
LAB_006e5858:
    pFVar9 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar9);
    FMODAudioEngine::stopAllEffects(pFVar9);
    if ((*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') ||
       (*(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) != '\0')) {
      bVar2 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
      if (bVar2 == 0) {
        GJBaseGameLayer::pauseAudio();
      }
      else {
        pFVar9 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)(ulong)bVar2);
        FMODAudioEngine::pauseAllMusic(pFVar9,false);
      }
    }
  }
  else {
    if ((this->PlayLayer_data).field_0x16e == '\0') {
      cVar6 = (this->GJBaseGameLayer_data).m_ignoreDamage;
LAB_006e5850:
      (this->PlayLayer_data).field_0x16e = cVar6;
    }
    else {
      cVar6 = (this->GJBaseGameLayer_data).m_ignoreDamage;
      if ((bool)cVar6 != false) goto LAB_006e5850;
      (this->PlayLayer_data).field_0x16e = 0;
      toggleIgnoreDamage(this,false);
      pFVar9 = (FMODAudioEngine *)
               (ulong)*(byte *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 1);
    }
    if ((int)pFVar9 == 0) goto LAB_006e5858;
  }
  GJBaseGameLayer::preResumeGame((GJBaseGameLayer *)this);
  dwTickStartp = clock();
  GJBaseGameLayer::resetLevelVariables((GJBaseGameLayer *)this);
  if (((this->PlayLayer_data).m_unk376d != false) && (cVar6 = shouldDebugDraw(this), cVar6 == '\0'))
  {
    toggleDebugDraw(this);
  }
  (this->GJBaseGameLayer_data).m_gameState.m_commandIndex = 0;
  (this->GJBaseGameLayer_data).m_gameState.m_currentProgress = 0;
  *(undefined4 *)((long)&(this->GJBaseGameLayer_data).m_queuedReplayButtons.start + 4) = 0;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_hazardCollisionObjectsCount + 1) = 1;
  this[1].CCNode_data.m_sInverse.d = 0.0;
  this[1].CCNode_data.m_sInverse.tx = 0.0;
  *(undefined1 *)&this[1].CCNode_data.m_sInverse.c = 0;
  cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_hazardCollisionObjects.last;
  *(undefined4 *)&(this->GJBaseGameLayer_data).m_queuedReplayButtons.start = 0;
  *(undefined4 *)&(this->GJBaseGameLayer_data).m_queuedButtons.capacity = 0;
  if ((cVar6 == '\0') ||
     (pPVar10 = (this->GJBaseGameLayer_data).m_queuedRecordedButtons.capacity,
     pPVar10 == (PlayerButtonCommand *)0x0)) {
    gettimeofday((timeval *)local_20,(__timezone_ptr_t)0x0);
    pPVar10 = (PlayerButtonCommand *)(local_18 * (long)local_20);
    (this->GJBaseGameLayer_data).m_queuedRecordedButtons.start = pPVar10;
  }
  else {
    (this->GJBaseGameLayer_data).m_queuedRecordedButtons.start = pPVar10;
  }
  GameToolbox::fast_srand((ulong)pPVar10);
  *(undefined4 *)&(this->GJBaseGameLayer_data).m_coinsCollected = 0;
  *(undefined1 *)((long)&(this->PlayLayer_data).m_speedObjects + 1) = 0;
  pUVar11 = (UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_checkpointArray + 3) = 0;
  UILayer::toggleMenuVisibility(pUVar11,true);
  plVar20 = *(long **)&(this->GJBaseGameLayer_data).m_cameraHeight;
  *(undefined1 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.last + 1) = 0;
  *(undefined1 *)&(this->PlayLayer_data).m_keyPulses.m_bits.last = 0;
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start = 0;
  if (plVar20 != (long *)0x0) {
    lVar24 = *plVar20;
    *(undefined1 *)((long)&(this->PlayLayer_data).m_blendingColors.size + 3) = 0;
    *(undefined1 *)(plVar20 + 0xa8) = 0;
    pcVar25 = *(code **)(lVar24 + 0x80);
    *(undefined1 *)((long)plVar20 + 0x541) = 0;
    (*pcVar25)(0x3f800000,plVar20);
    plVar20 = *(long **)&(this->GJBaseGameLayer_data).m_cameraHeight;
    fVar35 = *(float *)((long)&(this->PlayLayer_data).m_blendingColors.size + 7);
    pcVar25 = *(code **)(*plVar20 + 0x548);
    *(float *)&(this->GJBaseGameLayer_data).m_started = fVar35;
    cocos2d::CCPoint::CCPoint((CCPoint *)local_20,fVar35,225.0);
    (*pcVar25)(plVar20,(CCPoint *)local_20);
    GJBaseGameLayer::reorderObjectSection
              ((GJBaseGameLayer *)this,*(GameObject **)&(this->GJBaseGameLayer_data).m_cameraHeight)
    ;
    plVar20 = *(long **)&(this->GJBaseGameLayer_data).m_cameraHeight;
    (**(code **)(*plVar20 + 0x510))(plVar20,1);
  }
  *(undefined1 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.last + 7) = 0;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.capacity + 3) = 0;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.capacity + 7) = 0;
  *(undefined1 *)((long)&(this->PlayLayer_data).m_nextColorKey + 3) = 0;
  *(undefined1 *)((long)&(this->PlayLayer_data).m_keyOpacities.capacity + 7) = 0;
  FUN_00e1798c(&(this->GJBaseGameLayer_data).m_queuedButtons,&DAT_010288a0,0);
  *(undefined4 *)((long)&(this->PlayLayer_data).m_pauseDelta + 7) = 0;
  pUVar11 = (UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last;
  this[1].CCObject_data.m_uOrderOfArrival = 0;
  UILayer::enableMenu(pUVar11);
  GJBaseGameLayer::resetActiveEnterEffects((GJBaseGameLayer *)this);
  if (*(double *)&this[1].CCObject_data.m_nTag < *(double *)&this[1].CCObject_data) {
    *(double *)&this[1].CCObject_data.m_nTag = *(double *)&this[1].CCObject_data;
  }
  pCVar26 = this->CCCopying;
  (this->GJBaseGameLayer_data).m_particleSystemLimit = 0;
  uVar32 = 0;
  pcVar25 = *(code **)(pCVar26 + 0x4f8);
  this[1].CCObject_data.m_uID = 0;
  this[1].CCObject_data.m_nLuaID = 0;
  this[1].CCObject_data.m_uIndexInArray = 0;
  this[1].CCObject_data.m_nChildIndex = 0;
  this[1].CCObject_data.m_unknown2 = 0;
  this[1].CCObject_data.m_nZOrder = 0;
  (*pcVar25)(this,0);
  iVar7 = cocos2d::CCArray::count((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity);
  if (iVar7 != 0) {
    do {
      pGVar12 = (GameObject *)
                cocos2d::CCArray::objectAtIndex
                          ((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity,uVar32);
      (**(code **)(*(long *)pGVar12 + 0x540))(&local_30);
      (**(code **)(*(long *)pGVar12 + 0x4f8))(pGVar12);
      if (-1 < *(int *)(pGVar12 + 0x274)) {
        dVar34 = *(double *)(pGVar12 + 0x3a0);
        if (dVar34 <= 0.0) {
          iVar7 = 0;
LAB_006e53e8:
          dVar34 = *(double *)(pGVar12 + 0x3a8);
          if (0.0 < dVar34) goto LAB_006e53f4;
LAB_006e58ec:
          iVar19 = 0;
        }
        else {
          if (10000000.0 <= dVar34) {
            iVar7 = (int)(*(float *)&(this->GJBaseGameLayer_data).m_debugDrawPoints * 1e+07);
            goto LAB_006e53e8;
          }
          iVar7 = (int)(dVar34 * (double)*(float *)&(this->GJBaseGameLayer_data).m_debugDrawPoints);
          dVar34 = *(double *)(pGVar12 + 0x3a8);
          if (dVar34 <= 0.0) goto LAB_006e58ec;
LAB_006e53f4:
          if (10000000.0 <= dVar34) {
            iVar19 = (int)(*(float *)((long)&(this->GJBaseGameLayer_data).m_debugDrawPoints + 4) *
                          1e+07);
          }
          else {
            iVar19 = (int)(dVar34 * (double)*(float *)((long)&(this->GJBaseGameLayer_data).
                                                              m_debugDrawPoints + 4));
          }
        }
        if ((iVar7 != *(int *)(pGVar12 + 0x274)) || (iVar19 != *(int *)(pGVar12 + 0x278))) {
          GJBaseGameLayer::reorderObjectSection((GJBaseGameLayer *)this,pGVar12);
          if ((*(int *)&(this->GJBaseGameLayer_data).m_customParticles < *(int *)(pGVar12 + 0x274))
             || (((*(int *)(pGVar12 + 0x274) <
                   *(int *)((long)&(this->GJBaseGameLayer_data).m_particlesDict + 4) ||
                  (*(int *)&(this->GJBaseGameLayer_data).m_unclaimedParticles <
                   *(int *)(pGVar12 + 0x278))) ||
                 (*(int *)(pGVar12 + 0x278) <
                  *(int *)((long)&(this->GJBaseGameLayer_data).m_customParticles + 4))))) {
            (**(code **)(*(long *)pGVar12 + 0x510))(pGVar12,1);
          }
        }
      }
      fVar35 = local_30;
      (**(code **)(*(long *)pGVar12 + 0x540))(local_28,pGVar12);
      fVar4 = local_2c;
      if (fVar35 == local_28[0]) {
                    
        (**(code **)(*(long *)pGVar12 + 0x540))((CCPoint *)local_20,pGVar12);
        if (fVar4 != (float)local_20._4_4_) goto LAB_006e548c;
      }
      else {
LAB_006e548c:
        pGVar12[0x338] = (GameObject)0x1;
        (**(code **)(*(long *)pGVar12 + 0x6e0))(pGVar12,1);
        (**(code **)(*(long *)pGVar12 + 0x6f0))(pGVar12,1);
      }
      uVar32 = uVar32 + 1;
      uVar8 = cocos2d::CCArray::count((CCArray *)(this->GJBaseGameLayer_data).m_unkdd8.capacity);
    } while (uVar32 < uVar8);
  }
  AudioEffectsLayer::resetAudioVars
            (*(AudioEffectsLayer **)&(this->GJBaseGameLayer_data).m_recordInputs);
  loadDefaultColors(this);
  lVar24 = loadLastCheckpoint(this);
  if (*(char *)&(this->GJBaseGameLayer_data).m_hazardCollisionObjects.last == '\0') {
    GJEffectManager::getPersistentStateString();
                    
    FUN_00e18ea8(&(this->GJBaseGameLayer_data).m_savePositionValues.factor,(CCPoint *)local_20);
    if ((undefined8 *)((long)local_20 + -0x18) != &DAT_0134b6b0) {
      piVar27 = (int *)((long)local_20 + -8);
      do {
        iVar7 = *piVar27;
        cVar6 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar27,0x10);
        if (bVar5) {
          *piVar27 = iVar7 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      if (iVar7 < 1) {
        operator.delete((undefined8 *)((long)local_20 + -0x18));
      }
    }
  }
  GJEffectManager::resetUsedItemState
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4);
  if (lVar24 == 0) {
    *(undefined4 *)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity = 0;
    *(undefined4 *)((long)&(this->GJBaseGameLayer_data).m_sectionSizes.capacity + 4) = 0;
    (this->GJBaseGameLayer_data).m_sectionSizes.last = (vector<int> **)0x0;
    GJBaseGameLayer::resetRecord((GJBaseGameLayer *)this,0,false);
    ppGVar29 = (this->GJBaseGameLayer_data).m_hazardCollisionObjects.start;
    (this->GJBaseGameLayer_data).m_queuedRecordedButtons.last =
         (this->GJBaseGameLayer_data).m_queuedRecordedButtons.start;
    if (ppGVar29 == (GameObject **)0x0) {
      pGVar31 = (GameObject *)(this->GJBaseGameLayer_data).m_unkdd8.last;
    }
    else {
      pCVar23 = *(CheckpointObject **)((long)&(this->PlayLayer_data).m_blendingColors.factor + 3);
      if (pCVar23 != (CheckpointObject *)0x0) {
        loadFromCheckpoint(this,pCVar23);
        goto LAB_006e553c;
      }
      pGVar31 = ppGVar29[0xe4];
    }
    GJBaseGameLayer::setupLevelStart((GJBaseGameLayer *)this,(LevelSettingsObject *)pGVar31);
  }
  else {
    cVar6 = *(char *)&(this->GJBaseGameLayer_data).m_hazardCollisionObjects.last;
    *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.capacity + 1) = 0;
    if (cVar6 == '\0') {
      GJBaseGameLayer::resetRecord
                ((GJBaseGameLayer *)this,(this->GJBaseGameLayer_data).m_gameState.m_unkUint4,false);
    }
  }
LAB_006e553c:
  pCVar28 = (this->GJBaseGameLayer_data).m_unkdd0;
  pCVar13 = (CCPoint *)(**(code **)(pCVar28->CCCopying + 0xc0))(pCVar28);
  cocos2d::CCPoint::CCPoint((CCPoint *)local_20,pCVar13);
  cocos2d::CCPoint::operator=
            ((CCPoint *)&pCVar28[8].CCNode_data.m_obAnchorPointInPoints.y,(CCPoint *)local_20);
  if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode == false) {
    ppGVar29 = (this->GJBaseGameLayer_data).m_unkdd8.start;
    (**(code **)&((*ppGVar29)->CCNode_data).m_sInverse.ty)(ppGVar29,&DAT_01341eb0);
    ppGVar29 = (this->GJBaseGameLayer_data).m_unkdd8.start;
    cocos2d::CCPoint::CCPoint((CCPoint *)local_20,(CCPoint *)&DAT_01341eb0);
    cocos2d::CCPoint::operator=((CCPoint *)(ppGVar29 + 0x14c),(CCPoint *)local_20);
  }
  else {
    ppGVar29 = (this->GJBaseGameLayer_data).m_unkdd8.start;
    pCVar13 = (CCPoint *)(*(code *)((*ppGVar29)->CCNode_data).m_pCamera)(ppGVar29);
    cocos2d::CCPoint::CCPoint((CCPoint *)local_20,pCVar13);
    cocos2d::CCPoint::operator=((CCPoint *)(ppGVar29 + 0x14c),(CCPoint *)local_20);
  }
  if (lVar24 == 0) {
    pGVar31 = (GameObject *)(this->GJBaseGameLayer_data).m_unkdd0;
    pCVar13 = (CCPoint *)(**(code **)(pGVar31->CCCopying + 0xc0))(pGVar31);
    GameObject::setLastPosition(pGVar31,pCVar13);
    pGVar31 = (GameObject *)(this->GJBaseGameLayer_data).m_unkdd8.start;
    pCVar13 = (CCPoint *)(**(code **)(pGVar31->CCCopying + 0xc0))(pGVar31);
    GameObject::setLastPosition(pGVar31,pCVar13);
    if (((this->GJBaseGameLayer_data).m_hazardCollisionObjects.start != (GameObject **)0x0) &&
       (*(long *)((long)&(this->PlayLayer_data).m_blendingColors.factor + 3) == 0)) {
      GJBaseGameLayer::loadStartPosObject((GJBaseGameLayer *)this);
    }
  }
  GJBaseGameLayer::updatePlayerCollisionBlocks((GJBaseGameLayer *)this);
  if ((*(char *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 2) == '\0') &&
     (PlayerObject::playSpawnEffect((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0),
     (this->GJBaseGameLayer_data).m_gameState.m_isDualMode != false)) {
    PlayerObject::playSpawnEffect((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start);
  }
  GJBaseGameLayer::stopCameraShake((GJBaseGameLayer *)this);
  if ((this->GJBaseGameLayer_data).m_hazardCollisionObjects.start == (GameObject **)0x0) {
    if (lVar24 != 0) goto LAB_006e55c4;
    (this->GJBaseGameLayer_data).m_startingFromBeginning = true;
    GJBaseGameLayer::checkSpawnObjects((GJBaseGameLayer *)this);
LAB_006e5a58:
    GJBaseGameLayer::updateProximityVolumeEffects((GJBaseGameLayer *)this);
    GJBaseGameLayer::updateLevelColors((GJBaseGameLayer *)this);
    GJBaseGameLayer::updateCamera((GJBaseGameLayer *)this,0.0);
    (**(code **)(this->CCCopying + 0x498))(0,this);
    GJBaseGameLayer::updateGradientLayers((GJBaseGameLayer *)this);
    GJBaseGameLayer::updateShaderLayer((GJBaseGameLayer *)this,0.0);
    updateAttempts(this);
    *(undefined4 *)&(this->GJBaseGameLayer_data).m_savePositionValues.single =
         *(undefined4 *)&(this->GJBaseGameLayer_data).field_0x2f54;
    pGVar14 = (GameStatsManager *)
              FUN_00e18ea8(&(this->GJBaseGameLayer_data).m_savePositionValues.resize,
                           &(this->GJBaseGameLayer_data).m_savePositionValues.factor);
  }
  else {
    if (lVar24 == 0) goto LAB_006e5a58;
LAB_006e55c4:
    if (0 < *(int *)(lVar24 + 0xe94)) {
      local_20._0_4_ = 0.0;
      local_20._4_4_ = 0.0;
      local_18 = 0;
      local_10 = 0;
                    
      (**(code **)(this->CCCopying + 0x4d8))
                (0,this,*(int *)(lVar24 + 0xe94),0,(CCPoint *)local_20,
                 *(undefined4 *)(lVar24 + 0xe90),0);
      if ((CCPoint)local_20 != (CCPoint)0x0) {
        operator.delete((void *)local_20);
      }
    }
    GJBaseGameLayer::gameEventTriggered((GJBaseGameLayer *)this,0x40,0,0);
    GJBaseGameLayer::updateProximityVolumeEffects((GJBaseGameLayer *)this);
    GJBaseGameLayer::updateLevelColors((GJBaseGameLayer *)this);
    GJBaseGameLayer::updateCamera((GJBaseGameLayer *)this,0.0);
    (**(code **)(this->CCCopying + 0x498))(0,this);
    GJBaseGameLayer::updateGradientLayers((GJBaseGameLayer *)this);
    GJBaseGameLayer::updateShaderLayer((GJBaseGameLayer *)this,0.0);
    pGVar14 = (GameStatsManager *)updateAttempts(this);
  }
  pGVar14 = (GameStatsManager *)GameStatsManager::sharedState(pGVar14);
  GameStatsManager::incrementStat(pGVar14,"2");
  pGVar33 = (this->GJBaseGameLayer_data).m_level;
  iVar7 = ((pGVar33->GJGameLevel_data).m_attempts.random -
          (pGVar33->GJGameLevel_data).m_attempts.seed) + 1;
  (pGVar33->GJGameLevel_data).m_attempts.value = iVar7;
  iVar19 = rand();
  iVar19 = (int)((float)iVar19 * 4.656613e-10 * 1000.0);
  (pGVar33->GJGameLevel_data).m_attempts.seed = iVar19;
  (pGVar33->GJGameLevel_data).m_attempts.random = iVar7 + iVar19;
  updateProgressbar(this);
  GJBaseGameLayer::refreshCounterLabels((GJBaseGameLayer *)this);
  bVar2 = *(byte *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity;
  bVar3 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
  this_00 = (GameManager *)(ulong)bVar3;
  bVar5 = lVar24 == 0;
  if (bVar3 == 0) {
    uVar32 = (uint)(bVar5 & bVar2);
    this_00 = (GameManager *)(ulong)uVar32;
    uVar8 = (uint)bVar5;
    if ((uVar32 != 0) &&
       (uVar8 = uVar32,
       (this->GJBaseGameLayer_data).m_hazardCollisionObjects.start == (GameObject **)0x0)) {
      this_00 = (GameManager *)startMusic(this);
    }
  }
  else {
    *(undefined1 *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity = 0;
    uVar8 = (uint)bVar5;
  }
  lVar15 = GameManager::sharedState(this_00);
  if (((*(char *)(lVar15 + 0x333) == '\0') ||
      (*(char *)&(this->GJBaseGameLayer_data).m_endPortal != '\0')) ||
     (*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth != '\0')) {
    GJBaseGameLayer::removeReleasedButtons((GJBaseGameLayer *)this);
    cVar6 = UILayer::isJumpButtonPressed
                      ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
    if (cVar6 == '\0') goto LAB_006e593c;
LAB_006e571c:
    GJBaseGameLayer::queueButton((GJBaseGameLayer *)this,1,true,false,0.0);
  }
  else {
    tryStartRecord(this);
    GJBaseGameLayer::removeReleasedButtons((GJBaseGameLayer *)this);
    cVar6 = UILayer::isJumpButtonPressed
                      ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
    if (cVar6 != '\0') goto LAB_006e571c;
LAB_006e593c:
    GJBaseGameLayer::queueButton((GJBaseGameLayer *)this,1,false,false,0.0);
  }
  if ((*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') &&
     ((this->PlayLayer_data).field_0x16e == '\0')) {
    *(undefined1 *)((long)&(this->PlayLayer_data).m_speedObjects + 3) = 0;
  }
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 1) = 0;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_cameraWidth + 1) = 0;
  GJBaseGameLayer::syncBGTextures((GJBaseGameLayer *)this);
  dwTickEndp = clock();
  uVar21 = (this->GJBaseGameLayer_data).m_labelObjects.resize;
  dwDurationp = dwTickEndp - dwTickStartp;
  if (uVar21 != 0) {
    puVar22 = *(uint **)(uVar21 + 0x38);
    uVar32 = *puVar22;
    if (uVar32 != 0) {
      puVar30 = *(undefined8 **)(puVar22 + 4);
      puVar1 = puVar30 + ((ulong)uVar32 - 1);
      for (; (puVar30 <= puVar1 && ((CCNode *)*puVar30 != (CCNode *)0x0)); puVar30 = puVar30 + 1) {
        cocos2d::CCNode::qsortAllChildrenWithIndex((CCNode *)*puVar30);
      }
    }
  }
  GJBaseGameLayer::sortSectionVector((GJBaseGameLayer *)this);
  bVar3 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
  if ((bVar3 == 0) ||
     ((bVar2 == 0 && (bVar3 = *(byte *)((long)&(this->PlayLayer_data).m_unk383c + 3), bVar3 == 0))))
  {
    (this->GJBaseGameLayer_data).m_startingFromBeginning = false;
    *(undefined1 *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.start + 1) = 1;
    if (lVar24 == 0) goto LAB_006e5810;
  }
  else {
    *(undefined1 *)((long)&(this->PlayLayer_data).m_unk383c + 3) = 0;
    if (uVar8 != 0) {
      pCVar16 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create((CCDelayTime *)(ulong)bVar3,0.2);
      uVar17 = cocos2d::CCCallFunc::create
                         ((CCCallFunc *)this,(CCObject *)startGameDelayed,(_func_void *)0x0);
      pCVar18 = (CCAction *)cocos2d::CCSequence::create(pCVar16,uVar17,0);
      cocos2d::CCNode::runAction((CCNode *)this,pCVar18);
      (this->GJBaseGameLayer_data).m_startingFromBeginning = false;
      *(undefined1 *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.start + 1) = 1;
      goto LAB_006e5810;
    }
    *(undefined1 *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity = 1;
    (this->GJBaseGameLayer_data).m_startingFromBeginning = false;
    *(undefined1 *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.start + 1) = 1;
  }
  cocos2d::CCPoint::operator=
            (&(this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2,(CCPoint *)(lVar24 + 0x4a4)
            );
  cocos2d::CCPoint::operator=
            (&(this->GJBaseGameLayer_data).m_gameState.m_cameraStepDiff,(CCPoint *)(lVar24 + 0x454))
  ;
  cocos2d::CCPoint::operator=
            (&(this->GJBaseGameLayer_data).m_gameState.m_unkPoint4,(CCPoint *)(lVar24 + 0x168));
LAB_006e5810:
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}




void PlayLayer::resetLevelFromStart(PlayLayer *this)

{
  GameManager *pGVar1;
  GameManager *pGVar2;
  FMODAudioEngine *pFVar3;
  code *pcVar4;
  
  pGVar1 = (GameManager *)GameManager::sharedState((GameManager *)this);
  pGVar1 = (GameManager *)GameManager::getGameVariable(pGVar1,"0146");
  pGVar2 = (GameManager *)GameManager::sharedState(pGVar1);
  GameManager::setGameVariable(pGVar2,"0146",true);
  pFVar3 = (FMODAudioEngine *)(**(code **)(this->CCCopying + 0x600))(this);
  pFVar3 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar3);
  FMODAudioEngine::stopAllMusic(pFVar3,true);
  pcVar4 = *(code **)(this->CCCopying + 0x618);
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 1) = 1;
  pGVar2 = (GameManager *)(*pcVar4)(this);
  pGVar2 = (GameManager *)GameManager::sharedState(pGVar2);
  GameManager::setGameVariable(pGVar2,"0146",SUB81(pGVar1,0));
  return;
}




void PlayLayer::resetSPTriggered(PlayLayer *this)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  long *plVar5;
  
  lVar3 = *(long *)((long)&(this->PlayLayer_data).m_blendingColors.single + 3);
  if (lVar3 != 0) {
    puVar4 = *(uint **)(lVar3 + 0x38);
    uVar2 = *puVar4;
    if (uVar2 != 0) {
      plVar5 = *(long **)(puVar4 + 4);
      plVar1 = plVar5 + ((ulong)uVar2 - 1);
      for (; (plVar5 <= plVar1 && (*plVar5 != 0)); plVar5 = plVar5 + 1) {
        *(undefined1 *)(*plVar5 + 0x71a) = 0;
      }
    }
  }
  return;
}




void PlayLayer::resume(PlayLayer *this)

{
  byte bVar1;
  char cVar2;
  long lVar3;
  FMODAudioEngine *pFVar4;
  long *plVar5;
  GameManager *pGVar6;
  CCCopying *pCVar7;
  float fVar8;
  double dVar9;
  
  lVar3 = AppDelegate::get();
  if (*(char *)(lVar3 + 0x11) != '\0') {
    bVar1 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 2);
    if (bVar1 == 0) {
      GJBaseGameLayer::preResumeGame((GJBaseGameLayer *)this);
      *(undefined1 *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.start + 1) = 1;
    }
    else {
      pFVar4 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)(ulong)bVar1);
      pFVar4 = (FMODAudioEngine *)FMODAudioEngine::resumeAllAudio(pFVar4);
      FMODAudioEngine::sharedEngine(pFVar4);
      FMOD::System::update();
    }
    fVar8 = (float)PlatformToolbox::getDeviceRefreshRate();
    plVar5 = (long *)cocos2d::CCDirector::sharedDirector();
    pFVar4 = (FMODAudioEngine *)(**(code **)(*plVar5 + 0x60))((double)(1.0 / fVar8));
    pFVar4 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar4);
    fVar8 = (float)FMODAudioEngine::getBackgroundMusicVolume(pFVar4);
    *(undefined1 *)((long)&this[1].CCObject_data.m_unknown5 + 3) = 0;
    *(bool *)((long)&(this->PlayLayer_data).m_orbs + 3) = fVar8 <= 0.0;
    pGVar6 = (GameManager *)cocos2d::CCDirector::sharedDirector();
    pGVar6[0xaa] = (GameManager)0x1;
    pGVar6 = (GameManager *)GameManager::sharedState(pGVar6);
    cVar2 = GameManager::getGameVariable(pGVar6,"0128");
    if (cVar2 == '\0') {
      pGVar6 = (GameManager *)GameManager::sharedState((GameManager *)0x0);
      cVar2 = GameManager::getGameVariable(pGVar6,"0024");
      if (cVar2 == '\0') {
        PlatformToolbox::hideCursor();
      }
    }
    else {
      PlatformToolbox::toggleLockCursor(true);
    }
    lVar3 = AppDelegate::get();
    pCVar7 = this->CCCopying;
    *(undefined1 *)(lVar3 + 0x11) = 0;
    (**(code **)(pCVar7 + 0x2b0))(this);
    PlayerObject::releaseAllButtons((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
    UILayer::refreshDpad((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
    UILayer::resetAllButtons
              ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
    UILayer::toggleMenuVisibility
              ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last,true);
    dVar9 = (double)getTempMilliTime();
    *(double *)&this[1].CCObject_data.m_unknown2 =
         *(double *)&this[1].CCObject_data.m_unknown2 +
         (dVar9 - *(double *)&this[1].CCObject_data.m_uAutoReleaseCount);
  }
  return;
}




void PlayLayer::resumeAndRestart(PlayLayer *this,bool param_1)

{
  byte bVar1;
  char cVar2;
  FMODAudioEngine *pFVar3;
  long lVar4;
  GameManager *pGVar5;
  float fVar6;
  
  if ((*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') ||
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) != '\0')) {
    if ((param_1) ||
       (bVar1 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6), bVar1 == 0)
       ) {
      pFVar3 = (FMODAudioEngine *)GJBaseGameLayer::resetAudio();
    }
    else {
      pFVar3 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)(ulong)bVar1);
      pFVar3 = (FMODAudioEngine *)FMODAudioEngine::stopAllEffects(pFVar3);
      pFVar3 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar3);
      pFVar3 = (FMODAudioEngine *)FMODAudioEngine::stopAllMusic(pFVar3,false);
    }
    *(undefined1 *)&this[1].CCNode_data.m_sInverse.ty = 0;
    pFVar3 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar3);
    fVar6 = (float)FMODAudioEngine::getBackgroundMusicVolume(pFVar3);
    *(bool *)((long)&(this->PlayLayer_data).m_orbs + 3) = fVar6 <= 0.0;
  }
  *(undefined1 *)((long)&this[1].CCObject_data.m_unknown5 + 3) = 0;
  lVar4 = AppDelegate::get();
  if (*(char *)(lVar4 + 0x11) == '\0') {
    return;
  }
  lVar4 = AppDelegate::get();
  *(undefined1 *)(lVar4 + 0x11) = 0;
  PlayerObject::releaseAllButtons((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
  UILayer::resetAllButtons
            ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
  pGVar5 = (GameManager *)
           UILayer::toggleMenuVisibility
                     ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last,true
                     );
  pGVar5 = (GameManager *)GameManager::sharedState(pGVar5);
  cVar2 = GameManager::getGameVariable(pGVar5,"0128");
  if (cVar2 == '\0') {
    pGVar5 = (GameManager *)GameManager::sharedState((GameManager *)0x0);
    cVar2 = GameManager::getGameVariable(pGVar5,"0024");
    if (cVar2 == '\0') {
      PlatformToolbox::hideCursor();
    }
    (**(code **)(this->CCCopying + 0x2b0))(this);
  }
  else {
    PlatformToolbox::toggleLockCursor(true);
    (**(code **)(this->CCCopying + 0x2b0))(this);
  }
  if (!param_1) {
    (**(code **)(this->CCCopying + 0x618))(this);
    return;
  }
  resetLevelFromStart(this);
  return;
}


/* PlayLayer::saveActiveSaveObjects(std::vector<SavedActiveObjectState,
   std::allocator<SavedActiveObjectState> >&, std::vector<SavedSpecialObjectState,
   std::allocator<SavedSpecialObjectState> >&) */

void PlayLayer::saveActiveSaveObjects(vector *param_1,vector *param_2)

{
  undefined8 uVar1;
  byte bVar2;
  undefined1 uVar3;
  vector vVar4;
  vector vVar5;
  char cVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  long *plVar9;
  long *plVar10;
  ulong *puVar11;
  ulong uVar12;
  ulong *puVar13;
  long *plVar14;
  undefined8 *puVar15;
  int iVar16;
  vector *in_x2;
  vector *pvVar17;
  ulong *puVar18;
  undefined8 *puVar19;
  long *plVar20;
  vector *in_x3;
  undefined8 *puVar21;
  vector *pvVar22;
  long lVar23;
  long *plVar24;
  vector *in_x4;
  ulong uVar25;
  void *pvVar26;
  ulong *puVar27;
  long *plVar28;
  long lVar29;
  ulong *puVar30;
  long *plVar31;
  long *unaff_x24;
  undefined8 *puVar32;
  vector *this;
  long *plVar33;
  void *pvVar34;
  vector *pvVar35;
  void *unaff_x27;
  vector *pvVar36;
  vector *unaff_x28;
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  
  puVar27 = *(ulong **)(param_1 + 0x37e8);
  puVar30 = *(ulong **)(param_1 + 0x37f0);
  pvVar34 = (void *)((long)puVar30 - (long)puVar27 >> 3);
  if ((long)puVar30 - (long)puVar27 < 0) {
    pvVar17 = in_x2;
    auVar37 = FUN_00e13af4("vector::reserve");
    goto LAB_006d0524;
  }
  puVar32 = *(undefined8 **)param_2;
  pvVar17 = in_x2;
  if ((void *)(*(long *)(param_2 + 0x10) - (long)puVar32 >> 4) < pvVar34) {
    puVar7 = *(undefined8 **)(param_2 + 8);
    lVar29 = (long)puVar7 - (long)puVar32;
    if (pvVar34 == (void *)0x0) {
      puVar8 = (undefined8 *)0x0;
      puVar15 = puVar8;
      puVar21 = puVar32;
    }
    else {
      pvVar34 = (void *)((long)pvVar34 << 4);
      puVar8 = operator.new(pvVar34);
      puVar15 = puVar8;
      puVar21 = *(undefined8 **)param_2;
    }
    for (; puVar32 != puVar7; puVar32 = puVar32 + 2) {
      if (puVar8 != (undefined8 *)0x0) {
        pvVar17 = (vector *)*puVar32;
        in_x3 = (vector *)puVar32[1];
        *puVar8 = pvVar17;
        puVar8[1] = in_x3;
      }
      puVar8 = puVar8 + 2;
    }
    if (puVar21 != (undefined8 *)0x0) {
      operator.delete(puVar21);
    }
    *(undefined8 **)param_2 = puVar15;
    *(long *)(param_2 + 8) = (long)puVar15 + lVar29;
    *(long *)(param_2 + 0x10) = (long)puVar15 + (long)pvVar34;
    puVar30 = *(ulong **)(param_1 + 0x37f0);
    puVar27 = *(ulong **)(param_1 + 0x37e8);
  }
  this = (vector *)0xfffffffffffffff;
  if (puVar27 == puVar30) goto LAB_006d00d0;
  do {
    cVar6 = (**(code **)(*(long *)*puVar27 + 0x600))((long *)*puVar27);
    if (cVar6 != '\0') {
      puVar11 = *(ulong **)(param_2 + 8);
      pvVar34 = (void *)*puVar27;
      if (puVar11 == *(ulong **)(param_2 + 0x10)) {
        auVar38._8_8_ = puVar11;
        auVar38._0_8_ = *(long *)param_2;
        pvVar17 = (vector *)((long)puVar11 - *(long *)param_2);
        in_x3 = (vector *)((long)pvVar17 >> 4);
        if (in_x3 != (vector *)0x0) {
          in_x4 = (vector *)((long)in_x3 * 2);
          unaff_x28 = (vector *)0xfffffffffffffff0;
          pvVar26 = pvVar34;
          if (in_x3 <= in_x4) goto LAB_006d0550;
          goto LAB_006d0368;
        }
        unaff_x28 = (vector *)0x10;
        goto LAB_006d0368;
      }
      bVar2 = *(byte *)((long)pvVar34 + 0x594);
      pvVar17 = (vector *)(ulong)bVar2;
      uVar3 = *(undefined1 *)((long)pvVar34 + 0x595);
      if (puVar11 != (ulong *)0x0) {
        *puVar11 = (ulong)pvVar34;
        *(byte *)(puVar11 + 1) = bVar2;
        *(undefined1 *)((long)puVar11 + 9) = uVar3;
      }
      *(ulong **)(param_2 + 8) = puVar11 + 2;
    }
    while (puVar27 = puVar27 + 1, puVar30 == puVar27) {
LAB_006d00d0:
      puVar30 = *(ulong **)param_2;
      puVar27 = *(ulong **)(param_2 + 8);
      this = (vector *)((long)puVar27 - (long)puVar30);
      uVar12 = (long)this >> 4;
      if (uVar12 == *(long *)(param_2 + 0x10) - (long)puVar30 >> 4) goto LAB_006d0154;
      if (uVar12 == 0) {
        puVar11 = (ulong *)0x0;
LAB_006d00f8:
        puVar13 = puVar11;
        puVar18 = puVar30;
        if (puVar30 != puVar27) {
          do {
            if (puVar13 != (ulong *)0x0) {
              uVar12 = puVar18[1];
              *puVar13 = *puVar18;
              puVar13[1] = uVar12;
            }
            puVar18 = puVar18 + 2;
            puVar13 = puVar13 + 2;
          } while (puVar27 != puVar18);
          puVar13 = (ulong *)((long)puVar11 +
                             ((long)puVar27 - (long)(puVar30 + 2) & 0xfffffffffffffff0U) + 0x10);
        }
        pvVar34 = *(void **)param_2;
        *(ulong **)(param_2 + 8) = puVar13;
        *(ulong **)param_2 = puVar11;
        *(vector **)(param_2 + 0x10) = (vector *)((long)puVar11 + (long)this);
        if (pvVar34 != (void *)0x0) {
          operator.delete(pvVar34);
        }
LAB_006d0154:
        plVar33 = *(long **)(param_1 + 0x3808);
        plVar28 = *(long **)(param_1 + 0x3800);
        do {
          if (plVar28 == plVar33) {
            unaff_x24 = *(long **)(param_1 + 0x1090);
            pvVar34 = (void *)0x1;
            param_2 = (vector *)0xfffffffffffffff;
            do {
              if (unaff_x24 == (long *)0x0) {
                return;
              }
              puVar30 = (ulong *)unaff_x24[3];
              puVar27 = (ulong *)unaff_x24[2];
              if (puVar30 != puVar27) {
                do {
                  param_1 = (vector *)*puVar27;
                  if (param_1[0x750] != (vector)0x0) {
                    puVar32 = *(undefined8 **)(in_x2 + 8);
                    if (puVar32 == *(undefined8 **)(in_x2 + 0x10)) {
                      auVar37._8_8_ = puVar32;
                      auVar37._0_8_ = *(long *)in_x2;
                      in_x3 = (vector *)((long)puVar32 - *(long *)in_x2);
                      pvVar17 = (vector *)((long)in_x3 >> 4);
                      if (pvVar17 == (vector *)0x0) {
                        unaff_x27 = (void *)0x10;
LAB_006d0244:
                        puVar7 = operator.new(unaff_x27);
                        puVar32 = puVar7 + 2;
                        auVar37 = *(undefined1 (*) [16])in_x2;
                        in_x3 = (vector *)(*(long *)(in_x2 + 8) - *(long *)in_x2);
                      }
                      else {
                        in_x4 = (vector *)((long)pvVar17 * 2);
                        unaff_x27 = (void *)0xfffffffffffffff0;
                        if (in_x4 < pvVar17) goto LAB_006d0244;
LAB_006d0524:
                        if (param_2 < in_x4) goto LAB_006d0244;
                        unaff_x27 = (void *)((long)pvVar17 << 5);
                        puVar32 = (undefined8 *)0x10;
                        puVar7 = (undefined8 *)0x0;
                        if (in_x4 != (vector *)0x0) goto LAB_006d0244;
                      }
                      puVar15 = auVar37._8_8_;
                      puVar8 = auVar37._0_8_;
                      if ((vector *)((long)puVar7 + (long)in_x3) != (vector *)0x0) {
                        *(vector **)((long)puVar7 + (long)in_x3) = param_1;
                        *(int *)((vector *)((long)puVar7 + (long)in_x3) + 8) = (int)pvVar34;
                      }
                      puVar19 = puVar7;
                      puVar21 = puVar8;
                      if (puVar15 != puVar8) {
                        do {
                          if (puVar19 != (undefined8 *)0x0) {
                            uVar1 = puVar21[1];
                            *puVar19 = *puVar21;
                            puVar19[1] = uVar1;
                          }
                          puVar21 = puVar21 + 2;
                          puVar19 = puVar19 + 2;
                        } while (puVar15 != puVar21);
                        puVar32 = (undefined8 *)
                                  ((long)puVar7 +
                                  ((long)puVar15 - (long)(puVar8 + 2) & 0xfffffffffffffff0U) + 0x20)
                        ;
                      }
                      if (puVar8 != (undefined8 *)0x0) {
                        operator.delete(puVar8);
                      }
                      *(undefined8 **)in_x2 = puVar7;
                      *(undefined8 **)(in_x2 + 8) = puVar32;
                      *(long *)(in_x2 + 0x10) = (long)puVar7 + (long)unaff_x27;
                    }
                    else {
                      if (puVar32 != (undefined8 *)0x0) {
                        *puVar32 = param_1;
                        *(int *)(puVar32 + 1) = (int)pvVar34;
                      }
                      *(undefined8 **)(in_x2 + 8) = puVar32 + 2;
                    }
                  }
                  puVar27 = puVar27 + 1;
                } while (puVar30 != puVar27);
              }
              unaff_x24 = (long *)*unaff_x24;
            } while( true );
          }
          lVar29 = *plVar28;
          iVar16 = *(int *)(lVar29 + 0x5d4);
          if (iVar16 != 0) {
            plVar14 = *(long **)(in_x2 + 8);
            if (plVar14 == *(long **)(in_x2 + 0x10)) {
              plVar9 = *(long **)in_x2;
              lVar23 = (long)plVar14 - (long)plVar9;
              uVar12 = lVar23 >> 4;
              if (uVar12 == 0) {
                pvVar34 = (void *)0x10;
LAB_006d0424:
                plVar10 = operator.new(pvVar34);
                plVar9 = *(long **)in_x2;
                plVar31 = plVar10 + 2;
                plVar14 = *(long **)(in_x2 + 8);
                iVar16 = *(int *)(lVar29 + 0x5d4);
                lVar23 = (long)plVar14 - (long)plVar9;
                lVar29 = *plVar28;
              }
              else {
                uVar25 = uVar12 * 2;
                pvVar34 = (void *)0xfffffffffffffff0;
                if (((uVar25 < uVar12) || (0xfffffffffffffff < uVar25)) ||
                   (pvVar34 = (void *)(uVar12 << 5), uVar25 != 0)) goto LAB_006d0424;
                plVar31 = (long *)0x10;
                plVar10 = (long *)0x0;
              }
              if ((long)plVar10 + lVar23 != 0) {
                *(long *)((long)plVar10 + lVar23) = lVar29;
                *(int *)((long)plVar10 + lVar23 + 8) = iVar16;
              }
              plVar20 = plVar9;
              plVar24 = plVar10;
              if (plVar9 != plVar14) {
                do {
                  if (plVar24 != (long *)0x0) {
                    lVar29 = plVar20[1];
                    *plVar24 = *plVar20;
                    plVar24[1] = lVar29;
                  }
                  plVar20 = plVar20 + 2;
                  plVar24 = plVar24 + 2;
                } while (plVar20 != plVar14);
                plVar31 = (long *)((long)plVar10 +
                                  ((long)plVar20 - (long)(plVar9 + 2) & 0xfffffffffffffff0U) + 0x20)
                ;
              }
              if (plVar9 != (long *)0x0) {
                operator.delete(plVar9);
              }
              *(long **)in_x2 = plVar10;
              *(long **)(in_x2 + 8) = plVar31;
              *(long *)(in_x2 + 0x10) = (long)plVar10 + (long)pvVar34;
            }
            else {
              if (plVar14 != (long *)0x0) {
                *plVar14 = lVar29;
                *(int *)(plVar14 + 1) = iVar16;
              }
              *(long **)(in_x2 + 8) = plVar14 + 2;
            }
          }
          plVar28 = plVar28 + 1;
        } while( true );
      }
      if (uVar12 < 0x1000000000000000) {
                    
        puVar11 = operator.new(this);
        goto LAB_006d00f8;
      }
                    
      auVar38 = FUN_00e1383c();
      pvVar26 = pvVar34;
LAB_006d0550:
      pvVar34 = pvVar26;
      if ((this < in_x4) || (unaff_x28 = (vector *)((long)in_x3 << 5), in_x4 != (vector *)0x0)) {
LAB_006d0368:
        pvVar36 = operator.new(unaff_x28);
        pvVar35 = pvVar36 + 0x10;
        auVar38 = *(undefined1 (*) [16])param_2;
        pvVar26 = (void *)*puVar27;
        pvVar17 = (vector *)(*(long *)(param_2 + 8) - *(long *)param_2);
      }
      else {
        pvVar35 = (vector *)0x10;
        pvVar36 = (vector *)0x0;
      }
      puVar32 = auVar38._0_8_;
      in_x3 = pvVar36 + (long)pvVar17;
      vVar4 = *(vector *)((long)pvVar34 + 0x594);
      vVar5 = *(vector *)((long)pvVar34 + 0x595);
      in_x4 = (vector *)(ulong)(byte)vVar5;
      if (in_x3 != (vector *)0x0) {
        *(void **)(pvVar36 + (long)pvVar17) = pvVar26;
        in_x3[8] = vVar4;
        in_x3[9] = vVar5;
      }
      puVar7 = puVar32;
      pvVar22 = pvVar36;
      if (auVar38._8_8_ != puVar32) {
        do {
          if (pvVar22 != (vector *)0x0) {
            in_x4 = (vector *)*puVar7;
            uVar1 = puVar7[1];
            *(vector **)pvVar22 = in_x4;
            *(undefined8 *)(pvVar22 + 8) = uVar1;
          }
          puVar7 = puVar7 + 2;
          in_x3 = pvVar22 + 0x10;
          pvVar22 = in_x3;
        } while (puVar7 != auVar38._8_8_);
        pvVar17 = (vector *)((long)puVar7 - (long)(puVar32 + 2));
        pvVar35 = pvVar36 + ((ulong)pvVar17 & 0xfffffffffffffff0) + 0x20;
      }
      if (puVar32 != (undefined8 *)0x0) {
        operator.delete(puVar32);
      }
      unaff_x28 = pvVar36 + (long)unaff_x28;
      *(vector **)param_2 = pvVar36;
      *(vector **)(param_2 + 8) = pvVar35;
      *(vector **)(param_2 + 0x10) = unaff_x28;
    }
  } while( true );
}


/* PlayLayer::saveDynamicSaveObjects(std::vector<SavedObjectStateRef,
   std::allocator<SavedObjectStateRef> >&) */

void PlayLayer::saveDynamicSaveObjects(PlayLayer *this,vector *param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  long lVar13;
  void *pvVar14;
  undefined8 *unaff_x26;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  double unaff_d8;
  double unaff_d9;
  float unaff_s10;
  float unaff_s11;
  float unaff_s12;
  float unaff_s13;
  undefined1 auVar19 [16];
  
  puVar10 = *(undefined8 **)((long)&(this->PlayLayer_data).m_collectibles + 3);
  puVar12 = *(undefined8 **)&(this->PlayLayer_data).field_0x110;
  pvVar14 = (void *)((long)puVar12 - (long)puVar10 >> 3);
  if ((void *)0x555555555555555 < pvVar14) {
    FUN_00e13af4("vector::reserve");
                    /* catch(type#1 @ 00000000) { ... } // from try @ 006cfb80 with catch @ 006cfbe0
                        */
    __cxa_begin_catch();
    __cxa_end_catch();
    return;
  }
  puVar8 = *(undefined8 **)param_1;
  puVar11 = *(undefined8 **)(param_1 + 0x10);
  if ((void *)(((long)puVar11 - (long)puVar8 >> 4) * -0x5555555555555555) < pvVar14) {
    unaff_x26 = *(undefined8 **)(param_1 + 8);
    lVar13 = (long)unaff_x26 - (long)puVar8;
    if (pvVar14 == (void *)0x0) {
      puVar10 = (undefined8 *)0x0;
      puVar11 = puVar10;
      puVar12 = puVar8;
    }
    else {
      pvVar14 = (void *)((long)pvVar14 * 0x30);
      puVar10 = operator.new(pvVar14);
      puVar11 = puVar10;
      puVar12 = *(undefined8 **)param_1;
    }
    for (; puVar8 != unaff_x26; puVar8 = puVar8 + 6) {
      if (puVar10 != (undefined8 *)0x0) {
        uVar1 = puVar8[1];
        *puVar10 = *puVar8;
        puVar10[1] = uVar1;
        uVar1 = puVar8[3];
        puVar10[2] = puVar8[2];
        puVar10[3] = uVar1;
        uVar1 = puVar8[5];
        puVar10[4] = puVar8[4];
        puVar10[5] = uVar1;
      }
      puVar10 = puVar10 + 6;
    }
    if (puVar12 != (undefined8 *)0x0) {
      operator.delete(puVar12);
    }
    *(undefined8 **)param_1 = puVar11;
    puVar8 = (undefined8 *)((long)puVar11 + lVar13);
    puVar11 = (undefined8 *)((long)puVar11 + (long)pvVar14);
    *(undefined8 **)(param_1 + 8) = puVar8;
    *(undefined8 **)(param_1 + 0x10) = puVar11;
    puVar12 = *(undefined8 **)&(this->PlayLayer_data).field_0x110;
    puVar10 = *(undefined8 **)((long)&(this->PlayLayer_data).m_collectibles + 3);
  }
  else {
    puVar8 = *(undefined8 **)(param_1 + 8);
  }
  if (puVar12 == puVar10) goto LAB_006cf8b0;
  pvVar14 = (void *)0xaaaaaaaaaaaaaaab;
  do {
    puVar9 = (undefined8 *)*puVar10;
    unaff_d8 = (double)puVar9[0x74] - (double)*(float *)((long)puVar9 + 0x29c);
    if (unaff_d8 == (double)*(float *)(puVar9 + 0x76)) {
      unaff_d9 = (double)puVar9[0x75] - (double)*(float *)(puVar9 + 0x54);
      fVar16 = *(float *)((long)puVar9 + 0x2a4);
      if (unaff_d9 != (double)*(float *)((long)puVar9 + 0x3b4)) {
        fVar17 = *(float *)((long)puVar9 + 0x2ac);
        fVar18 = *(float *)((long)puVar9 + 0x2b4);
        fVar15 = *(float *)(puVar9 + 0x57);
        goto LAB_006cf7a8;
      }
      fVar17 = *(float *)((long)puVar9 + 0x2ac);
      if (fVar16 != 0.0) {
        fVar18 = *(float *)((long)puVar9 + 0x2b4);
        fVar15 = *(float *)(puVar9 + 0x57);
        goto LAB_006cf7a8;
      }
      fVar18 = *(float *)((long)puVar9 + 0x2b4);
      if (fVar17 != 0.0) {
        fVar15 = *(float *)(puVar9 + 0x57);
        goto LAB_006cf7a8;
      }
      fVar15 = *(float *)(puVar9 + 0x57);
      if ((fVar18 != 0.0) || (fVar15 != 0.0)) goto LAB_006cf7a8;
    }
    else {
      fVar16 = *(float *)((long)puVar9 + 0x2a4);
      fVar17 = *(float *)((long)puVar9 + 0x2ac);
      fVar18 = *(float *)((long)puVar9 + 0x2b4);
      unaff_d9 = (double)puVar9[0x75] - (double)*(float *)(puVar9 + 0x54);
      fVar15 = *(float *)(puVar9 + 0x57);
LAB_006cf7a8:
      unaff_s13 = fVar16 - *(float *)(puVar9 + 0x55);
      unaff_s12 = fVar17 - *(float *)(puVar9 + 0x56);
      unaff_s11 = fVar18 - *(float *)((long)puVar9 + 700);
      unaff_s10 = fVar15 - *(float *)(puVar9 + 0x58);
      if (puVar8 == puVar11) {
        uVar5 = (long)puVar8 - *(long *)param_1;
        unaff_x26 = (undefined8 *)(((long)uVar5 >> 4) * (long)pvVar14);
        puVar4 = puVar9;
        if (unaff_x26 != (undefined8 *)0x0) {
          auVar19._8_8_ = (undefined8 *)((long)unaff_x26 * 2);
          auVar19._0_8_ = *(long *)param_1;
          puVar11 = (undefined8 *)0xfffffffffffffff0;
          puVar7 = puVar8;
          if (unaff_x26 < (undefined8 *)((long)unaff_x26 * 2) || unaff_x26 == (undefined8 *)0x0)
          goto LAB_006cfba4;
          goto LAB_006cf9d0;
        }
        puVar11 = (undefined8 *)0x30;
        goto LAB_006cf9d0;
      }
      uVar2 = *(undefined4 *)(puVar9 + 0x97);
      uVar3 = *(undefined4 *)((long)puVar9 + 0x4bc);
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = puVar9;
        puVar8[1] = unaff_d8;
        puVar11 = *(undefined8 **)(param_1 + 0x10);
        puVar8[2] = unaff_d9;
        *(float *)(puVar8 + 3) = unaff_s13;
        *(float *)((long)puVar8 + 0x1c) = unaff_s12;
        *(float *)(puVar8 + 4) = unaff_s11;
        *(float *)((long)puVar8 + 0x24) = unaff_s10;
        *(undefined4 *)(puVar8 + 5) = uVar2;
        *(undefined4 *)((long)puVar8 + 0x2c) = uVar3;
      }
      puVar8 = puVar8 + 6;
      *(undefined8 **)(param_1 + 8) = puVar8;
    }
    while (puVar10 = puVar10 + 1, puVar12 == puVar10) {
LAB_006cf8b0:
      puVar9 = *(undefined8 **)param_1;
      puVar10 = (undefined8 *)((long)puVar8 - (long)puVar9);
      uVar5 = ((long)puVar10 >> 4) * -0x5555555555555555;
      if (((long)puVar11 - (long)puVar9 >> 4) * -0x5555555555555555 +
          ((long)puVar10 >> 4) * 0x5555555555555555 == 0) {
        return;
      }
      if (uVar5 == 0) {
        puVar12 = (undefined8 *)0x0;
LAB_006cf8e4:
        puVar4 = puVar12;
        puVar11 = puVar9;
        if (puVar9 != puVar8) {
          do {
            if (puVar4 != (undefined8 *)0x0) {
              uVar1 = puVar11[1];
              *puVar4 = *puVar11;
              puVar4[1] = uVar1;
              uVar1 = puVar11[3];
              puVar4[2] = puVar11[2];
              puVar4[3] = uVar1;
              uVar1 = puVar11[5];
              puVar4[4] = puVar11[4];
              puVar4[5] = uVar1;
            }
            puVar11 = puVar11 + 6;
            puVar4 = puVar4 + 6;
          } while (puVar11 != puVar8);
          puVar4 = puVar12 + ((((ulong)((long)puVar11 - (long)(puVar9 + 6)) >> 4) *
                               0xaaaaaaaaaaaaaab & 0xfffffffffffffff) + 1) * 6;
        }
        pvVar14 = *(void **)param_1;
        *(undefined8 **)(param_1 + 8) = puVar4;
        *(undefined8 **)param_1 = puVar12;
        *(long *)(param_1 + 0x10) = (long)puVar12 + (long)puVar10;
        if (pvVar14 == (void *)0x0) {
          return;
        }
        operator.delete(pvVar14);
        return;
      }
      if (uVar5 < 0x555555555555556) {
                    
        puVar12 = operator.new(puVar10);
        goto LAB_006cf8e4;
      }
      auVar19 = FUN_00e1383c();
      puVar7 = puVar8;
LAB_006cfba4:
      puVar6 = auVar19._0_8_;
      puVar4 = puVar9;
      if ((auVar19._8_8_ < 0x555555555555556) &&
         (puVar11 = (undefined8 *)((long)unaff_x26 * 0x60), auVar19._8_8_ == 0)) {
        puVar8 = (undefined8 *)0x30;
        unaff_x26 = (undefined8 *)0x0;
      }
      else {
LAB_006cf9d0:
        unaff_x26 = operator.new(puVar11);
        puVar6 = *(undefined8 **)param_1;
        puVar8 = unaff_x26 + 6;
        puVar7 = *(undefined8 **)(param_1 + 8);
        puVar9 = (undefined8 *)*puVar10;
        uVar5 = (long)puVar7 - (long)puVar6;
      }
      lVar13 = (long)unaff_x26 + uVar5;
      uVar2 = *(undefined4 *)(puVar4 + 0x97);
      uVar3 = *(undefined4 *)((long)puVar4 + 0x4bc);
      if (lVar13 != 0) {
        *(undefined8 **)((long)unaff_x26 + uVar5) = puVar9;
        *(double *)(lVar13 + 8) = unaff_d8;
        *(double *)(lVar13 + 0x10) = unaff_d9;
        *(float *)(lVar13 + 0x18) = unaff_s13;
        *(float *)(lVar13 + 0x1c) = unaff_s12;
        *(float *)(lVar13 + 0x20) = unaff_s11;
        *(float *)(lVar13 + 0x24) = unaff_s10;
        *(undefined4 *)(lVar13 + 0x28) = uVar2;
        *(undefined4 *)(lVar13 + 0x2c) = uVar3;
      }
      puVar4 = unaff_x26;
      puVar9 = puVar6;
      if (puVar6 != puVar7) {
        do {
          if (puVar4 != (undefined8 *)0x0) {
            uVar1 = puVar9[1];
            *puVar4 = *puVar9;
            puVar4[1] = uVar1;
            uVar1 = puVar9[3];
            puVar4[2] = puVar9[2];
            puVar4[3] = uVar1;
            uVar1 = puVar9[5];
            puVar4[4] = puVar9[4];
            puVar4[5] = uVar1;
          }
          puVar9 = puVar9 + 6;
          puVar4 = puVar4 + 6;
        } while (puVar9 != puVar7);
        puVar8 = unaff_x26 +
                 ((((ulong)((long)puVar9 - (long)(puVar6 + 6)) >> 4) * 0xaaaaaaaaaaaaaab &
                  0xfffffffffffffff) + 1) * 6 + 6;
      }
      if (puVar6 != (undefined8 *)0x0) {
        operator.delete(puVar6);
      }
      puVar11 = (undefined8 *)((long)unaff_x26 + (long)puVar11);
      *(undefined8 **)param_1 = unaff_x26;
      *(undefined8 **)(param_1 + 8) = puVar8;
      *(undefined8 **)(param_1 + 0x10) = puVar11;
    }
  } while( true );
}




void PlayLayer::scanActiveSaveObjects(PlayLayer *this)

{
  undefined8 *puVar1;
  uint uVar2;
  char cVar3;
  void *pvVar4;
  void *pvVar5;
  GameObject *pGVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long lVar9;
  ulong uVar10;
  long *plVar11;
  undefined8 *puVar12;
  GameObject **ppGVar13;
  size_t sVar14;
  void *pvVar15;
  
  ppGVar13 = (this->GJBaseGameLayer_data).m_unkdd8.capacity;
  if (ppGVar13 != (GameObject **)0x0) {
    pGVar6 = ppGVar13[7];
    uVar2 = *(uint *)&pGVar6->CCCopying;
    if (uVar2 != 0) {
      puVar12 = *(undefined8 **)&(pGVar6->CCObject_data).m_nTag;
      puVar1 = puVar12 + ((ulong)uVar2 - 1);
      if ((puVar12 <= puVar1) && (plVar11 = (long *)*puVar12, plVar11 != (long *)0x0)) {
        do {
          cVar3 = (**(code **)(*plVar11 + 0x650))(plVar11);
          if (cVar3 == '\0') {
            if (((int)plVar11[0x9a] == 2) && ((char)plVar11[0xba] != '\0')) {
              puVar8 = *(undefined8 **)((long)&(this->PlayLayer_data).m_progressFill + 3);
              if (puVar8 == *(undefined8 **)((long)&(this->PlayLayer_data).m_progressWidth + 3)) {
                pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_progressBar + 3);
                sVar14 = (long)puVar8 - (long)pvVar4;
                uVar7 = (long)sVar14 >> 3;
                if (uVar7 == 0) {
                  pvVar15 = (void *)0x8;
LAB_006cfed4:
                  pvVar5 = operator.new(pvVar15);
                  pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_progressBar + 3);
                  sVar14 = *(long *)((long)&(this->PlayLayer_data).m_progressFill + 3) -
                           (long)pvVar4;
                }
                else {
                  uVar10 = uVar7 * 2;
                  pvVar15 = (void *)0xfffffffffffffff8;
                  if ((uVar10 < uVar7) || (0x1fffffffffffffff < uVar10)) goto LAB_006cfed4;
                  pvVar15 = (void *)(uVar7 << 4);
                  pvVar5 = (void *)0x0;
                  if (uVar10 != 0) goto LAB_006cfed4;
                }
                if ((long)pvVar5 + sVar14 != 0) {
                  *(long **)((long)pvVar5 + sVar14) = plVar11;
                  pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_progressBar + 3);
                  sVar14 = *(long *)((long)&(this->PlayLayer_data).m_progressFill + 3) -
                           (long)pvVar4;
                }
                if ((long)sVar14 >> 3 != 0) {
                  memmove(pvVar5,pvVar4,sVar14);
                  pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_progressBar + 3);
                }
                if (pvVar4 != (void *)0x0) {
                  operator.delete(pvVar4);
                }
                *(void **)((long)&(this->PlayLayer_data).m_progressBar + 3) = pvVar5;
                *(size_t *)((long)&(this->PlayLayer_data).m_progressFill + 3) =
                     (long)pvVar5 + sVar14 + 8;
                *(long *)((long)&(this->PlayLayer_data).m_progressWidth + 3) =
                     (long)pvVar5 + (long)pvVar15;
              }
              else {
                lVar9 = 0;
                if (puVar8 != (undefined8 *)0x0) {
                  *puVar8 = plVar11;
                  lVar9 = *(long *)((long)&(this->PlayLayer_data).m_progressFill + 3);
                }
                *(long *)((long)&(this->PlayLayer_data).m_progressFill + 3) = lVar9 + 8;
              }
            }
          }
          else {
            cVar3 = (**(code **)(*plVar11 + 0x6c0))
                              (plVar11,*(undefined1 *)
                                        ((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles +
                                        6));
            if (cVar3 == '\0') {
              puVar8 = *(undefined8 **)((long)&(this->PlayLayer_data).m_percentageLabel + 3);
              if (puVar8 == *(undefined8 **)&(this->PlayLayer_data).field_0x130) {
                pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_attemptLabel + 3);
                sVar14 = (long)puVar8 - (long)pvVar4;
                uVar7 = (long)sVar14 >> 3;
                if (uVar7 == 0) {
                  pvVar15 = (void *)0x8;
LAB_006cff4c:
                  pvVar5 = operator.new(pvVar15);
                  pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_attemptLabel + 3);
                  sVar14 = *(long *)((long)&(this->PlayLayer_data).m_percentageLabel + 3) -
                           (long)pvVar4;
                }
                else {
                  uVar10 = uVar7 * 2;
                  pvVar15 = (void *)0xfffffffffffffff8;
                  if ((uVar10 < uVar7) || (0x1fffffffffffffff < uVar10)) goto LAB_006cff4c;
                  pvVar15 = (void *)(uVar7 << 4);
                  pvVar5 = (void *)0x0;
                  if (uVar10 != 0) goto LAB_006cff4c;
                }
                if ((long)pvVar5 + sVar14 != 0) {
                  *(long **)((long)pvVar5 + sVar14) = plVar11;
                  pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_attemptLabel + 3);
                  sVar14 = *(long *)((long)&(this->PlayLayer_data).m_percentageLabel + 3) -
                           (long)pvVar4;
                }
                if ((long)sVar14 >> 3 != 0) {
                  memmove(pvVar5,pvVar4,sVar14);
                  pvVar4 = *(void **)((long)&(this->PlayLayer_data).m_attemptLabel + 3);
                }
                if (pvVar4 != (void *)0x0) {
                  operator.delete(pvVar4);
                }
                *(void **)((long)&(this->PlayLayer_data).m_attemptLabel + 3) = pvVar5;
                *(size_t *)((long)&(this->PlayLayer_data).m_percentageLabel + 3) =
                     (long)pvVar5 + sVar14 + 8;
                *(long *)&(this->PlayLayer_data).field_0x130 = (long)pvVar5 + (long)pvVar15;
              }
              else {
                lVar9 = 0;
                if (puVar8 != (undefined8 *)0x0) {
                  *puVar8 = plVar11;
                  lVar9 = *(long *)((long)&(this->PlayLayer_data).m_percentageLabel + 3);
                }
                *(long *)((long)&(this->PlayLayer_data).m_percentageLabel + 3) = lVar9 + 8;
              }
            }
          }
          puVar12 = puVar12 + 1;
        } while ((puVar12 <= puVar1) && (plVar11 = (long *)*puVar12, plVar11 != (long *)0x0));
      }
    }
  }
  return;
}





void PlayLayer::scanDynamicSaveObjects(PlayLayer *this)

{
  vector<> *this_00;
  long *plVar1;
  uint uVar2;
  void *pvVar3;
  GameObject *pGVar4;
  int iVar5;
  GameObject **ppGVar6;
  undefined4 *puVar7;
  long lVar8;
  long lVar9;
  uint *puVar10;
  GameObject *pGVar11;
  long *plVar12;
  void *pvVar13;
  long *plVar14;
  long *plVar15;
  long lVar16;
  uint uVar17;
  undefined8 local_40;
  _Rb_tree<> a_Stack_38 [8];
  undefined4 local_30 [2];
  void *local_28;
  undefined4 *local_20;
  undefined4 *local_18;
  undefined8 local_10;
  long local_8;
  
  local_20 = local_30;
  local_30[0] = 0;
  ppGVar6 = (this->GJBaseGameLayer_data).m_unkdd8.capacity;
  local_8 = ___stack_chk_guard;
  local_28 = (void *)0x0;
  local_10 = 0;
  local_18 = local_20;
  if (ppGVar6 != (GameObject **)0x0) {
    pGVar11 = ppGVar6[7];
    uVar17 = *(uint *)&pGVar11->CCCopying;
    if (uVar17 != 0) {
      plVar15 = *(long **)&(pGVar11->CCObject_data).m_nTag;
      plVar1 = plVar15 + ((ulong)uVar17 - 1);
      if (plVar15 <= plVar1) {
        lVar16 = *plVar15;
        pGVar4 = local_40;
        while (local_40 = pGVar4, lVar16 != 0) {
          iVar5 = *(int *)(lVar16 + 0x3f4);
          local_40._4_4_ = (undefined4)((ulong)pGVar4 >> 0x20);
          if (iVar5 == 0x813) {
LAB_006d8920:
            local_40._0_4_ = *(int *)(lVar16 + 0x5a8);
            std::_Rb_tree<>::_M_insert_unique<int>(a_Stack_38,(int *)&local_40);
            local_40 = (GameObject *)CONCAT44(local_40._4_4_,*(undefined4 *)(lVar16 + 0x5ac));
            std::_Rb_tree<>::_M_insert_unique<int>(a_Stack_38,(int *)&local_40);
            pGVar4 = local_40;
          }
          else if (iVar5 < 0x814) {
            if (iVar5 == 0x543) {
              local_40 = (GameObject *)CONCAT44(local_40._4_4_,*(undefined4 *)(lVar16 + 0x5ac));
                    
              std::_Rb_tree<>::_M_insert_unique<int>(a_Stack_38,(int *)&local_40);
              pGVar4 = local_40;
            }
            else if ((iVar5 == 0x716) || (iVar5 == 0x542)) goto LAB_006d8920;
          }
          else if ((iVar5 == 0xbc8) || ((0xbc7 < iVar5 && (iVar5 - 0xbd8U < 2)))) goto LAB_006d8920;
          local_40 = pGVar4;
          plVar15 = plVar15 + 1;
          if (plVar1 < plVar15) break;
          pGVar4 = local_40;
          lVar16 = *plVar15;
        }
      }
    }
  }
  GJBaseGameLayer::addRemapTargets((GJBaseGameLayer *)this,(set *)a_Stack_38);
  if (local_20 != local_30) {
    puVar7 = local_20;
    do {
      lVar16 = GJBaseGameLayer::getGroup((GJBaseGameLayer *)this,puVar7[8]);
      pGVar4 = local_40;
      if (lVar16 != 0) {
        uVar17 = **(uint **)(lVar16 + 0x38);
        if (uVar17 != 0) {
          plVar15 = *(long **)(*(uint **)(lVar16 + 0x38) + 4);
          plVar1 = plVar15 + ((ulong)uVar17 - 1);
          for (; (plVar15 <= plVar1 &&
                 (local_40 = (GameObject *)*plVar15, local_40 != (GameObject *)0x0));
              plVar15 = plVar15 + 1) {
            if (local_40[0x530] == (GameObject)0x0) {
              plVar12 = *(long **)&(this->PlayLayer_data).field_0x110;
              plVar14 = *(long **)((long)&(this->PlayLayer_data).m_maxObjectX + 3);
              local_40[0x530] = (GameObject)0x1;
              if (plVar12 == plVar14) {
                std::vector<>::_M_emplace_back_aux<>
                          ((vector<> *)((long)&(this->PlayLayer_data).m_collectibles + 3),
                           (GameObject **)&local_40);
              }
              else {
                lVar16 = 0;
                if (plVar12 != (long *)0x0) {
                  *plVar12 = (long)local_40;
                  lVar16 = *(long *)&(this->PlayLayer_data).field_0x110;
                }
                *(long *)&(this->PlayLayer_data).field_0x110 = lVar16 + 8;
              }
            }
            pGVar4 = local_40;
          }
        }
      }
      local_40 = pGVar4;
      puVar7 = (undefined4 *)FUN_00dfab74(puVar7);
    } while (puVar7 != local_30);
  }
  iVar5 = cocos2d::CCArray::count((CCArray *)(this->GJBaseGameLayer_data).m_targetGroups.single);
  uVar17 = 0;
  pvVar3 = local_28;
  if (0 < iVar5 + -2) {
    this_00 = (vector<> *)((long)&(this->PlayLayer_data).m_collectibles + 3);
    do {
      lVar16 = cocos2d::CCArray::objectAtIndex
                         ((CCArray *)(this->GJBaseGameLayer_data).m_targetGroups.single,uVar17);
      lVar8 = cocos2d::CCArray::objectAtIndex
                        ((CCArray *)(this->GJBaseGameLayer_data).m_targetGroups.single,uVar17 + 1);
      lVar9 = cocos2d::CCArray::objectAtIndex
                        ((CCArray *)(this->GJBaseGameLayer_data).m_targetGroups.single,uVar17 + 2);
      pGVar4 = local_40;
      if (lVar16 != 0) {
        uVar2 = **(uint **)(lVar16 + 0x38);
        if (uVar2 != 0) {
          plVar15 = *(long **)(*(uint **)(lVar16 + 0x38) + 4);
          plVar1 = plVar15 + ((ulong)uVar2 - 1);
          for (; (plVar15 <= plVar1 &&
                 (local_40 = (GameObject *)*plVar15, local_40 != (GameObject *)0x0));
              plVar15 = plVar15 + 1) {
            if (local_40[0x530] == (GameObject)0x0) {
              plVar12 = *(long **)&(this->PlayLayer_data).field_0x110;
              plVar14 = *(long **)((long)&(this->PlayLayer_data).m_maxObjectX + 3);
              local_40[0x530] = (GameObject)0x1;
              if (plVar12 == plVar14) {
                std::vector<>::_M_emplace_back_aux<>(this_00,(GameObject **)&local_40);
              }
              else {
                lVar16 = 0;
                if (plVar12 != (long *)0x0) {
                  *plVar12 = (long)local_40;
                  lVar16 = *(long *)&(this->PlayLayer_data).field_0x110;
                }
                *(long *)&(this->PlayLayer_data).field_0x110 = lVar16 + 8;
              }
            }
            pGVar4 = local_40;
          }
        }
      }
      local_40 = pGVar4;
      pGVar4 = local_40;
      if (lVar8 != 0) {
        uVar2 = **(uint **)(lVar8 + 0x38);
        if (uVar2 != 0) {
          plVar15 = *(long **)(*(uint **)(lVar8 + 0x38) + 4);
          plVar1 = plVar15 + ((ulong)uVar2 - 1);
          for (; (plVar15 <= plVar1 &&
                 (local_40 = (GameObject *)*plVar15, local_40 != (GameObject *)0x0));
              plVar15 = plVar15 + 1) {
            if (local_40[0x530] == (GameObject)0x0) {
              plVar12 = *(long **)&(this->PlayLayer_data).field_0x110;
              plVar14 = *(long **)((long)&(this->PlayLayer_data).m_maxObjectX + 3);
              local_40[0x530] = (GameObject)0x1;
              if (plVar12 == plVar14) {
                std::vector<>::_M_emplace_back_aux<>(this_00,(GameObject **)&local_40);
              }
              else {
                lVar16 = 0;
                if (plVar12 != (long *)0x0) {
                  *plVar12 = (long)local_40;
                  lVar16 = *(long *)&(this->PlayLayer_data).field_0x110;
                }
                *(long *)&(this->PlayLayer_data).field_0x110 = lVar16 + 8;
              }
            }
            pGVar4 = local_40;
          }
        }
      }
      local_40 = pGVar4;
      if ((lVar9 != 0) && (lVar16 = *(long *)(lVar9 + 0x38), lVar16 != 0)) {
        lVar8 = *(long *)(lVar16 + 0x120);
        while( true ) {
          pGVar4 = local_40;
          if (*(long *)(lVar16 + 0x108) != 0) {
            puVar10 = *(uint **)(*(long *)(lVar16 + 0x108) + 0x38);
            uVar2 = *puVar10;
            if (uVar2 != 0) {
              plVar15 = *(long **)(puVar10 + 4);
              plVar1 = plVar15 + ((ulong)uVar2 - 1);
              for (; (plVar15 <= plVar1 &&
                     (local_40 = (GameObject *)*plVar15, local_40 != (GameObject *)0x0));
                  plVar15 = plVar15 + 1) {
                if (local_40[0x530] == (GameObject)0x0) {
                  plVar12 = *(long **)&(this->PlayLayer_data).field_0x110;
                  plVar14 = *(long **)((long)&(this->PlayLayer_data).m_maxObjectX + 3);
                  local_40[0x530] = (GameObject)0x1;
                  if (plVar12 == plVar14) {
                    std::vector<>::_M_emplace_back_aux<>(this_00,(GameObject **)&local_40);
                  }
                  else {
                    lVar16 = 0;
                    if (plVar12 != (long *)0x0) {
                      *plVar12 = (long)local_40;
                      lVar16 = *(long *)&(this->PlayLayer_data).field_0x110;
                    }
                    *(long *)&(this->PlayLayer_data).field_0x110 = lVar16 + 8;
                  }
                }
                pGVar4 = local_40;
              }
            }
          }
          local_40 = pGVar4;
          if (lVar8 == 0) break;
          lVar16 = lVar8;
          lVar8 = *(long *)(lVar8 + 0x120);
        }
      }
      uVar17 = uVar17 + 4;
      pvVar3 = local_28;
    } while ((int)uVar17 < iVar5 + -2);
  }
  while (pvVar3 != (void *)0x0) {
    std::_Rb_tree<>::_M_erase(a_Stack_38,*(_Rb_tree_node **)((long)pvVar3 + 0x18));
    pvVar13 = *(void **)((long)pvVar3 + 0x10);
    operator.delete(pvVar3);
    pvVar3 = pvVar13;
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




long * PlayLayer::scene(GJGameLevel *param_1,bool param_2,bool param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  plVar1 = (long *)cocos2d::CCScene::create();
  lVar2 = AppDelegate::get();
  *(long **)(lVar2 + 0x18) = plVar1;
  uVar3 = create(param_1,param_2,param_3);
  (**(code **)(*plVar1 + 0x1b8))(plVar1,uVar3);
  *(undefined4 *)((long)plVar1 + 0x1c) = 5;
  return plVar1;
}











void PlayLayer::setupHasCompleted(PlayLayer *this)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  GameManager GVar4;
  GameManager GVar5;
  byte bVar6;
  bool bVar7;
  uint uVar8;
  char cVar9;
  undefined8 *puVar10;
  GameObject **ppGVar11;
  GJEffectManager *this_00;
  long lVar12;
  GameManager *pGVar13;
  FMODAudioEngine *pFVar14;
  undefined8 uVar15;
  GameObject *pGVar16;
  MusicDownloadManager *this_01;
  char *pcVar17;
  CCTexture2D *this_02;
  ObjectToolbox *pOVar18;
  CCPoint *pCVar19;
  CCFiniteTimeAction *pCVar20;
  CCAction *pCVar21;
  CCDelayTime *this_03;
  CCCopying *pCVar22;
  GameObject **ppGVar23;
  CCNode *pCVar24;
  long *plVar25;
  GameObject *pGVar26;
  GJMGLayer *pGVar27;
  OBB2D *pOVar28;
  int *piVar29;
  code *pcVar30;
  float fVar31;
  float fVar32;
  float local_38;
  float local_34;
  long local_30;
  CCPoint local_28;
  CCPoint local_20;
  CCPoint local_18;
  float local_10;
  undefined4 local_c;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  GJBaseGameLayer::createTextLayers((GJBaseGameLayer *)this);
  GJBaseGameLayer::updateSpecialGroupData((GJBaseGameLayer *)this);
  optimizeColorGroups(this);
  optimizeOpacityGroups(this);
  scanDynamicSaveObjects(this);
  scanActiveSaveObjects(this);
  FUN_00e18d28(&local_18,
               &(((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_capacityString);
                    
  GJBaseGameLayer::updateLayerCapacity((GJBaseGameLayer *)this,&local_18);
  puVar10 = (undefined8 *)(CONCAT44(local_18.y,local_18.x) + -0x18);
  if (puVar10 != &DAT_0134b6b0) {
    piVar29 = (int *)(CONCAT44(local_18.y,local_18.x) + -8);
    do {
      iVar1 = *piVar29;
      cVar9 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar29,0x10);
      if (bVar7) {
        *piVar29 = iVar1 + -1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    if (iVar1 < 1) {
      operator.delete(puVar10);
    }
  }
  GJBaseGameLayer::increaseBatchNodeCapacity((GJBaseGameLayer *)this);
  ppGVar11 = (this->GJBaseGameLayer_data).m_unkdd8.last;
  if (ppGVar11 == (GameObject **)0x0) {
    ppGVar11 = (GameObject **)LevelSettingsObject::create((LevelSettingsObject *)0x0);
    (this->GJBaseGameLayer_data).m_unkdd8.last = ppGVar11;
    ppGVar11[0x30] = (GameObject *)(this->GJBaseGameLayer_data).m_level;
    cocos2d::CCObject::retain((CCObject *)(this->GJBaseGameLayer_data).m_unkdd8.last);
    ppGVar11 = (this->GJBaseGameLayer_data).m_unkdd8.last;
  }
  ppGVar23 = (this->GJBaseGameLayer_data).m_unkdd8.start;
  this_00 = (GJEffectManager *)ppGVar11[0x28];
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_unkdd0[9].CCCopying =
       *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
  *(undefined1 *)(ppGVar23 + 0x168) =
       *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
  lVar12 = GJEffectManager::getColorAction(this_00,0x3ed);
  pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
  *(undefined4 *)(lVar12 + 0x50) = 0;
  uVar2 = *(undefined1 *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 2);
  uVar3 = *(undefined1 *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 3);
  *(undefined1 *)(lVar12 + 0x4a) = *(undefined1 *)&pCVar24[8].CCNode_data.m_obAnchorPointInPoints.x;
  *(undefined1 *)(lVar12 + 0x48) = uVar2;
  *(undefined1 *)(lVar12 + 0x49) = uVar3;
  *(undefined1 *)(lVar12 + 0x54) = 1;
  pGVar13 = (GameManager *)
            GJEffectManager::getColorAction
                      ((GJEffectManager *)(this->GJBaseGameLayer_data).m_unkdd8.last[0x28],0x3ee);
  pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
  *(undefined4 *)(pGVar13 + 0x50) = 0;
  GVar4 = *(GameManager *)((long)&pCVar24[8].CCNode_data.m_obAnchorPointInPoints.x + 1);
  GVar5 = *(GameManager *)((long)&pCVar24[8].CCNode_data.m_obAnchorPointInPoints.x + 2);
  pGVar13[0x4a] = *(GameManager *)((long)&pCVar24[8].CCNode_data.m_obAnchorPointInPoints.x + 3);
  pGVar13[0x48] = GVar4;
  pGVar13[0x49] = GVar5;
  pGVar13[0x54] = (GameManager)0x1;
  lVar12 = GameManager::sharedState(pGVar13);
  uVar8 = *(int *)(lVar12 + 0x300) - *(int *)(lVar12 + 0x304);
  if (0 < (int)uVar8) {
    pGVar13 = (GameManager *)GameManager::sharedState((GameManager *)(ulong)uVar8);
    lVar12 = GameManager::sharedState(pGVar13);
    GameManager::loadDeathEffect(pGVar13,*(int *)(lVar12 + 0x300) - *(int *)(lVar12 + 0x304));
  }
  GJBaseGameLayer::createBackground
            ((GJBaseGameLayer *)this,*(int *)((this->GJBaseGameLayer_data).m_unkdd8.last + 0x2c));
  ppGVar11 = (this->GJBaseGameLayer_data).m_unkdd8.last;
  if (0 < *(int *)((long)ppGVar11 + 0x16c)) {
    GJBaseGameLayer::createMiddleground((GJBaseGameLayer *)this,*(int *)((long)ppGVar11 + 0x16c));
    ppGVar11 = (this->GJBaseGameLayer_data).m_unkdd8.last;
  }
  GJBaseGameLayer::createGroundLayer
            ((GJBaseGameLayer *)this,*(int *)((long)ppGVar11 + 0x164),*(int *)(ppGVar11 + 0x33));
  UILayer::togglePlatformerMode
            ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last,
             *(bool *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6));
  pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
  pOVar28 = (this->GJBaseGameLayer_data).m_cameraObb2;
  local_18.y = (float)*(byte *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 3) / 255.0;
  local_c = 0x3f800000;
  local_18.x = (float)*(byte *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 2) / 255.0;
  local_10 = (float)*(byte *)&pCVar24[8].CCNode_data.m_obAnchorPointInPoints.x / 255.0;
  (**(code **)(pOVar28->CCCopying + 0x540))(pOVar28,&local_18);
  pOVar28 = (this->GJBaseGameLayer_data).m_cameraObb2;
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_10 = 0.0;
  local_c = 0x3f800000;
  (**(code **)(pOVar28->CCCopying + 0x560))(pOVar28,&local_18);
  pFVar14 = (FMODAudioEngine *)GJBaseGameLayer::resetPlayer((GJBaseGameLayer *)this);
  uVar15 = FMODAudioEngine::sharedEngine(pFVar14);
  GJGameLevel::getAudioFileName();
                    
  FMODAudioEngine::loadMusic
            ((FMODAudioEngine *)0x3f800000,0,0x3f800000,uVar15,&local_18,1,0,0,
             *(undefined1 *)((long)(this->GJBaseGameLayer_data).m_unkdd8.last + 0x15e));
  puVar10 = (undefined8 *)(CONCAT44(local_18.y,local_18.x) + -0x18);
  if (puVar10 != &DAT_0134b6b0) {
    piVar29 = (int *)(CONCAT44(local_18.y,local_18.x) + -8);
    do {
      iVar1 = *piVar29;
      cVar9 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar29,0x10);
      if (bVar7) {
        *piVar29 = iVar1 + -1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    if (iVar1 < 1) {
      operator.delete(puVar10);
    }
  }
  pGVar16 = (this->GJBaseGameLayer_data).m_unkdd8.last[0x30];
  fVar31 = (pGVar16->CCSprite_data).m_obUnflippedOffsetPositionFromCenter.y;
  if ((fVar31 == 0.0) &&
     (uVar8 = (((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_audioTrack,
     pGVar16 = (GameObject *)(ulong)uVar8, (int)uVar8 < 0x14)) {
    pFVar14 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)pGVar16);
    pFVar14 = (FMODAudioEngine *)FMODAudioEngine::disableMetering(pFVar14);
  }
  else {
    pFVar14 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)pGVar16);
    FMODAudioEngine::enableMetering(pFVar14);
    *(undefined1 *)((long)&(this->PlayLayer_data).m_unk3918.x + 3) = 1;
    this_01 = (MusicDownloadManager *)MusicDownloadManager::sharedState();
    pFVar14 = (FMODAudioEngine *)MusicDownloadManager::incrementPriorityForSong(this_01,(int)fVar31)
    ;
  }
  pFVar14 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar14);
  fVar31 = (float)FMODAudioEngine::getBackgroundMusicVolume(pFVar14);
  uVar8 = (((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_audioTrack;
  *(bool *)((long)&(this->PlayLayer_data).m_orbs + 3) = fVar31 <= 0.0;
  LevelTools::getAudioString((LevelTools *)(ulong)uVar8,(uint)(fVar31 <= 0.0));
                    
  uVar15 = AudioEffectsLayer::create(&local_18);
  (this->GJBaseGameLayer_data).m_recordInputs = (bool)(char)uVar15;
  (this->GJBaseGameLayer_data).m_unk32a1 = (bool)(char)((ulong)uVar15 >> 8);
  (this->GJBaseGameLayer_data).m_unk32a2 = (bool)(char)((ulong)uVar15 >> 0x10);
  (this->GJBaseGameLayer_data).m_unk32a3 = (bool)(char)((ulong)uVar15 >> 0x18);
  (this->GJBaseGameLayer_data).m_unk32a4 = (bool)(char)((ulong)uVar15 >> 0x20);
  *(int3 *)&(this->GJBaseGameLayer_data).field_0x3135 = (int3)((ulong)uVar15 >> 0x28);
  puVar10 = (undefined8 *)(CONCAT44(local_18.y,local_18.x) + -0x18);
  if (puVar10 != &DAT_0134b6b0) {
    piVar29 = (int *)(CONCAT44(local_18.y,local_18.x) + -8);
    do {
      iVar1 = *piVar29;
      cVar9 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar29,0x10);
      if (bVar7) {
        *piVar29 = iVar1 + -1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    if (iVar1 < 1) {
      operator.delete(puVar10);
      uVar15._0_1_ = (this->GJBaseGameLayer_data).m_recordInputs;
      uVar15._1_1_ = (this->GJBaseGameLayer_data).m_unk32a1;
      uVar15._2_1_ = (this->GJBaseGameLayer_data).m_unk32a2;
      uVar15._3_1_ = (this->GJBaseGameLayer_data).m_unk32a3;
      uVar15._4_1_ = (this->GJBaseGameLayer_data).m_unk32a4;
      uVar15._5_3_ = *(undefined3 *)&(this->GJBaseGameLayer_data).field_0x3135;
    }
    else {
      uVar15._0_1_ = (this->GJBaseGameLayer_data).m_recordInputs;
      uVar15._1_1_ = (this->GJBaseGameLayer_data).m_unk32a1;
      uVar15._2_1_ = (this->GJBaseGameLayer_data).m_unk32a2;
      uVar15._3_1_ = (this->GJBaseGameLayer_data).m_unk32a3;
      uVar15._4_1_ = (this->GJBaseGameLayer_data).m_unk32a4;
      uVar15._5_3_ = *(undefined3 *)&(this->GJBaseGameLayer_data).field_0x3135;
    }
  }
  pGVar27 = (this->GJBaseGameLayer_data).m_middleground;
  (**(code **)(pGVar27->CCCopying + 0x1c0))(pGVar27,uVar15,1);
  plVar25 = *(long **)&(this->GJBaseGameLayer_data).m_recordInputs;
  pGVar13 = (GameManager *)(**(code **)(*plVar25 + 0x148))(plVar25,0);
  pGVar13 = (GameManager *)GameManager::sharedState(pGVar13);
  lVar12 = GameManager::sharedState(pGVar13);
  pcVar17 = (char *)GameManager::getFontFile(pGVar13,*(int *)(lVar12 + 0x36c));
  uVar15 = cocos2d::CCLabelBMFont::create("Attempt 1",pcVar17);
  *(undefined8 *)&(this->PlayLayer_data).field_0x1f0 = uVar15;
  pGVar27 = (this->GJBaseGameLayer_data).m_middleground;
  (**(code **)(pGVar27->CCCopying + 0x1c0))(pGVar27,uVar15,0x578);
  if (*(char *)((long)&(this->PlayLayer_data).m_infoLabel + 3) != '\0') {
    plVar25 = *(long **)&(this->PlayLayer_data).field_0x1f0;
    (**(code **)(*plVar25 + 0x90))(0xbf800000,plVar25);
  }
  uVar15 = cocos2d::CCLabelBMFont::create("","chatFont.fnt");
  this[1].CCNode_data.m_fScaleX = (float)(int)uVar15;
  this[1].CCNode_data.m_fScaleY = (float)(int)((ulong)uVar15 >> 0x20);
  (**(code **)(this->CCCopying + 0x1c0))(this,uVar15,1000);
  plVar25 = *(long **)&this[1].CCNode_data.m_fScaleX;
  pcVar30 = *(code **)(*plVar25 + 0x118);
  cocos2d::CCPoint::CCPoint(&local_18,0.0,1.0);
  (*pcVar30)(plVar25,&local_18);
  plVar25 = *(long **)&this[1].CCNode_data.m_fScaleX;
  pcVar30 = *(code **)(*plVar25 + 0xb8);
  cocos2d::CCPoint::CCPoint(&local_28,0.0,0.0);
  cocos2d::CCPoint::CCPoint(&local_20,5.0,local_34 - 10.0);
  cocos2d::CCPoint::operator+(&local_28,(CCPoint *)&local_20);
  (*pcVar30)(plVar25,&local_18);
  plVar25 = *(long **)&this[1].CCNode_data.m_fScaleX;
  (**(code **)(*plVar25 + 0x3f0))(plVar25,0xffffff96);
  plVar25 = *(long **)&this[1].CCNode_data.m_fScaleX;
  (**(code **)(*plVar25 + 0xa0))(0x3f000000,plVar25);
  updateInfoLabel(this);
  (**(code **)(this->CCCopying + 0x5f8))(this);
  if ((((*(char *)((long)(this->GJBaseGameLayer_data).m_unkdd8.last + 0x154) == '\0') ||
       (*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth != '\0')) ||
      ((((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_levelType == Editor)) ||
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0')) {
    fVar31 = 1.0;
  }
  else {
    plVar25 = *(long **)&(this->PlayLayer_data).field_0x1f0;
    fVar31 = 2.0;
    this_03 = (CCDelayTime *)(**(code **)(*plVar25 + 0x148))(plVar25,0);
    pCVar20 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create(this_03,0.5);
    uVar15 = cocos2d::CCCallFunc::create
                       ((CCCallFunc *)this,(CCObject *)showTwoPlayerGuide,(_func_void *)0x0);
    pCVar21 = (CCAction *)cocos2d::CCSequence::create(pCVar20,uVar15,0);
    cocos2d::CCNode::runAction((CCNode *)this,pCVar21);
  }
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 1) = 1;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 2) = 1;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_cameraWidth + 1) = 1;
  GJBaseGameLayer::updateCamera((GJBaseGameLayer *)this,0.0);
  uVar15 = cocos2d::CCSprite::create("slidergroove2.png");
  *(undefined8 *)((long)&(this->PlayLayer_data).m_bestAttemptTime + 3) = uVar15;
  (**(code **)(this->CCCopying + 0x1c0))(this,uVar15,10);
  plVar25 = (long *)cocos2d::CCSprite::create("sliderBar2.png");
  lVar12 = *plVar25;
  *(long **)((long)&(this->PlayLayer_data).m_pauseTime + 3) = plVar25;
  fVar32 = *(float *)(*(long *)((long)&(this->PlayLayer_data).m_bestAttemptTime + 3) + 0x1b0);
  local_18.x = 1.36332e-41;
  local_18.y = 1.36332e-41;
  pcVar30 = *(code **)(lVar12 + 0x420);
  local_10 = 1.47094e-41;
  local_c = 0x2901;
  *(undefined4 *)((long)&(this->PlayLayer_data).m_currentTime + 7) = 0x41000000;
  *(float *)((long)&(this->PlayLayer_data).m_currentTime + 3) = fVar32 - 4.0;
  this_02 = (CCTexture2D *)(*pcVar30)();
  cocos2d::CCTexture2D::setTexParameters(this_02,(_ccTexParams *)&local_18);
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_pauseTime + 3);
  pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
  local_20.x._1_1_ = *(undefined1 *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 3);
  local_20.x._2_1_ = *(undefined1 *)&pCVar24[8].CCNode_data.m_obAnchorPointInPoints.x;
  local_20.x._0_1_ = *(undefined1 *)((long)&pCVar24[8].CCNode_data.m_fSkewY + 2);
  (**(code **)(*plVar25 + 0x3b0))(plVar25,&local_20);
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_bestAttemptTime + 3);
  (**(code **)(*plVar25 + 0x1c0))
            (plVar25,*(undefined8 *)((long)&(this->PlayLayer_data).m_pauseTime + 3),0xffffffff);
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_pauseTime + 3);
  pcVar30 = *(code **)(*plVar25 + 0x118);
  cocos2d::CCPoint::CCPoint(&local_20,0.0,0.0);
  (*pcVar30)(plVar25,&local_20);
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_pauseTime + 3);
  pcVar30 = *(code **)(*plVar25 + 0xb8);
  cocos2d::CCPoint::CCPoint(&local_20,2.0,4.0);
  (*pcVar30)(plVar25,&local_20);
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_bestAttemptTime + 3);
  pcVar30 = *(code **)(*plVar25 + 0xb8);
  cocos2d::CCPoint::CCPoint(&local_20,local_38 * 0.5,local_34 - 8.0);
  (*pcVar30)(plVar25,&local_20);
  plVar25 = (long *)cocos2d::CCLabelBMFont::create("100%","bigFont.fnt");
  lVar12 = *plVar25;
  *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3) = plVar25;
  (**(code **)(lVar12 + 0xa0))(0x3f000000);
  (**(code **)(this->CCCopying + 0x1c0))
            (this,*(undefined8 *)((long)&(this->PlayLayer_data).m_unk38d0 + 3),0xf);
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
  pcVar30 = *(code **)(*plVar25 + 0xb8);
  cocos2d::CCPoint::CCPoint(&local_20,local_38 * 0.5 + 110.0,local_34 - 8.0);
  (*pcVar30)(plVar25,&local_20);
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
  pcVar30 = *(code **)(*plVar25 + 0x118);
  cocos2d::CCPoint::CCPoint(&local_20,0.0,0.5);
  (*pcVar30)(plVar25,&local_20);
  updateProgressbar(this);
  (**(code **)(this->CCCopying + 0x5f0))(this);
  if (((*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth == '\0') &&
      (ppGVar11 = (this->GJBaseGameLayer_data).m_unkdd8.last,
      *(char *)((long)ppGVar11 + 0x19d) == '\0')) && (*(int *)((long)ppGVar11 + 0x1ac) < 1)) {
    pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
    (**(code **)(pCVar24->CCCopying + 0x148))(pCVar24,0);
    ppGVar11 = (this->GJBaseGameLayer_data).m_unkdd8.start;
    (**(code **)&(*ppGVar11)->CCNodeRGBA_data)(ppGVar11,0);
    loadDefaultColors(this);
    GJBaseGameLayer::updateLevelColors((GJBaseGameLayer *)this);
    ppGVar11 = (this->GJBaseGameLayer_data).m_hazardCollisionObjects.start;
  }
  else {
    pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
    (**(code **)(pCVar24->CCCopying + 0x148))(pCVar24,1);
    ppGVar11 = (this->GJBaseGameLayer_data).m_unkdd8.start;
    (**(code **)&(*ppGVar11)->CCNodeRGBA_data)(ppGVar11,1);
    loadDefaultColors(this);
    GJBaseGameLayer::updateLevelColors((GJBaseGameLayer *)this);
    ppGVar11 = (this->GJBaseGameLayer_data).m_hazardCollisionObjects.start;
  }
  if (ppGVar11 == (GameObject **)0x0) {
    pGVar16 = (GameObject *)(this->GJBaseGameLayer_data).m_unkdd8.last;
  }
  else {
    pGVar16 = ppGVar11[0xe4];
  }
  GJBaseGameLayer::setupLevelStart((GJBaseGameLayer *)this,(LevelSettingsObject *)pGVar16);
  pCVar22 = this->CCCopying;
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_hazardCollisionObjectsCount = 1;
  (**(code **)(pCVar22 + 0x498))(0,this);
  GJBaseGameLayer::updateCamera((GJBaseGameLayer *)this,0.0);
  pGVar13 = (GameManager *)(**(code **)(this->CCCopying + 0x4f8))(this,0);
  pGVar13 = (GameManager *)GameManager::sharedState(pGVar13);
  pOVar18 = (ObjectToolbox *)GameManager::getGameVariable(pGVar13,"0072");
  *(char *)&this[1].CCNode_data.m_fRotationX = (char)pOVar18;
  pOVar18 = (ObjectToolbox *)ObjectToolbox::sharedState(pOVar18);
  uVar15 = ObjectToolbox::intKeyToFrame(pOVar18,8);
  FUN_00e153b8(&local_30,uVar15,&local_20);
                    
  plVar25 = (long *)GameObject::createWithKey(8);
  lVar12 = *plVar25;
  *(long **)((long)&(this->PlayLayer_data).m_statusLabel + 3) = plVar25;
  (**(code **)(lVar12 + 0x4e0))();
  pGVar16 = *(GameObject **)((long)&(this->PlayLayer_data).m_statusLabel + 3);
  FUN_00e18d28(&local_28,&local_30);
                    
  GameObject::addColorSprite(pGVar16,&local_28);
  if ((undefined8 *)((long)local_28 + -0x18) != &DAT_0134b6b0) {
    piVar29 = (int *)((long)local_28 + -8);
    do {
      iVar1 = *piVar29;
      cVar9 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar29,0x10);
      if (bVar7) {
        *piVar29 = iVar1 + -1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    if (iVar1 < 1) {
      operator.delete((undefined8 *)((long)local_28 + -0x18));
    }
  }
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_statusLabel + 3);
  pcVar30 = *(code **)(*plVar25 + 0x4e8);
                    
  FUN_00e18d28(&local_20,&local_30);
                    
  (*pcVar30)(plVar25,&local_20);
  lVar12 = CONCAT53(local_20._3_5_,
                    CONCAT12(local_20.x._2_1_,CONCAT11(local_20.x._1_1_,local_20.x._0_1_)));
  puVar10 = (undefined8 *)(lVar12 + -0x18);
  if (puVar10 != &DAT_0134b6b0) {
    piVar29 = (int *)(lVar12 + -8);
    do {
      iVar1 = *piVar29;
      cVar9 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar29,0x10);
      if (bVar7) {
        *piVar29 = iVar1 + -1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    if (iVar1 < 1) {
      operator.delete(puVar10);
    }
  }
  pCVar24 = (this->GJBaseGameLayer_data).m_unkdd0;
  plVar25 = *(long **)((long)&(this->PlayLayer_data).m_statusLabel + 3);
  pcVar30 = *(code **)(*plVar25 + 0x548);
                    
  pCVar19 = (CCPoint *)(**(code **)(pCVar24->CCCopying + 0xc0))(pCVar24);
  cocos2d::CCPoint::CCPoint(&local_20,pCVar19);
  (*pcVar30)(plVar25,&local_20);
  pGVar26 = *(GameObject **)((long)&(this->PlayLayer_data).m_statusLabel + 3);
  pGVar26[0x22f] = (GameObject)0x1;
  addObject(this,pGVar26);
  GJBaseGameLayer::createPlayerCollisionBlock((GJBaseGameLayer *)this);
  plVar25 = *(long **)&(this->PlayLayer_data).field_0x1f0;
  pcVar30 = *(code **)(*plVar25 + 0xb8);
  cocos2d::CCPoint::CCPoint
            (&local_20,(this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.x + local_38 * 0.5,
             (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.y + local_34 * 0.5 + 85.0);
  (*pcVar30)(plVar25,&local_20);
  if (*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth != '\0') {
    plVar25 = *(long **)&(this->PlayLayer_data).field_0x1f0;
    (**(code **)(*plVar25 + 0x3f0))(plVar25,0x32);
  }
  pCVar22 = this->CCCopying;
  *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_halfCameraWidth + 1) = 1;
  (**(code **)(pCVar22 + 0x618))(this);
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity = 0;
  prepareMusic(this,false);
  bVar6 = *(byte *)((long)&(this->PlayLayer_data).m_circleWaveArray + 3);
  if (bVar6 == 0) {
                    
    pCVar20 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create((CCDelayTime *)0x0,fVar31);
    uVar15 = cocos2d::CCCallFunc::create((CCCallFunc *)this,(CCObject *)onQuit,(_func_void *)0x0);
  }
  else {
    pCVar20 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create((CCDelayTime *)(ulong)bVar6,fVar31)
    ;
    uVar15 = cocos2d::CCCallFunc::create((CCCallFunc *)this,(CCObject *)startGame,(_func_void *)0x0)
    ;
  }
  pCVar21 = (CCAction *)cocos2d::CCSequence::create(pCVar20,uVar15,0);
  cocos2d::CCNode::runAction((CCNode *)this,pCVar21);
  cocos2d::CCNode::scheduleUpdate((CCNode *)this);
  GJBaseGameLayer::checkSpawnObjects((GJBaseGameLayer *)this);
  GJEffectManager::updateEffects
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,0.0);
  (**(code **)(this->CCCopying + 0x498))(0,this);
  GJBaseGameLayer::updateLevelColors((GJBaseGameLayer *)this);
  GJBaseGameLayer::updateProximityVolumeEffects((GJBaseGameLayer *)this);
  updateTestModeLabel(this);
  cVar9 = GJBaseGameLayer::shouldExitHackedLevel((GJBaseGameLayer *)this);
  if (cVar9 != '\0') {
                    
    removeAllObjects(this);
    onQuit(this);
  }
  if ((undefined8 *)(local_30 + -0x18) != &DAT_0134b6b0) {
    piVar29 = (int *)(local_30 + -8);
    do {
      iVar1 = *piVar29;
      cVar9 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(piVar29,0x10);
      if (bVar7) {
        *piVar29 = iVar1 + -1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    if (iVar1 < 1) {
      operator.delete((undefined8 *)(local_30 + -0x18));
    }
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::shouldBlend(PlayLayer *this,int param_1)

{
  GJEffectManager::shouldBlend
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,param_1);
  return;
}




char PlayLayer::shouldDebugDraw(PlayLayer *this)

{
  char cVar1;
  
  if (((*(char *)((long)&(this->PlayLayer_data).m_unk3768 + 3) == '\0') ||
      (cVar1 = *(char *)&(this->GJBaseGameLayer_data).m_endPortal, cVar1 == '\0')) &&
     (cVar1 = '\0', (this->PlayLayer_data).m_unk376d != false)) {
    cVar1 = *(char *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 2);
  }
  return cVar1;
}






void PlayLayer::showCompleteEffect(PlayLayer *this)

{
  undefined4 uVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  CCGridBase *pCVar8;
  long lVar9;
  CCFiniteTimeAction *pCVar10;
  undefined8 uVar11;
  CCAction *pCVar12;
  FMODAudioEngine *pFVar13;
  CCLightFlash *this_00;
  CCLightFlash *extraout_x0;
  GJGameLevel *pGVar14;
  int *piVar15;
  GJMGLayer *pGVar16;
  undefined8 in_x7;
  undefined1 uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined5 uStack_2d;
  float local_28;
  float local_24;
  CCPoint CStack_20;
  CCPoint CStack_18;
  long local_10;
  long local_8;
  
  pCVar8 = this[1].CCNode_data.m_pGrid;
  local_8 = ___stack_chk_guard;
  if (pCVar8 == (CCGridBase *)0x0) {
    uVar17 = 0;
  }
  else {
    uVar17 = (undefined1)pCVar8[0x20].CCObject_data.m_eObjType;
    uVar2 = *(byte *)((long)&pCVar8[0x20].CCObject_data.m_eObjType + 1);
    if ((uVar2 & uVar17) != 0) {
      bVar3 = *(byte *)((long)&pCVar8[0x20].CCObject_data.m_eObjType + 2);
      pCVar8 = (CCGridBase *)(ulong)bVar3;
      bVar5 = true;
      if (bVar3 != 0) goto LAB_006ca6e8;
    }
    bVar5 = false;
    if (uVar2 != 0) goto LAB_006ca6e8;
  }
  uVar11 = FMODAudioEngine::sharedEngine((FMODAudioEngine *)pCVar8);
  FUN_00e153b8(&local_10,"endStart_02.ogg",&CStack_20);
                    
  FMODAudioEngine::playEffect(uVar11,&local_10);
  if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
    piVar15 = (int *)(local_10 + -8);
    do {
      iVar7 = *piVar15;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar15,0x10);
      if (bVar5) {
        *piVar15 = iVar7 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (iVar7 < 1) {
      bVar5 = false;
      operator.delete((undefined8 *)(local_10 + -0x18));
      goto LAB_006ca6e8;
    }
  }
  bVar5 = false;
LAB_006ca6e8:
  lVar9 = *(long *)&(this->GJBaseGameLayer_data).m_cameraHeight;
  if ((lVar9 == 0) || (*(char *)(lVar9 + 0x540) == '\0')) {
    fVar21 = -90.0;
    fVar22 = 30.0;
  }
  else {
    fVar21 = 90.0;
    fVar22 = -30.0;
  }
  bVar3 = *(byte *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6);
  pCVar8 = (CCGridBase *)(ulong)bVar3;
  if ((bVar3 == 0) && (pCVar8 = this[1].CCNode_data.m_pGrid, pCVar8 == (CCGridBase *)0x0)) {
    uVar1 = 0x42340000;
    fVar23 = 1.0;
    fVar20 = 8.0;
  }
  else {
    fVar21 = 0.0;
    fVar23 = 0.5;
    uVar1 = 0x43340000;
    fVar20 = 16.0;
    fVar22 = fVar21;
  }
  if (uVar17 == 0) {
    cocos2d::CCDirector::sharedDirector();
    this_00 = (CCLightFlash *)cocos2d::CCDirector::getWinSize();
    fVar19 = (this->GJBaseGameLayer_data).m_gameState.m_cameraZoom;
    fVar18 = local_28 / fVar19;
    fVar19 = (local_24 / fVar19) * 0.5;
    fVar18 = fVar19 * fVar19 + fVar18 * fVar18;
    fVar19 = SQRT(fVar18);
    if (NAN(fVar19)) {
      fVar19 = sqrtf(fVar18);
      this_00 = extraout_x0;
    }
    lVar9 = CCLightFlash::create(this_00);
    pGVar16 = (this->GJBaseGameLayer_data).m_middleground;
    (**(code **)(pGVar16->CCCopying + 0x1c0))(pGVar16,lVar9,0);
    uVar11 = (**(code **)(this->CCCopying + 0x1f0))(this);
    *(undefined8 *)(lVar9 + 0x158) = uVar11;
    *(undefined4 *)(lVar9 + 0x160) = 100;
    getEndPosition();
    cocos2d::CCPoint::CCPoint(&CStack_18,fVar22,0.0);
    cocos2d::CCPoint::operator+(&CStack_20,(CCPoint *)&CStack_18);
    fVar18 = fVar23 * 0.04;
    CCLightFlash::playEffect
              (0x3f800000,0,0x41f00000,0x41a00000,fVar22 + fVar19 + 10.0,fVar23 * 0.18,fVar18,
               fVar23 * 0.195,lVar9,&local_10,
               CONCAT53(uStack_2d,
                        *(undefined3 *)
                         ((long)&(this->GJBaseGameLayer_data).m_unkdd0[8].CCNode_data.m_fSkewY + 2))
               ,(int)fVar20,1,0,0x3ecccccd,in_x7,fVar18,fVar18,fVar21,uVar1,0x431b0000,0x42c80000,
               0x3ecccccd);
    uVar17 = *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 1);
    *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 1) = 0;
    pCVar8 = (CCGridBase *)
             GJBaseGameLayer::shakeCamera
                       ((GJBaseGameLayer *)this,(fVar20 + 2.0) * 0.195 * fVar23,3.0,0.0);
    *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 1) = uVar17;
  }
  if (bVar5) {
    pFVar13 = (FMODAudioEngine *)showCompleteText(this);
  }
  else {
    pCVar10 = (CCFiniteTimeAction *)
              cocos2d::CCDelayTime::create((CCDelayTime *)pCVar8,(fVar20 + 2.0) * 0.195 * fVar23);
    uVar11 = cocos2d::CCCallFunc::create
                       ((CCCallFunc *)this,(CCObject *)showCompleteText,(_func_void *)0x0);
    pCVar12 = (CCAction *)cocos2d::CCSequence::create(pCVar10,uVar11,0);
    pFVar13 = (FMODAudioEngine *)cocos2d::CCNode::runAction((CCNode *)this,pCVar12);
  }
  pFVar13 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine(pFVar13);
  lVar9 = FMODAudioEngine::getActiveMusicChannel(pFVar13,0);
  if (lVar9 != 0) {
    FMOD::Channel::setLoopCount((int)lVar9);
  }
  bVar3 = *(byte *)((long)(this->GJBaseGameLayer_data).m_unkdd8.last + 0x15d);
  pFVar13 = (FMODAudioEngine *)(ulong)bVar3;
  if ((bVar3 != 0) ||
     (pGVar14 = (this->GJBaseGameLayer_data).m_level,
     uVar6 = (pGVar14->GJGameLevel_data).m_levelID.random -
             (pGVar14->GJGameLevel_data).m_levelID.seed, pFVar13 = (FMODAudioEngine *)(ulong)uVar6,
     uVar6 == 0xbb9)) {
    iVar7 = FMODAudioEngine::sharedEngine(pFVar13);
    FMODAudioEngine::fadeOutMusic(2.0,iVar7);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void PlayLayer::showCompleteText(PlayLayer *this)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  CCGridBase *pCVar4;
  char *pcVar5;
  CCNode *this_00;
  CCScaleTo *pCVar6;
  CCEaseElasticOut *this_01;
  CCDelayTime *pCVar7;
  CCEaseIn *this_02;
  CCHide *this_03;
  undefined8 uVar8;
  undefined8 uVar9;
  CCAction *pCVar10;
  CCPoint *pCVar11;
  long *plVar12;
  long *plVar13;
  CCDirector *this_04;
  CCFiniteTimeAction *pCVar14;
  CCNode *pCVar15;
  GJMGLayer *pGVar16;
  int iVar17;
  code *pcVar18;
  undefined1 uVar19;
  float fVar20;
  float local_30;
  float local_2c;
  CCPoint CStack_28;
  CCPoint CStack_20;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  long local_8;
  
  pCVar4 = this[1].CCNode_data.m_pGrid;
  local_8 = ___stack_chk_guard;
  if (pCVar4 == (CCGridBase *)0x0) {
    uVar19 = 0;
  }
  else {
    uVar19 = (undefined1)pCVar4[0x20].CCObject_data.m_eObjType;
  }
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  cocos2d::CCPoint::CCPoint(&CStack_28,local_30 * 0.5,local_2c * 0.5 + 35.0);
  if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
    fVar20 = 1.1;
    pcVar5 = "GJ_levelComplete_001.png";
  }
  else {
    fVar20 = 1.0;
    pcVar5 = "GJ_practiceComplete_001.png";
  }
  this_00 = (CCNode *)cocos2d::CCSprite::createWithSpriteFrameName(pcVar5);
  (**(code **)(this->CCCopying + 0x1c0))(this,this_00,0xf);
  (**(code **)(this_00->CCCopying + 0xb8))(this_00,&CStack_28);
  pCVar6 = (CCScaleTo *)(**(code **)(this_00->CCCopying + 0xa0))(0x3c23d70a,this_00);
  this_01 = (CCEaseElasticOut *)cocos2d::CCScaleTo::create(pCVar6,0.66,fVar20);
  pCVar7 = (CCDelayTime *)cocos2d::CCEaseElasticOut::create(this_01,0.6);
  pCVar6 = (CCScaleTo *)cocos2d::CCDelayTime::create(pCVar7,0.88000005);
  this_02 = (CCEaseIn *)cocos2d::CCScaleTo::create(pCVar6,0.22000001,0.01,0.01);
  this_03 = (CCHide *)cocos2d::CCEaseIn::create(this_02,2.0);
  uVar8 = cocos2d::CCHide::create(this_03);
  uVar9 = cocos2d::CCCallFunc::create((CCCallFunc *)this_00,(CCObject *)0x208,(_func_void *)0x1);
  pCVar10 = (CCAction *)
            cocos2d::CCSequence::create((CCFiniteTimeAction *)pCVar7,pCVar6,this_03,uVar8,uVar9,0);
  cocos2d::CCNode::runAction(this_00,pCVar10);
  pCVar11 = (CCPoint *)(**(code **)(this_00->CCCopying + 0xc0))(this_00);
  cocos2d::CCPoint::CCPoint(&CStack_20,pCVar11);
  plVar12 = (long *)cocos2d::CCParticleSystemQuad::create("levelComplete01.plist",false);
  (**(code **)(*plVar12 + 0x620))(plVar12,1);
  (**(code **)(this->CCCopying + 0x1c0))(this,plVar12,0xd);
  (**(code **)(*plVar12 + 0xb8))(plVar12,&CStack_20);
  pCVar15 = (this->GJBaseGameLayer_data).m_unkdd0;
  local_c = 0x3f800000;
  local_14 = (float)*(byte *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 3) / 255.0;
  local_10 = (float)*(byte *)&pCVar15[8].CCNode_data.m_obAnchorPointInPoints.x / 255.0;
  local_18 = (float)*(byte *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 2) / 255.0;
  (**(code **)(*plVar12 + 0x540))(plVar12,&local_18);
  pCVar15 = (this->GJBaseGameLayer_data).m_unkdd0;
  local_c = 0x3f800000;
  local_10 = (float)*(byte *)&pCVar15[8].CCNode_data.m_obAnchorPointInPoints.x / 255.0;
  local_14 = (float)*(byte *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 3) / 255.0;
  local_18 = (float)*(byte *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 2) / 255.0;
  (**(code **)(*plVar12 + 0x560))(plVar12,&local_18);
  plVar13 = (long *)cocos2d::CCParticleSystemQuad::create("levelComplete01.plist",false);
  (**(code **)(*plVar13 + 0x620))(plVar13,1);
  (**(code **)(this->CCCopying + 0x1c0))(this,plVar13,0xd);
  pcVar18 = *(code **)(*plVar13 + 0xb8);
  uVar8 = (**(code **)(*plVar12 + 0xc0))(plVar12);
  pCVar7 = (CCDelayTime *)(*pcVar18)(plVar13,uVar8);
  if ((uVar19 == 0) &&
     (bVar1 = *(byte *)&(this->GJBaseGameLayer_data).m_endPortal,
     pCVar7 = (CCDelayTime *)(ulong)bVar1, bVar1 == 0)) {
    this_04 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
    fVar20 = (float)cocos2d::CCDirector::getScreenRight(this_04);
    iVar17 = 0;
    plVar12 = (long *)CCCircleWave::create(10.0,fVar20,0.8,false);
    pCVar15 = (this->GJBaseGameLayer_data).m_unkdd0;
    *(undefined4 *)((long)plVar12 + 0x164) = 4;
    uVar19 = *(undefined1 *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 2);
    uVar2 = *(undefined1 *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 3);
    *(undefined1 *)((long)plVar12 + 0x156) =
         *(undefined1 *)&pCVar15[8].CCNode_data.m_obAnchorPointInPoints.x;
    *(undefined1 *)((long)plVar12 + 0x154) = uVar19;
    *(undefined1 *)((long)plVar12 + 0x155) = uVar2;
    pcVar18 = *(code **)(*plVar12 + 0xb8);
    getEndPosition();
    (*pcVar18)(plVar12,&local_18);
    pGVar16 = (this->GJBaseGameLayer_data).m_middleground;
    (**(code **)(pGVar16->CCCopying + 0x1c0))(pGVar16,plVar12,0);
    plVar12 = (long *)CCCircleWave::create(10.0,250.0,0.8,false);
    pCVar15 = (this->GJBaseGameLayer_data).m_unkdd0;
    *(undefined4 *)((long)plVar12 + 0x164) = 4;
    uVar19 = *(undefined1 *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 2);
    uVar2 = *(undefined1 *)((long)&pCVar15[8].CCNode_data.m_fSkewY + 3);
    *(undefined1 *)((long)plVar12 + 0x156) =
         *(undefined1 *)&pCVar15[8].CCNode_data.m_obAnchorPointInPoints.x;
    *(undefined1 *)((long)plVar12 + 0x154) = uVar19;
    *(undefined1 *)((long)plVar12 + 0x155) = uVar2;
    pcVar18 = *(code **)(*plVar12 + 0xb8);
    uVar8 = (**(code **)(this_00->CCCopying + 0xc0))(this_00);
    (*pcVar18)(plVar12,uVar8);
    pCVar7 = (CCDelayTime *)(**(code **)(this->CCCopying + 0x1c0))(this,plVar12,9);
    do {
      fVar20 = (float)iVar17;
      iVar17 = iVar17 + 1;
      pCVar14 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create(pCVar7,fVar20 * 0.05);
      uVar8 = cocos2d::CCCallFunc::create
                        ((CCCallFunc *)this,(CCObject *)spawnCircle,(_func_void *)0x0);
      pCVar10 = (CCAction *)cocos2d::CCSequence::create(pCVar14,uVar8,0);
      pCVar7 = (CCDelayTime *)cocos2d::CCNode::runAction((CCNode *)this,pCVar10);
    } while (iVar17 != 5);
    iVar17 = 0;
    do {
      uVar3 = rand();
      fVar20 = (float)iVar17;
      iVar17 = iVar17 + 1;
      pCVar14 = (CCFiniteTimeAction *)
                cocos2d::CCDelayTime::create
                          ((CCDelayTime *)(ulong)uVar3,
                           ((float)(int)uVar3 * 4.656613e-10 * 2.0 + -1.0) * 0.08 + fVar20 * 0.15);
      uVar8 = cocos2d::CCCallFunc::create
                        ((CCCallFunc *)this,(CCObject *)spawnFirework,(_func_void *)0x0);
      pCVar10 = (CCAction *)cocos2d::CCSequence::create(pCVar14,uVar8,0);
      pCVar7 = (CCDelayTime *)cocos2d::CCNode::runAction((CCNode *)this,pCVar10);
    } while (iVar17 != 10);
  }
  pCVar14 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create(pCVar7,1.5);
  uVar8 = cocos2d::CCCallFunc::create((CCCallFunc *)this,(CCObject *)showEndLayer,(_func_void *)0x0)
  ;
  pCVar10 = (CCAction *)cocos2d::CCSequence::create(pCVar14,uVar8,0);
  cocos2d::CCNode::runAction((CCNode *)this,pCVar10);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::showEndLayer(PlayLayer *this)

{
  long *plVar1;
  
  PlatformToolbox::showCursor();
  PlayerObject::releaseAllButtons((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
  UILayer::resetAllButtons
            ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
  UILayer::toggleMenuVisibility
            ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last,false);
  *(undefined1 *)&(this->PlayLayer_data).m_keyPulses.m_bits.last = 1;
  plVar1 = (long *)EndLevelLayer::create((EndLevelLayer *)this);
  (**(code **)(this->CCCopying + 0x1c0))(this,plVar1,0x3e9);
  (**(code **)(*plVar1 + 0x520))(plVar1,0);
  return;
}





void PlayLayer::showHint(PlayLayer *this)

{
  int iVar1;
  char *pcVar2;
  CCNode *this_00;
  CCFadeIn *this_01;
  CCDelayTime *this_02;
  CCFadeOut *this_03;
  undefined8 uVar3;
  undefined8 uVar4;
  CCAction *pCVar5;
  GJGameLevel *pGVar6;
  code *pcVar7;
  undefined4 uVar8;
  float fVar9;
  float local_18;
  float local_14;
  CCPoint CStack_10;
  long local_8;
  
  *(undefined1 *)((long)&(this->PlayLayer_data).m_attemptTime + 4) = 1;
  local_8 = ___stack_chk_guard;
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  pGVar6 = (this->GJBaseGameLayer_data).m_level;
  iVar1 = (pGVar6->GJGameLevel_data).m_levelID.random - (pGVar6->GJGameLevel_data).m_levelID.seed;
  if ((iVar1 == 1) || (iVar1 == 0x3e9)) {
    uVar8 = 0x3f333333;
    pcVar2 = "Tap to jump over the spikes";
    fVar9 = 3.0;
  }
  else {
    uVar8 = 0x3f19999a;
    fVar9 = 4.0;
    pcVar2 = "Tap while touching a ring to jump mid air";
  }
  this_00 = (CCNode *)cocos2d::CCLabelBMFont::create(pcVar2,"bigFont.fnt");
  (**(code **)(this_00->CCCopying + 0xa0))(uVar8);
  (**(code **)(this->CCCopying + 0x1c0))(this,this_00,3);
  pcVar7 = *(code **)(this_00->CCCopying + 0xb8);
  cocos2d::CCPoint::CCPoint(&CStack_10,local_18 * 0.5,local_14 * 0.5 + 60.0);
  (*pcVar7)(this_00,&CStack_10);
  this_01 = (CCFadeIn *)(**(code **)(this_00->CCCopying + 0x3f0))(this_00,0);
  this_02 = (CCDelayTime *)cocos2d::CCFadeIn::create(this_01,0.5);
  this_03 = (CCFadeOut *)cocos2d::CCDelayTime::create(this_02,fVar9);
  uVar3 = cocos2d::CCFadeOut::create(this_03,0.5);
  uVar4 = cocos2d::CCCallFunc::create((CCCallFunc *)this_00,(CCObject *)0x208,(_func_void *)0x1);
  pCVar5 = (CCAction *)
           cocos2d::CCSequence::create((CCFiniteTimeAction *)this_02,this_03,uVar3,uVar4,0);
  cocos2d::CCNode::runAction(this_00,pCVar5);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}









void
PlayLayer::showNewBest
          (PlayLayer *this,bool param_1,int param_2,int param_3,bool param_4,bool param_5,
          bool param_6)

{
  bool bVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  CCNode *pCVar6;
  long *plVar7;
  CCString *pCVar8;
  char *pcVar9;
  long *plVar10;
  CCPoint *pCVar11;
  float *pfVar12;
  FMODAudioEngine *pFVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  long lVar16;
  CCScaleTo *pCVar17;
  CCEaseElasticOut *this_00;
  CCDelayTime *pCVar18;
  CCEaseIn *this_01;
  CCHide *this_02;
  undefined8 uVar19;
  CCAction *pCVar20;
  undefined8 uVar21;
  uchar extraout_w1;
  uchar extraout_w1_00;
  int *piVar22;
  code *pcVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  float local_28;
  float local_24;
  CCPoint CStack_20;
  CCPoint local_18;
  CCPoint local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (param_2 + param_3 < 1) {
    cocos2d::CCDirector::sharedDirector();
    cocos2d::CCDirector::getWinSize();
    fVar30 = 0.7;
    fVar27 = 0.0;
  }
  else {
    cocos2d::CCDirector::sharedDirector();
    cocos2d::CCDirector::getWinSize();
    fVar30 = 1.3;
    fVar27 = 10.0;
  }
  cocos2d::CCPoint::CCPoint(&CStack_20,local_28 * 0.5,local_24 * 0.5 + 20.0 + fVar27);
  pCVar6 = (CCNode *)cocos2d::CCNode::create();
  (**(code **)(this->CCCopying + 0x1c0))(this,pCVar6,100);
  (**(code **)(pCVar6->CCCopying + 0xb8))(pCVar6,&CStack_20);
  if (!param_6) {
    cVar2 = *(char *)((long)&(this->PlayLayer_data).m_infoLabel + 3);
    if (param_1) {
      if (cVar2 != '\0') goto LAB_006cb1f0;
      plVar7 = (long *)cocos2d::CCLabelBMFont::create("New Reward!","goldFont.fnt");
      (**(code **)(*plVar7 + 0xa0))(0x3f99999a);
      pcVar23 = *(code **)(*plVar7 + 0xb8);
      cocos2d::CCPoint::CCPoint(&local_10,0.0,5.0);
      (*pcVar23)(plVar7,&local_10);
      pcVar23 = *(code **)(*plVar7 + 0x118);
      cocos2d::CCPoint::CCPoint(&local_10,0.5,0.0);
      (*pcVar23)(plVar7,&local_10);
      (**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar7);
    }
    else if (cVar2 == '\0') {
      plVar7 = (long *)cocos2d::CCSprite::createWithSpriteFrameName("GJ_newBest_001.png");
      (**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar7);
      pcVar23 = *(code **)(*plVar7 + 0x118);
      cocos2d::CCPoint::CCPoint(&local_10,0.5,0.0);
      (*pcVar23)(plVar7,&local_10);
    }
    else {
LAB_006cb1f0:
      FUN_00e153b8(&local_18,&DAT_00fa37f0,&local_10);
      iVar5 = rand();
      switch((int)((float)iVar5 * 4.656613e-10 * 90.0)) {
      case 1:
        FUN_00e1798c(&local_18,"Y u die?",8);
        break;
      case 2:
        FUN_00e1798c(&local_18,"Not 100%",8);
        break;
      case 3:
        FUN_00e1798c(&local_18,"Try jump?",9);
        break;
      case 4:
        FUN_00e1798c(&local_18,"Kappa",5);
        break;
      case 5:
      case 0x24:
                    
        FUN_00e1798c(&local_18,"Too slow",8);
        break;
      case 6:
        FUN_00e1798c(&local_18,"Ples omg why no",0xf);
        break;
      case 7:
        FUN_00e1798c(&local_18,"Maybe jump?",0xb);
        break;
      case 8:
        FUN_00e1798c(&local_18,"Problem?",8);
        break;
      case 9:
        FUN_00e1798c(&local_18,"Nice crash",10);
        break;
      case 10:
        FUN_00e1798c(&local_18,"Try again?",10);
        break;
      case 0xb:
        FUN_00e1798c(&local_18,"Almost...",9);
        break;
      case 0xc:
        FUN_00e1798c(&local_18,"Hehe...",7);
        break;
      case 0xd:
        FUN_00e1798c(&local_18,"U no like?",10);
        break;
      case 0xe:
        FUN_00e1798c(&local_18,&DAT_00fa37f0,3);
        break;
      case 0xf:
        FUN_00e1798c(&local_18,"Rage time?",10);
        break;
      case 0x10:
        FUN_00e1798c(&local_18,"One more?",9);
        break;
      case 0x11:
        FUN_00e1798c(&local_18,"Noscope",7);
        break;
      case 0x12:
        FUN_00e1798c(&local_18,"Feel the pain",0xd);
        break;
      case 0x13:
        FUN_00e1798c(&local_18,"Over 1%!",8);
        break;
      case 0x14:
        FUN_00e1798c(&local_18,"BOOM!",5);
        break;
      case 0x15:
        FUN_00e1798c(&local_18,"Click faster",0xc);
        break;
      case 0x16:
        FUN_00e1798c(&local_18,"Dont be sad",0xb);
        break;
      case 0x17:
        FUN_00e1798c(&local_18,"Go again",8);
        break;
      case 0x18:
        FUN_00e1798c(&local_18,"So close",8);
        break;
      case 0x19:
        FUN_00e1798c(&local_18,"What!?",6);
        break;
      case 0x1a:
        FUN_00e1798c(&local_18,"You ok?",7);
        break;
      case 0x1b:
        FUN_00e1798c(&local_18,"Did he died?",0xc);
        break;
      case 0x1c:
        FUN_00e1798c(&local_18,&DAT_00fa3958,3);
        break;
      case 0x1d:
        FUN_00e1798c(&local_18,"Game Over",9);
        break;
      case 0x1e:
        FUN_00e1798c(&local_18,&DAT_00fa3970,3);
        break;
      case 0x1f:
        FUN_00e1798c(&local_18,"RubRub?",7);
        break;
      case 0x20:
        FUN_00e1798c(&local_18,"You Died",8);
        break;
      case 0x21:
        FUN_00e1798c(&local_18,"Continue?",9);
        break;
      case 0x22:
        FUN_00e1798c(&local_18,&DAT_00fa39a0,4);
        break;
      case 0x23:
        FUN_00e1798c(&local_18,"Wrong button",0xc);
        break;
      case 0x25:
        FUN_00e1798c(&local_18,"Insert coin",0xb);
        break;
      case 0x26:
        FUN_00e1798c(&local_18,"You Lose",8);
        break;
      case 0x27:
        FUN_00e1798c(&local_18,"Combo Breaker!",0xe);
        break;
      case 0x28:
        FUN_00e1798c(&local_18,"Time\'s Up!",10);
        break;
      case 0x29:
        FUN_00e1798c(&local_18,&DAT_00fa39f8,4);
        break;
      case 0x2a:
        FUN_00e1798c(&local_18,"VAMOS",5);
        break;
      case 0x2b:
        FUN_00e1798c(&local_18,"Not ok",6);
        break;
      case 0x2c:
        FUN_00e1798c(&local_18,"Dead, you are",0xd);
        break;
      case 0x2d:
        FUN_00e1798c(&local_18,"Slow down",9);
        break;
      case 0x2e:
        FUN_00e1798c(&local_18,"Nice try",8);
        break;
      case 0x2f:
        FUN_00e1798c(&local_18,"Take a break",0xc);
        break;
      case 0x30:
        FUN_00e1798c(&local_18,"Explosion!",10);
        break;
      case 0x31:
        FUN_00e1798c(&local_18,"So random",9);
        break;
      case 0x32:
        FUN_00e1798c(&local_18,"...",3);
        break;
      case 0x33:
        FUN_00e1798c(&local_18,"Is that it?",0xb);
        break;
      case 0x34:
        FUN_00e1798c(&local_18,"Not even close",0xe);
        break;
      case 0x35:
        FUN_00e1798c(&local_18,"Give up",7);
        break;
      case 0x36:
        FUN_00e1798c(&local_18,"Hotel?",6);
        break;
      case 0x37:
        FUN_00e1798c(&local_18,"liaf uoy",8);
        break;
      case 0x38:
        FUN_00e1798c(&local_18,"Go home",7);
        break;
      case 0x39:
        FUN_00e1798c(&local_18,"Spam?",5);
        break;
      case 0x3a:
        FUN_00e1798c(&local_18,"Try harder",10);
        break;
      case 0x3b:
        FUN_00e1798c(&local_18,"PogChamp",8);
        break;
      case 0x3c:
        FUN_00e1798c(&local_18,"Hang in there",0xd);
        break;
      case 0x3d:
        FUN_00e1798c(&local_18,"That\'s progress for ya",0x16);
        break;
      case 0x3e:
        FUN_00e1798c(&local_18,"Unlucky",7);
        break;
      case 0x3f:
        FUN_00e1798c(&local_18,"Why tho?",8);
        break;
      case 0x40:
        FUN_00e1798c(&local_18,"Nope!",5);
        break;
      case 0x41:
        FUN_00e1798c(&local_18,"Brutal",6);
        break;
      case 0x42:
        FUN_00e1798c(&local_18,"Not like this",0xd);
        break;
      case 0x43:
        FUN_00e1798c(&local_18,"Oopsie",6);
        break;
      case 0x44:
        FUN_00e1798c(&local_18,"Crushed",7);
        break;
      case 0x45:
        FUN_00e1798c(&local_18,"A for effort",0xc);
        break;
      case 0x46:
        FUN_00e1798c(&local_18,"Denied",6);
        break;
      case 0x47:
        FUN_00e1798c(&local_18,"So far, so bad",0xe);
        break;
      case 0x48:
        FUN_00e1798c(&local_18,"Was that the plan?",0x12);
        break;
      case 0x49:
        FUN_00e1798c(&local_18,"Spike loves you.",0x10);
        break;
      case 0x4a:
        FUN_00e1798c(&local_18,"Spike: 1, You: 0",0x10);
        break;
      case 0x4b:
        FUN_00e1798c(&local_18,"Need a Map?",0xb);
        break;
      case 0x4c:
        FUN_00e1798c(&local_18,"Who put that there?",0x13);
        break;
      case 0x4d:
        FUN_00e1798c(&local_18,"That looked painful",0x13);
        break;
      case 0x4e:
        FUN_00e1798c(&local_18,"Don\'t quit your day job",0x17);
        break;
      case 0x4f:
        FUN_00e1798c(&local_18,"Again? Really?",0xe);
        break;
      case 0x50:
        FUN_00e1798c(&local_18,"Stop testing gravity",0x14);
        break;
      case 0x51:
        FUN_00e1798c(&local_18,"I blame 240fps",0xe);
        break;
      case 0x52:
        FUN_00e1798c(&local_18,"Wrong way!",10);
        break;
      case 0x53:
        FUN_00e1798c(&local_18,"RobTop pls fix!",0xf);
        break;
      case 0x54:
        FUN_00e1798c(&local_18,"Who buffed this?",0x10);
        break;
      case 0x55:
        FUN_00e1798c(&local_18,"Geometry Dash\'nt",0x10);
        break;
      case 0x56:
        FUN_00e1798c(&local_18,"I like that part",0x10);
        break;
      case 0x57:
        FUN_00e1798c(&local_18,"Checkpoints, pls",0x10);
        break;
      case 0x58:
        FUN_00e1798c(&local_18,"Why jump there?",0xf);
        break;
      case 0x59:
        FUN_00e1798c(&local_18,"Who said GO?!",0xd);
        break;
      case 0x5a:
        FUN_00e1798c(&local_18,"New Best\'nt",0xb);
      }
                    
      plVar7 = (long *)cocos2d::CCLabelBMFont::create((char *)local_18,"goldFont.fnt");
      (**(code **)(*plVar7 + 0xa0))(0x3f99999a);
      pcVar23 = *(code **)(*plVar7 + 0xb8);
      cocos2d::CCPoint::CCPoint(&local_10,0.0,5.0);
      (*pcVar23)(plVar7,&local_10);
      pcVar23 = *(code **)(*plVar7 + 0x118);
      cocos2d::CCPoint::CCPoint(&local_10,0.5,0.0);
      (*pcVar23)(plVar7,&local_10);
      (**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar7);
      if ((char *)((long)local_18 + -0x18) != (char *)&DAT_0134b6b0) {
        piVar22 = (int *)((long)local_18 + -8);
        do {
          iVar5 = *piVar22;
          cVar2 = '\x01';
          bVar1 = (bool)ExclusiveMonitorPass(piVar22,0x10);
          if (bVar1) {
            *piVar22 = iVar5 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (iVar5 < 1) {
          operator.delete((char *)((long)local_18 + -0x18));
        }
      }
    }
  }
  pCVar8 = (CCString *)
           cocos2d::CCString::createWithFormat
                     ("%i%%",(ulong)*(uint *)((long)&(this->PlayLayer_data).m_keyPulses.m_bits.last
                                             + 3));
  pcVar9 = (char *)cocos2d::CCString::getCString(pCVar8);
  plVar7 = (long *)cocos2d::CCLabelBMFont::create(pcVar9,"bigFont.fnt");
  pcVar23 = *(code **)(*plVar7 + 0x118);
  cocos2d::CCPoint::CCPoint(&local_10,0.5,1.0);
  (*pcVar23)(plVar7,&local_10);
  (**(code **)(*plVar7 + 0xa0))(0x3f8ccccd,plVar7);
  pcVar23 = *(code **)(*plVar7 + 0xb8);
  cocos2d::CCPoint::CCPoint(&local_10,0.0,-4.0);
  (*pcVar23)(plVar7,&local_10);
  (**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar7);
  bVar1 = param_3 < 1;
  if (param_2 < 1) {
    if (bVar1) goto LAB_006cb308;
    fVar27 = -5.0;
LAB_006cacb8:
    pCVar8 = (CCString *)cocos2d::CCString::createWithFormat("+%i",(ulong)(uint)param_3);
    pcVar9 = (char *)cocos2d::CCString::getCString(pCVar8);
    plVar7 = (long *)cocos2d::CCLabelBMFont::create(pcVar9,"bigFont.fnt");
    (**(code **)(*plVar7 + 0xa0))(0x3f19999a);
    (**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar7);
    plVar10 = (long *)cocos2d::CCSprite::createWithSpriteFrameName("GJ_bigDiamond_001.png");
    pcVar23 = *(code **)(*plVar10 + 0x118);
    cocos2d::CCPoint::CCPoint(&local_10,0.0,0.5);
    (*pcVar23)(plVar10,&local_10);
    (**(code **)(*plVar10 + 0xa0))(0x3f0ccccd,plVar10);
    (**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar10);
    if (!param_4) {
      uVar14 = FMODAudioEngine::sharedEngine((FMODAudioEngine *)0x0);
      FUN_00e153b8(&local_10,"gold02.ogg",auStack_30);
                    
      FMODAudioEngine::playEffect(uVar14,&local_10);
      lVar16 = CONCAT44(local_10.y,
                        CONCAT13(local_10.x._3_1_,
                                 CONCAT12(local_10.x._2_1_,
                                          CONCAT11(local_10.x._1_1_,local_10.x._0_1_))));
      puVar15 = (undefined8 *)(lVar16 + -0x18);
      if (puVar15 != &DAT_0134b6b0) {
        piVar22 = (int *)(lVar16 + -8);
        do {
          iVar5 = *piVar22;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar22,0x10);
          if (bVar3) {
            *piVar22 = iVar5 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (iVar5 < 1) {
          operator.delete(puVar15);
        }
      }
    }
    if (param_2 < 1) {
      pfVar12 = (float *)(**(code **)(*plVar7 + 0x138))(plVar7);
      fVar28 = *pfVar12;
      fVar24 = (float)(**(code **)(*plVar7 + 0xa8))(plVar7);
      pfVar12 = (float *)(**(code **)(*plVar10 + 0x138))(plVar10);
      fVar29 = *pfVar12;
      fVar25 = (float)(**(code **)(*plVar10 + 0xa8))(plVar10);
      pfVar12 = (float *)(**(code **)(*plVar7 + 0x138))(plVar7);
      fVar31 = *pfVar12;
      fVar26 = (float)(**(code **)(*plVar7 + 0xa8))(plVar7);
      fVar24 = -((fVar24 * fVar28 + 1.0 + fVar25 * fVar29) * 0.5 - fVar31 * fVar26 * 0.5);
    }
    else {
      fVar24 = 40.0;
    }
    pcVar23 = *(code **)(*plVar7 + 0xb8);
    cocos2d::CCPoint::CCPoint(&local_10,fVar24 + fVar27,-62.0);
    (*pcVar23)(plVar7,&local_10);
    pcVar23 = *(code **)(*plVar10 + 0xb8);
    pCVar11 = (CCPoint *)(**(code **)(*plVar7 + 0xc0))(plVar7);
    pfVar12 = (float *)(**(code **)(*plVar7 + 0x138))(plVar7);
    fVar24 = *pfVar12;
    fVar25 = (float)(**(code **)(*plVar7 + 0xa8))(plVar7);
    cocos2d::CCPoint::CCPoint(&local_18,fVar25 * fVar24 * 0.5 + 1.0,-1.0);
    cocos2d::CCPoint::operator+(pCVar11,(CCPoint *)&local_18);
    (*pcVar23)(plVar10,&local_10);
    if (0 < param_2) goto LAB_006cae24;
LAB_006cb310:
    if (bVar1) goto LAB_006cb068;
  }
  else {
    if (!bVar1) {
      fVar27 = -20.0;
      goto LAB_006cacb8;
    }
LAB_006cb308:
    fVar27 = -5.0;
    if (param_2 < 1) goto LAB_006cb310;
LAB_006cae24:
    pCVar8 = (CCString *)cocos2d::CCString::createWithFormat("+%i",(ulong)(uint)param_2);
    pcVar9 = (char *)cocos2d::CCString::getCString(pCVar8);
    plVar7 = (long *)cocos2d::CCLabelBMFont::create(pcVar9,"bigFont.fnt");
    (**(code **)(*plVar7 + 0xa0))(0x3f19999a);
    (**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar7);
    plVar10 = (long *)cocos2d::CCSprite::createWithSpriteFrameName("currencyOrbIcon_001.png");
    pcVar23 = *(code **)(*plVar10 + 0x118);
    cocos2d::CCPoint::CCPoint(&local_10,0.0,0.5);
    (*pcVar23)(plVar10,&local_10);
    pFVar13 = (FMODAudioEngine *)(**(code **)(pCVar6->CCCopying + 0x1b8))(pCVar6,plVar10);
    uVar14 = FMODAudioEngine::sharedEngine(pFVar13);
    FUN_00e153b8(&local_10,"magicExplosion.ogg",auStack_30);
                    
    FMODAudioEngine::playEffect(uVar14,&local_10);
    lVar16 = CONCAT44(local_10.y,
                      CONCAT13(local_10.x._3_1_,
                               CONCAT12(local_10.x._2_1_,CONCAT11(local_10.x._1_1_,local_10.x._0_1_)
                                       )));
    puVar15 = (undefined8 *)(lVar16 + -0x18);
    if (puVar15 != &DAT_0134b6b0) {
      piVar22 = (int *)(lVar16 + -8);
      do {
        iVar5 = *piVar22;
        cVar2 = '\x01';
        bVar1 = (bool)ExclusiveMonitorPass(piVar22,0x10);
        if (bVar1) {
          *piVar22 = iVar5 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (iVar5 < 1) {
        operator.delete(puVar15);
      }
    }
    if (param_3 < 1) {
      pfVar12 = (float *)(**(code **)(*plVar7 + 0x138))(plVar7);
      fVar28 = *pfVar12;
      fVar24 = (float)(**(code **)(*plVar7 + 0xa8))(plVar7);
      pfVar12 = (float *)(**(code **)(*plVar10 + 0x138))(plVar10);
      fVar29 = *pfVar12;
      fVar25 = (float)(**(code **)(*plVar10 + 0xa8))(plVar10);
      pfVar12 = (float *)(**(code **)(*plVar7 + 0x138))(plVar7);
      fVar31 = *pfVar12;
      fVar26 = (float)(**(code **)(*plVar7 + 0xa8))(plVar7);
      fVar24 = -((fVar24 * fVar28 + 5.0 + fVar25 * fVar29) * 0.5 - fVar31 * fVar26 * 0.5);
    }
    else {
      fVar24 = -40.0;
    }
    pcVar23 = *(code **)(*plVar7 + 0xb8);
    cocos2d::CCPoint::CCPoint(&local_10,fVar24 + fVar27,-62.0);
    (*pcVar23)(plVar7,&local_10);
    pcVar23 = *(code **)(*plVar10 + 0xb8);
    pCVar11 = (CCPoint *)(**(code **)(*plVar7 + 0xc0))(plVar7);
    pfVar12 = (float *)(**(code **)(*plVar7 + 0x138))(plVar7);
    fVar27 = *pfVar12;
    fVar24 = (float)(**(code **)(*plVar7 + 0xa8))(plVar7);
    cocos2d::CCPoint::CCPoint(&local_18,fVar24 * fVar27 * 0.5 + 5.0,-0.5);
    cocos2d::CCPoint::operator+(pCVar11,(CCPoint *)&local_18);
    (*pcVar23)(plVar10,&local_10);
  }
  cocos2d::CCNode::convertToWorldSpace((CCPoint *)(this->GJBaseGameLayer_data).m_unkdd0);
  if (param_4) {
    cocos2d::CCPoint::CCPoint(&local_10,(CCPoint *)&local_18);
    lVar16 = CurrencyRewardLayer::create
                       ((CurrencyRewardLayer *)0x0,0x3f666666,param_2,0,0,param_3,9,1,0,0,&local_10,
                        0);
    pFVar13 = (FMODAudioEngine *)(**(code **)(this->CCCopying + 0x1c0))(this,lVar16,0x65);
    uVar14 = FMODAudioEngine::sharedEngine(pFVar13);
    FUN_00e153b8(&local_10,"secretKey.ogg",auStack_38);
                    
    FMODAudioEngine::playEffect(uVar14,&local_10);
    lVar4 = CONCAT44(local_10.y,
                     CONCAT13(local_10.x._3_1_,
                              CONCAT12(local_10.x._2_1_,CONCAT11(local_10.x._1_1_,local_10.x._0_1_))
                             ));
    puVar15 = (undefined8 *)(lVar4 + -0x18);
    if (puVar15 != &DAT_0134b6b0) {
      piVar22 = (int *)(lVar4 + -8);
      do {
        iVar5 = *piVar22;
        cVar2 = '\x01';
        bVar1 = (bool)ExclusiveMonitorPass(piVar22,0x10);
        if (bVar1) {
          *piVar22 = iVar5 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (iVar5 < 1) {
        operator.delete(puVar15);
      }
    }
  }
  else {
    cocos2d::CCPoint::CCPoint(&local_10,(CCPoint *)&local_18);
    lVar16 = CurrencyRewardLayer::create
                       ((CurrencyRewardLayer *)0x0,0x3f666666,param_2,0,0,param_3,0,0,0,0,&local_10,
                        0);
    (**(code **)(this->CCCopying + 0x1c0))(this,lVar16,0x65);
  }
  if (!param_5) {
    *(undefined1 **)(lVar16 + 0x198) = &(this->PlayLayer_data).field_0xc0;
  }
LAB_006cb068:
  pCVar17 = (CCScaleTo *)(**(code **)(pCVar6->CCCopying + 0xa0))(0x3c23d70a,pCVar6);
  this_00 = (CCEaseElasticOut *)cocos2d::CCScaleTo::create(pCVar17,0.4,1.0);
  pCVar18 = (CCDelayTime *)cocos2d::CCEaseElasticOut::create(this_00,0.6);
  pCVar17 = (CCScaleTo *)cocos2d::CCDelayTime::create(pCVar18,fVar30);
  this_01 = (CCEaseIn *)cocos2d::CCScaleTo::create(pCVar17,0.2,0.01,0.01);
  this_02 = (CCHide *)cocos2d::CCEaseIn::create(this_01,2.0);
  uVar14 = cocos2d::CCHide::create(this_02);
  uVar19 = cocos2d::CCCallFunc::create((CCCallFunc *)pCVar6,(CCObject *)0x208,(_func_void *)0x1);
  pCVar20 = (CCAction *)
            cocos2d::CCSequence::create
                      ((CCFiniteTimeAction *)pCVar18,pCVar17,this_02,uVar14,uVar19,0);
  cocos2d::CCNode::runAction(pCVar6,pCVar20);
  if (0 < param_2 + param_3) {
    local_10.x._0_1_ = 0;
    local_10.x._1_1_ = 0;
    local_10.x._2_1_ = 0;
    local_10.x._3_1_ = 0;
    pCVar6 = (CCNode *)cocos2d::CCLayerColor::create((_ccColor4B *)&local_10);
    (**(code **)(this->CCCopying + 0x1c0))(this,pCVar6,99);
    pCVar18 = (CCDelayTime *)cocos2d::CCFadeTo::create((CCFadeTo *)0x64,0.3,extraout_w1);
    uVar14 = cocos2d::CCDelayTime::create(pCVar18,fVar30 + 0.3);
    uVar19 = cocos2d::CCFadeTo::create((CCFadeTo *)0x0,0.4,extraout_w1_00);
    uVar21 = cocos2d::CCCallFunc::create((CCCallFunc *)pCVar6,(CCObject *)0x208,(_func_void *)0x1);
    pCVar20 = (CCAction *)
              cocos2d::CCSequence::create((CCFiniteTimeAction *)pCVar18,uVar14,uVar19,uVar21,0);
    cocos2d::CCNode::runAction(pCVar6,pCVar20);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::showRetryLayer(PlayLayer *this)

{
  long *plVar1;
  
  PlatformToolbox::showCursor();
  PlayerObject::releaseAllButtons((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0);
  UILayer::resetAllButtons
            ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last);
  UILayer::toggleMenuVisibility
            ((UILayer *)(this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last,false);
  *(undefined1 *)&(this->PlayLayer_data).m_keyPulses.m_bits.last = 1;
  plVar1 = (long *)RetryLevelLayer::create
                             ((RetryLevelLayer *)
                              ((this->GJBaseGameLayer_data).m_varianceValues + 0x7c5));
  (**(code **)(this->CCCopying + 0x1c0))(this,plVar1,100);
  (**(code **)(*plVar1 + 0x520))(plVar1,0);
  return;
}





void PlayLayer::showTwoPlayerGuide(PlayLayer *this)

{
  char cVar1;
  CCNode *this_00;
  CCNode *this_01;
  GameManager *pGVar2;
  CCNode *this_02;
  CCDelayTime *pCVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  CCAction *pCVar7;
  CCPoint *pCVar8;
  uchar extraout_w1;
  uchar extraout_w1_00;
  uchar uVar9;
  uchar extraout_w1_01;
  uchar extraout_w1_02;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  int iVar10;
  code *pcVar11;
  int iVar12;
  float local_18;
  float local_14;
  CCPoint CStack_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  this_00 = (CCNode *)cocos2d::CCLabelBMFont::create("Player 1","bigFont.fnt");
  (**(code **)(this_00->CCCopying + 0xa0))(0x3f4ccccd);
  (**(code **)(this->CCCopying + 0x1c0))(this,this_00,3);
  pcVar11 = *(code **)(this_00->CCCopying + 0xb8);
  cocos2d::CCPoint::CCPoint(&CStack_10,local_18 * 0.5 - local_18 * 0.25,local_14 * 0.5);
  (*pcVar11)(this_00,&CStack_10);
  this_01 = (CCNode *)cocos2d::CCLabelBMFont::create("Player 2","bigFont.fnt");
  (**(code **)(this_01->CCCopying + 0xa0))(0x3f4ccccd);
  (**(code **)(this->CCCopying + 0x1c0))(this,this_01,3);
  pcVar11 = *(code **)(this_01->CCCopying + 0xb8);
  cocos2d::CCPoint::CCPoint(&CStack_10,local_18 * 0.25 + local_18 * 0.5,local_14 * 0.5);
  pGVar2 = (GameManager *)(*pcVar11)(this_01,&CStack_10);
  pGVar2 = (GameManager *)GameManager::sharedState(pGVar2);
  cVar1 = GameManager::getGameVariable(pGVar2,"0010");
  if (cVar1 != '\0') {
    pCVar8 = (CCPoint *)(**(code **)(this_00->CCCopying + 0xc0))(this_00);
    cocos2d::CCPoint::CCPoint(&CStack_10,pCVar8);
    pcVar11 = *(code **)(this_00->CCCopying + 0xb8);
    uVar4 = (**(code **)(this_01->CCCopying + 0xc0))(this_01);
    (*pcVar11)(this_00,uVar4);
    (**(code **)(this_01->CCCopying + 0xb8))(this_01,&CStack_10);
  }
  iVar10 = 0;
  iVar12 = 1;
  this_02 = (CCNode *)cocos2d::CCSprite::createWithSpriteFrameName("floorLine_001.png");
  (**(code **)(this_02->CCCopying + 0xa0))
            ((local_14 * 1.2) / this_02[1].CCNode_data.m_obContentSize.height);
  (**(code **)(this_02->CCCopying + 0x158))(0x42b40000,this_02);
  (**(code **)(this->CCCopying + 0x1c0))(this,this_02,3);
  pcVar11 = *(code **)(this_02->CCCopying + 0xb8);
  cocos2d::CCPoint::CCPoint(&CStack_10,local_18 * 0.5,local_14 * 0.5);
  (*pcVar11)(this_02,&CStack_10);
  (**(code **)(this_02->CCCopying + 0x428))(this_02,0x100000302);
  (**(code **)(this_00->CCCopying + 0x3f0))(this_00,0);
  (**(code **)(this_01->CCCopying + 0x3f0))(this_01,0);
  (**(code **)(this_02->CCCopying + 0x380))(this_02,0);
  uVar9 = extraout_w1;
  do {
    pCVar3 = (CCDelayTime *)cocos2d::CCFadeTo::create((CCFadeTo *)0xffffffff,0.2,uVar9);
    uVar4 = cocos2d::CCDelayTime::create(pCVar3,0.8);
    uVar5 = cocos2d::CCFadeTo::create((CCFadeTo *)0x0,0.2,extraout_w1_01);
    uVar6 = cocos2d::CCCallFunc::create((CCCallFunc *)this_00,(CCObject *)0x208,(_func_void *)0x1);
    pCVar7 = (CCAction *)
             cocos2d::CCSequence::create((CCFiniteTimeAction *)pCVar3,uVar4,uVar5,uVar6,0);
    cocos2d::CCNode::runAction(this_00,pCVar7);
    uVar4 = extraout_x1_00;
    while( true ) {
      uVar9 = (uchar)uVar4;
      iVar10 = iVar10 + 1;
      iVar12 = iVar12 + 1;
      if (iVar10 == 0) break;
      if (iVar10 == 1) {
        pCVar3 = (CCDelayTime *)cocos2d::CCFadeTo::create((CCFadeTo *)0xffffffff,0.2,uVar9);
        uVar4 = cocos2d::CCDelayTime::create(pCVar3,0.8);
        uVar5 = cocos2d::CCFadeTo::create((CCFadeTo *)0x0,0.2,extraout_w1_02);
        uVar6 = cocos2d::CCCallFunc::create
                          ((CCCallFunc *)this_01,(CCObject *)0x208,(_func_void *)0x1);
        pCVar7 = (CCAction *)
                 cocos2d::CCSequence::create((CCFiniteTimeAction *)pCVar3,uVar4,uVar5,uVar6,0);
        cocos2d::CCNode::runAction(this_01,pCVar7);
        uVar4 = extraout_x1_01;
      }
      else {
        pCVar3 = (CCDelayTime *)cocos2d::CCFadeTo::create((CCFadeTo *)0xffffffff,0.2,uVar9);
        uVar4 = cocos2d::CCDelayTime::create(pCVar3,0.8);
        uVar5 = cocos2d::CCFadeTo::create((CCFadeTo *)0x0,0.2,extraout_w1_00);
        uVar6 = cocos2d::CCCallFunc::create
                          ((CCCallFunc *)this_02,(CCObject *)0x208,(_func_void *)0x1);
        pCVar7 = (CCAction *)
                 cocos2d::CCSequence::create((CCFiniteTimeAction *)pCVar3,uVar4,uVar5,uVar6,0);
        cocos2d::CCNode::runAction(this_02,pCVar7);
        uVar4 = extraout_x1;
        if (iVar12 == 3) {
          if (local_8 != ___stack_chk_guard) {
                    
            __stack_chk_fail();
          }
          return;
        }
      }
    }
  } while( true );
}





void PlayLayer::spawnCircle(PlayLayer *this)

{
  undefined1 uVar1;
  undefined1 uVar2;
  long lVar3;
  CCDirector *this_00;
  long *plVar4;
  CCNode *pCVar5;
  GJMGLayer *pGVar6;
  code *pcVar7;
  float fVar8;
  undefined1 auStack_10 [8];
  long local_8;
  
  local_8 = ___stack_chk_guard;
  this_00 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
  fVar8 = (float)cocos2d::CCDirector::getScreenRight(this_00);
  plVar4 = (long *)CCCircleWave::create(10.0,fVar8,0.5,true);
  pCVar5 = (this->GJBaseGameLayer_data).m_unkdd0;
  *(undefined4 *)((long)plVar4 + 0x164) = 4;
  uVar1 = *(undefined1 *)((long)&pCVar5[8].CCNode_data.m_fSkewY + 2);
  uVar2 = *(undefined1 *)((long)&pCVar5[8].CCNode_data.m_fSkewY + 3);
  *(undefined1 *)((long)plVar4 + 0x156) =
       *(undefined1 *)&pCVar5[8].CCNode_data.m_obAnchorPointInPoints.x;
  *(undefined1 *)((long)plVar4 + 0x154) = uVar1;
  *(undefined1 *)((long)plVar4 + 0x155) = uVar2;
  pcVar7 = *(code **)(*plVar4 + 0xb8);
  getEndPosition();
  (*pcVar7)(plVar4,auStack_10);
  pGVar6 = (this->GJBaseGameLayer_data).m_middleground;
  (**(code **)(pGVar6->CCCopying + 0x1c0))(pGVar6,plVar4,0);
  lVar3 = ___stack_chk_guard;
  *(undefined4 *)(plVar4 + 0x2c) = 1;
  if (local_8 == lVar3) {
    return;
  }
                    
  __stack_chk_fail();
}





void PlayLayer::spawnFirework(PlayLayer *this)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  GameManager *pGVar6;
  long lVar7;
  long *plVar8;
  CCNode *pCVar9;
  float local_28;
  float local_24;
  CCPoint CStack_20;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  GameManager *local_8;
  
  local_8 = ___stack_chk_guard;
  pGVar6 = (GameManager *)GameManager::sharedState(___stack_chk_guard);
  lVar7 = GameManager::sharedState(pGVar6);
  iVar4 = GameManager::colorForIdx(pGVar6,*(int *)(lVar7 + 0x2d0) - *(int *)(lVar7 + 0x2d4));
  pGVar6 = (GameManager *)GameManager::sharedState((GameManager *)(long)iVar4);
  lVar7 = GameManager::sharedState(pGVar6);
  GameManager::colorForIdx(pGVar6,*(int *)(lVar7 + 0x2c4) - *(int *)(lVar7 + 0x2c8));
  pCVar9 = (this->GJBaseGameLayer_data).m_unkdd0;
  uVar1 = *(undefined1 *)((long)&pCVar9[8].CCNode_data.m_obAnchorPointInPoints.x + 1);
  uVar2 = *(undefined1 *)((long)&pCVar9[8].CCNode_data.m_obAnchorPointInPoints.x + 2);
  local_14 = (float)*(byte *)((long)&pCVar9[8].CCNode_data.m_fSkewY + 3) / 255.0;
  uVar3 = *(undefined1 *)((long)&pCVar9[8].CCNode_data.m_obAnchorPointInPoints.x + 3);
  local_c = 0x3f800000;
  local_10 = (float)*(byte *)&pCVar9[8].CCNode_data.m_obAnchorPointInPoints.x / 255.0;
  local_18 = (float)*(byte *)((long)&pCVar9[8].CCNode_data.m_fSkewY + 2) / 255.0;
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  iVar4 = rand();
  iVar5 = rand();
  cocos2d::CCPoint::CCPoint
            (&CStack_20,(float)iVar4 * 4.656613e-10 * (local_28 - 50.0) + 50.0,
             (float)iVar5 * 4.656613e-10 * (local_24 - 50.0) + 50.0);
  iVar4 = rand();
  plVar8 = (long *)CCCircleWave::create(10.0,(float)iVar4 * 4.656613e-10 * 15.0 + 35.0,0.5,true);
  *(undefined1 *)((long)plVar8 + 0x154) = uVar1;
  *(undefined1 *)((long)plVar8 + 0x155) = uVar2;
  *(undefined1 *)((long)plVar8 + 0x156) = uVar3;
  *(undefined4 *)((long)plVar8 + 0x164) = 4;
  (**(code **)(*plVar8 + 0xb8))(plVar8,&CStack_20);
  (**(code **)(this->CCCopying + 0x1c0))(this,plVar8,10);
  plVar8 = (long *)cocos2d::CCParticleSystemQuad::create("firework.plist",false);
  (**(code **)(*plVar8 + 0x620))(plVar8,1);
  (**(code **)(this->CCCopying + 0x1c0))(this,plVar8,0xd);
  (**(code **)(*plVar8 + 0xb8))(plVar8,&CStack_20);
  (**(code **)(*plVar8 + 0x540))(plVar8,&local_18);
  (**(code **)(*plVar8 + 0x560))(plVar8,&local_18);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::startGame(PlayLayer *this)

{
  long lVar1;
  CCNode *pCVar2;
  GameObject **ppGVar3;
  
  lVar1 = cocos2d::CCDirector::sharedDirector();
  *(undefined1 *)(lVar1 + 0xaa) = 1;
  pCVar2 = (this->GJBaseGameLayer_data).m_unkdd0;
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity = 1;
  (**(code **)(pCVar2->CCCopying + 0x148))(pCVar2,1);
  ppGVar3 = (this->GJBaseGameLayer_data).m_unkdd8.start;
  (**(code **)&(*ppGVar3)->CCNodeRGBA_data)(ppGVar3,1);
  startMusic(this);
  return;
}




void PlayLayer::startGameDelayed(PlayLayer *this)

{
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity = 1;
  startMusic(this);
  return;
}




void PlayLayer::startMusic(PlayLayer *this)

{
  byte bVar1;
  int iVar2;
  FMODAudioEngine *this_00;
  CCObject *this_01;
  
  if (((*(char *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.start + 2) == '\0') &&
      (*(char *)&(this->GJBaseGameLayer_data).m_activeObjects.capacity != '\0')) &&
     (*(long *)((long)&(this->PlayLayer_data).m_blendingColors.factor + 3) == 0)) {
    this_00 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)this);
    FMODAudioEngine::getBackgroundMusicVolume(this_00);
    if (*(char *)&this[1].CCNode_data.m_sInverse.ty == '\0') {
      prepareMusic(this,false);
    }
    GJBaseGameLayer::processQueuedAudioTriggers((GJBaseGameLayer *)this);
    GJBaseGameLayer::updateProximityVolumeEffects((GJBaseGameLayer *)this);
    if (((this->GJBaseGameLayer_data).m_gameState.m_levelTime <= 0.0) &&
       (bVar1 = *(byte *)((long)(this->GJBaseGameLayer_data).m_unkdd8.last + 0x15c), bVar1 != 0)) {
      iVar2 = FMODAudioEngine::sharedEngine((FMODAudioEngine *)(ulong)bVar1);
      FMODAudioEngine::fadeInMusic(2.0,iVar2);
    }
    if ((this->GJBaseGameLayer_data).m_hazardCollisionObjects.start != (GameObject **)0x0) {
      GJBaseGameLayer::pauseAudio();
      GJBaseGameLayer::processActivatedAudioTriggers
                ((GJBaseGameLayer *)this,(float)(this->GJBaseGameLayer_data).m_gameState.m_levelTime
                );
      if (*(long *)((long)&(this->PlayLayer_data).m_blendingColors.factor + 3) == 0) {
        this_01 = (CCObject *)createCheckpoint(this);
        *(CCObject **)((long)&(this->PlayLayer_data).m_blendingColors.factor + 3) = this_01;
        cocos2d::CCObject::retain(this_01);
      }
    }
    *(undefined1 *)&this[1].CCNode_data.m_sInverse.ty = 0;
    *(undefined1 *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.start + 1) = 1;
  }
  return;
}




void PlayLayer::startRecording(PlayLayer *this)

{
  (this->PlayLayer_data).m_tryPlaceCheckpoint = false;
  return;
}




void PlayLayer::startRecordingDelayed(PlayLayer *this)

{
  CCDelayTime *this_00;
  CCFiniteTimeAction *pCVar1;
  undefined8 uVar2;
  CCAction *pCVar3;
  
  this_00 = (CCDelayTime *)cocos2d::CCNode::stopActionByTag((CCNode *)this,0x1f);
  pCVar1 = (CCFiniteTimeAction *)cocos2d::CCDelayTime::create(this_00,2.0);
  uVar2 = cocos2d::CCCallFunc::create
                    ((CCCallFunc *)this,(CCObject *)startRecording,(_func_void *)0x0);
  pCVar3 = (CCAction *)cocos2d::CCSequence::create(pCVar1,uVar2,0);
  (**(code **)(*(long *)pCVar3 + 0x48))(pCVar3,0x1f);
  cocos2d::CCNode::runAction((CCNode *)this,pCVar3);
  return;
}




void PlayLayer::stopRecording(PlayLayer *this)

{
  cocos2d::CCNode::stopActionByTag((CCNode *)this,0x1f);
  return;
}




void PlayLayer::storeCheckpoint(PlayLayer *this,CheckpointObject *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  cocos2d::CCArray::addObject
            (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3),
             (CCObject *)param_1);
  uVar2 = CheckpointObject::getObject((CheckpointObject *)param_1);
  (**(code **)(this->CCCopying + 0x510))(this,uVar2);
  uVar1 = cocos2d::CCArray::count
                    (*(CCArray **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3));
  if (uVar1 < 0x33) {
    return;
  }
  removeCheckpoint(this,true);
  return;
}




void PlayLayer::takeStateSnapshot(void)

{
  return;
}




void PlayLayer::testTime(void)

{
  return;
}





void PlayLayer::timeForPos
               (long param_1,CCPoint *param_2,undefined4 param_3,undefined4 param_4,
               undefined1 param_5)

{
  CCPoint CStack_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  cocos2d::CCPoint::CCPoint(&CStack_10,param_2);
  LevelTools::timeForPos
            (&CStack_10,*(undefined8 *)(param_1 + 0x3870),
             *(undefined4 *)(*(long *)(param_1 + 0xe08) + 0x14c),param_3,param_4,param_5,
             *(undefined1 *)(*(long *)(param_1 + 0xdf8) + 0xb40),0,0,0);
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::toggleBGEffectVisibility(PlayLayer *this,bool param_1)

{
  *(bool *)((long)&this[1].CCObject_data.m_unknown5 + 1) = !param_1;
  if (!param_1) {
    cocos2d::CCParticleSystem::stopSystem
              ((CCParticleSystem *)(this->GJBaseGameLayer_data).m_cameraObb2);
    return;
  }
  if ((char)this[1].CCObject_data.m_unknown5 == '\0') {
    return;
  }
  cocos2d::CCParticleSystem::resumeSystem
            ((CCParticleSystem *)(this->GJBaseGameLayer_data).m_cameraObb2);
  return;
}




void PlayLayer::toggleDebugDraw(PlayLayer *this)

{
  char cVar1;
  char cVar2;
  long *plVar3;
  
  cVar1 = shouldDebugDraw(this);
  plVar3 = *(long **)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.last + 3);
  cVar2 = (**(code **)(*plVar3 + 0x150))(plVar3);
  if (cVar1 != cVar2) {
    cocos2d::CCDrawNode::clear
              (*(CCDrawNode **)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.last + 3));
    plVar3 = *(long **)((long)&(this->PlayLayer_data).m_dynamicSaveObjects2.last + 3);
    (**(code **)(*plVar3 + 0x148))(plVar3,cVar1);
    if (cVar1 != '\0') {
      (**(code **)(this->CCCopying + 0x508))(this);
      return;
    }
  }
  return;
}




void PlayLayer::toggleGhostEffect(PlayLayer *this,int param_1)

{
  PlayerObject::toggleGhostEffect((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd0,param_1);
  if ((this->GJBaseGameLayer_data).m_gameState.m_isDualMode == false) {
    return;
  }
  PlayerObject::toggleGhostEffect
            ((PlayerObject *)(this->GJBaseGameLayer_data).m_unkdd8.start,param_1);
  return;
}




void PlayLayer::toggleGlitter(PlayLayer *this,bool param_1)

{
  byte bVar1;
  long lVar2;
  OBB2D *this_00;
  
  lVar2 = GameManager::sharedState((GameManager *)this);
  if (*(char *)(lVar2 + 0x335) != '\0') {
    return;
  }
  bVar1 = *(byte *)((long)&this[1].CCObject_data.m_unknown5 + 1);
  *(bool *)&this[1].CCObject_data.m_unknown5 = param_1;
  this_00 = (this->GJBaseGameLayer_data).m_cameraObb2;
  if (bVar1 < param_1) {
    cocos2d::CCParticleSystem::resumeSystem((CCParticleSystem *)this_00);
    return;
  }
  cocos2d::CCParticleSystem::stopSystem((CCParticleSystem *)this_00);
  return;
}




void PlayLayer::toggleGroundVisibility(PlayLayer *this,bool param_1)

{
  GJGroundLayer::toggleVisible02
            ((GJGroundLayer *)(this->GJBaseGameLayer_data).m_labelObjects.start,param_1);
  GJGroundLayer::toggleVisible02
            ((GJGroundLayer *)(this->GJBaseGameLayer_data).m_labelObjects.size,param_1);
  return;
}




void PlayLayer::toggleHideAttempts(PlayLayer *this,bool param_1)

{
  byte bVar1;
  char cVar2;
  GameManager *pGVar3;
  long *plVar4;
  
  if ((bool)*(char *)((long)&(this->PlayLayer_data).m_speedObjects + 2) == param_1) {
    return;
  }
  *(bool *)((long)&(this->PlayLayer_data).m_speedObjects + 2) = param_1;
  if (!param_1) {
    bVar1 = *(byte *)&(this->GJBaseGameLayer_data).m_endPortal;
    pGVar3 = (GameManager *)(ulong)bVar1;
    if (bVar1 != 0) {
      pGVar3 = (GameManager *)GameManager::sharedState(pGVar3);
      bVar1 = GameManager::getGameVariable(pGVar3,"0134");
      pGVar3 = (GameManager *)(ulong)bVar1;
      if (bVar1 != 0) goto LAB_006c9428;
    }
    pGVar3 = (GameManager *)GameManager::sharedState(pGVar3);
    cVar2 = GameManager::getGameVariable(pGVar3,"0135");
    if (cVar2 == '\0') {
      if (*(int *)&(this->GJBaseGameLayer_data).field_0x2f54 < 1) {
        return;
      }
      plVar4 = *(long **)&(this->PlayLayer_data).field_0x1f0;
      (**(code **)(*plVar4 + 0x148))(plVar4,1);
      return;
    }
  }
LAB_006c9428:
  plVar4 = *(long **)&(this->PlayLayer_data).field_0x1f0;
  (**(code **)(*plVar4 + 0x148))(plVar4,0);
  return;
}




void PlayLayer::toggleIgnoreDamage(PlayLayer *this,bool param_1)

{
  GameObject **ppGVar1;
  
  (this->GJBaseGameLayer_data).m_ignoreDamage = param_1;
  if (param_1) {
    (this->PlayLayer_data).field_0x16e = 1;
  }
  ppGVar1 = (this->GJBaseGameLayer_data).m_unkdd8.start;
  *(bool *)((long)&(this->GJBaseGameLayer_data).m_unkdd0[6].CCNode_data.m_fScaleY + 1) = param_1;
  *(bool *)((long)ppGVar1 + 0x7c5) = param_1;
  updateTestModeLabel(this);
  return;
}




void PlayLayer::toggleInfoLabel(PlayLayer *this)

{
  undefined4 uVar1;
  GameManager *this_00;
  long *plVar2;
  
  this_00 = (GameManager *)GameManager::sharedState((GameManager *)this);
  uVar1 = GameManager::getGameVariable(this_00,"0109");
  plVar2 = *(long **)&this[1].CCNode_data.m_fScaleX;
  (**(code **)(*plVar2 + 0x148))(plVar2,uVar1);
  updateInfoLabel(this);
  return;
}




void PlayLayer::toggleMGVisibility(PlayLayer *this,bool param_1)

{
  GJMGLayer *this_00;
  
  this_00 = *(GJMGLayer **)&(this->GJBaseGameLayer_data).m_labelObjects.factor;
  if (this_00 != (GJMGLayer *)0x0) {
    GJMGLayer::toggleVisible02(this_00,param_1);
    return;
  }
  return;
}




void PlayLayer::toggleMusicInPractice(PlayLayer *this)

{
  char cVar1;
  char cVar2;
  GameStatsManager *pGVar3;
  GameManager *this_00;
  
  pGVar3 = (GameStatsManager *)GameStatsManager::sharedState((GameStatsManager *)this);
  cVar1 = GameStatsManager::isItemEnabled(pGVar3,0xc,0x11);
  if (cVar1 == '\0') {
    this_00 = (GameManager *)GameManager::sharedState((GameManager *)0x0);
    cVar2 = GameManager::getGameVariable(this_00,"0125");
    cVar1 = '\0';
    if (cVar2 != '\0') {
      *(bool *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) =
           (((this->GJBaseGameLayer_data).m_level)->GJGameLevel_data).m_levelType == Editor;
      return;
    }
  }
  *(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) = cVar1;
  return;
}






void PlayLayer::togglePracticeMode(PlayLayer *this,bool param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  FMODAudioEngine *pFVar4;
  GameManager *this_00;
  int *piVar5;
  long local_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if ((bool)*(char *)&(this->GJBaseGameLayer_data).m_endPortal != param_1) {
    *(bool *)&(this->GJBaseGameLayer_data).m_endPortal = param_1;
    toggleDebugDraw(this);
    UILayer::toggleCheckpointsMenu
              (SUB81((this->GJBaseGameLayer_data).m_calcCollisionBlockObjects2.last,0));
    if (param_1) {
      if (*(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) == '\0') {
        pFVar4 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)0x0);
        pFVar4 = (FMODAudioEngine *)FMODAudioEngine::stopAllMusic(pFVar4,true);
        this_00 = (GameManager *)FMODAudioEngine::sharedEngine(pFVar4);
        GameManager::sharedState(this_00);
        GameManager::getPracticeMusicFile();
                    
        FMODAudioEngine::playMusic((FMODAudioEngine *)0x0,this_00,&local_10,1,0);
        if ((undefined8 *)(local_10 + -0x18) != &DAT_0134b6b0) {
          piVar5 = (int *)(local_10 + -8);
          do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5,0x10);
            if (bVar3) {
              *piVar5 = iVar1 + -1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (iVar1 < 1) {
            operator.delete((undefined8 *)(local_10 + -0x18));
          }
        }
      }
    }
    else {
      resetLevelFromStart(this);
    }
    if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal != '\0') {
      stopRecording(this);
    }
  }
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}





void PlayLayer::toggleProgressbar(PlayLayer *this)

{
  char cVar1;
  GameManager *pGVar2;
  long lVar3;
  long *plVar4;
  GameManager GVar5;
  code *pcVar6;
  float fVar7;
  float local_18;
  CCPoint CStack_10;
  GameManager *local_8;
  
  local_8 = ___stack_chk_guard;
  pGVar2 = (GameManager *)GameManager::sharedState(___stack_chk_guard);
  GVar5 = pGVar2[0x334];
  if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) == '\0') {
    pGVar2 = (GameManager *)GameManager::sharedState(pGVar2);
    fVar7 = 0.0;
    cVar1 = GameManager::getGameVariable(pGVar2,"0040");
    if (GVar5 != (GameManager)0x0) {
      fVar7 = 110.0;
    }
  }
  else {
    pGVar2 = (GameManager *)GameManager::sharedState(pGVar2);
    GVar5 = (GameManager)0x0;
    fVar7 = 0.0;
    cVar1 = GameManager::getGameVariable(pGVar2,"0145");
  }
  plVar4 = *(long **)((long)&(this->PlayLayer_data).m_bestAttemptTime + 3);
  (**(code **)(*plVar4 + 0x148))(plVar4,GVar5);
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  plVar4 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
  (**(code **)(*plVar4 + 0x148))(plVar4,cVar1);
  plVar4 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
  pcVar6 = *(code **)(*plVar4 + 0xb8);
  lVar3 = (**(code **)(*plVar4 + 0xc0))(plVar4);
  cocos2d::CCPoint::CCPoint(&CStack_10,fVar7 + local_18 * 0.5,*(float *)(lVar3 + 4));
  (*pcVar6)(plVar4,&CStack_10);
  plVar4 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
  pcVar6 = *(code **)(*plVar4 + 0x118);
  fVar7 = 0.0;
  if ((GVar5 == (GameManager)0x0) &&
     (fVar7 = 0.0, *(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) == '\0'))
  {
    fVar7 = 0.5;
  }
  cocos2d::CCPoint::CCPoint(&CStack_10,fVar7,0.5);
  (*pcVar6)(plVar4,&CStack_10);
  updateProgressbar(this);
  if ((cVar1 != '\0') &&
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0')) {
    GJBaseGameLayer::updatePlatformerTime((GJBaseGameLayer *)this);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::tryStartRecord(PlayLayer *this)

{
  cocos2d::CCNode::stopActionByTag((CCNode *)this,0x1f);
  startRecording(this);
  return;
}





void PlayLayer::updateAttempts(PlayLayer *this)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  GameManager *pGVar4;
  long lVar5;
  CCString *this_00;
  undefined8 uVar6;
  long *plVar7;
  code *pcVar8;
  float local_18;
  float local_14;
  CCPoint CStack_10;
  GameManager *local_8;
  
  *(int *)&(this->GJBaseGameLayer_data).field_0x2f54 =
       *(int *)&(this->GJBaseGameLayer_data).field_0x2f54 + 1;
  local_8 = ___stack_chk_guard;
  pGVar4 = (GameManager *)GameManager::sharedState(___stack_chk_guard);
  lVar5 = GameManager::sharedState(pGVar4);
  uVar1 = *(int *)(lVar5 + 0x37c) + 1;
  *(uint *)(pGVar4 + 0x37c) = uVar1;
  pGVar4 = (GameManager *)GameManager::sharedState((GameManager *)(ulong)uVar1);
  lVar5 = GameManager::sharedState(pGVar4);
  cVar3 = *(char *)&(this->GJBaseGameLayer_data).m_endPortal;
  uVar1 = *(int *)(lVar5 + 0x380) + 1;
  *(uint *)(pGVar4 + 0x380) = uVar1;
  if (cVar3 == '\0') {
    pGVar4 = (GameManager *)GameManager::sharedState((GameManager *)(ulong)uVar1);
    lVar5 = GameManager::sharedState(pGVar4);
    *(int *)(pGVar4 + 900) = *(int *)(lVar5 + 900) + 1;
  }
  this_00 = (CCString *)
            cocos2d::CCString::createWithFormat
                      ("Attempt %i",(ulong)*(uint *)&(this->GJBaseGameLayer_data).field_0x2f54);
  uVar6 = cocos2d::CCString::getCString(this_00);
  plVar7 = *(long **)&(this->PlayLayer_data).field_0x1f0;
  (**(code **)(*plVar7 + 0x390))(plVar7,uVar6);
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  if ((*(int *)&(this->GJBaseGameLayer_data).field_0x2f54 != 1) ||
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0')) {
    plVar7 = *(long **)&(this->PlayLayer_data).field_0x1f0;
    pcVar8 = *(code **)(*plVar7 + 0xb8);
    cocos2d::CCPoint::CCPoint
              (&CStack_10,
               (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.x + local_18 * 0.5 + 50.0,
               (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.y + local_14 * 0.5 + 85.0);
    (*pcVar8)(plVar7,&CStack_10);
  }
  if (*(char *)((long)&(this->PlayLayer_data).m_speedObjects + 2) == '\0') {
    bVar2 = *(byte *)&(this->GJBaseGameLayer_data).m_endPortal;
    pGVar4 = (GameManager *)(ulong)bVar2;
    if (bVar2 != 0) {
      pGVar4 = (GameManager *)GameManager::sharedState(pGVar4);
      bVar2 = GameManager::getGameVariable(pGVar4,"0134");
      pGVar4 = (GameManager *)(ulong)bVar2;
      if (bVar2 != 0) goto LAB_006d09f0;
    }
    pGVar4 = (GameManager *)GameManager::sharedState(pGVar4);
    cVar3 = GameManager::getGameVariable(pGVar4,"0135");
    if (cVar3 == '\0') {
      if (0 < *(int *)&(this->GJBaseGameLayer_data).field_0x2f54) {
        plVar7 = *(long **)&(this->PlayLayer_data).field_0x1f0;
        (**(code **)(*plVar7 + 0x148))(plVar7,1);
      }
      goto LAB_006d0a08;
    }
  }
LAB_006d09f0:
  plVar7 = *(long **)&(this->PlayLayer_data).field_0x1f0;
  (**(code **)(*plVar7 + 0x148))(plVar7,0);
LAB_006d0a08:
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}




void PlayLayer::updateAttemptTime(PlayLayer *this,float param_1)

{
  undefined8 uVar1;
  double dVar2;
  
  dVar2 = *(double *)&this[1].CCObject_data.m_uIndexInArray;
  *(double *)&this[1].CCObject_data = *(double *)&this[1].CCObject_data + (double)param_1;
  if (0.0 < dVar2) {
    return;
  }
  uVar1 = getTempMilliTime();
  this[1].CCObject_data.m_uIndexInArray = (int)uVar1;
  this[1].CCObject_data.m_nChildIndex = (int)((ulong)uVar1 >> 0x20);
  return;
}


/* PlayLayer::updateColor(cocos2d::_ccColor3B&, float, int, bool, float, cocos2d::_ccHSVValue&, int,
   bool, EffectGameObject*, int, int) */

undefined8
PlayLayer::updateColor
          (_ccColor3B *param_1,float param_2,int param_3,bool param_4,float param_5,
          _ccHSVValue *param_6,int param_7,bool param_8,EffectGameObject *param_9,int param_10,
          int param_11)

{
  undefined8 uVar1;
  long *plVar2;
  _Hash_node *p_Var3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  uint local_4;
  
  local_4 = (uint)param_4;
  uVar1 = GJBaseGameLayer::updateColor
                    (param_1,param_2,param_3,param_4,param_5,(_ccHSVValue *)((ulong)param_6 & 0xff),
                     param_7,param_8,param_9,param_10,param_11);
  if ((uint)(byte)param_1[0x310d] != ((uint)param_6 & 0xff)) {
    uVar4 = *(ulong *)(param_1 + 0x3918);
    uVar6 = (ulong)(int)local_4;
    uVar5 = 0;
    if (uVar4 != 0) {
      uVar5 = uVar6 / uVar4;
    }
    uVar5 = uVar6 - uVar5 * uVar4;
    plVar2 = (long *)FUN_006c95d0((_Hashtable<> *)(param_1 + 0x3910),uVar5,&local_4);
    if ((plVar2 == (long *)0x0) || (*plVar2 == 0)) {
      p_Var3 = (_Hash_node *)FUN_006c9758(&local_4);
      std::_Hashtable<>::_M_insert_unique_node
                ((_Hashtable<> *)(param_1 + 0x3910),uVar5,uVar6,p_Var3);
    }
  }
  return uVar1;
}




void PlayLayer::updateDebugDrawSettings(PlayLayer *this)

{
  bool bVar1;
  GameManager *pGVar2;
  
  pGVar2 = (GameManager *)GameManager::sharedState((GameManager *)this);
  pGVar2 = (GameManager *)GameManager::getGameVariable(pGVar2,"0166");
  *(char *)((long)&(this->PlayLayer_data).m_unk3768 + 3) = (char)pGVar2;
  pGVar2 = (GameManager *)GameManager::sharedState(pGVar2);
  pGVar2 = (GameManager *)GameManager::getGameVariable(pGVar2,"0171");
  (this->PlayLayer_data).m_platformerRestart = SUB81(pGVar2,0);
  pGVar2 = (GameManager *)GameManager::sharedState(pGVar2);
  bVar1 = (bool)GameManager::getGameVariable(pGVar2,"0179");
  (this->PlayLayer_data).m_unk376d = bVar1;
  toggleDebugDraw(this);
  return;
}





void PlayLayer::updateEffectPositions(PlayLayer *this)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  OBB2D *pOVar4;
  float fVar5;
  float local_18;
  float local_14;
  CCPoint CStack_10;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  pOVar4 = (this->GJBaseGameLayer_data).m_cameraObb2;
  fVar5 = (this->GJBaseGameLayer_data).m_gameState.m_cameraZoom;
  pcVar3 = *(code **)(pOVar4->CCCopying + 0xb8);
  cocos2d::CCPoint::CCPoint
            (&CStack_10,
             (local_18 * 0.5) / fVar5 + (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.x,
             (local_14 * 0.5) / fVar5 + (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.y)
  ;
  (*pcVar3)(pOVar4,&CStack_10);
  for (uVar2 = 0; uVar1 = cocos2d::CCArray::count(*(CCArray **)&(this->PlayLayer_data).field_0x1d0),
      uVar2 < uVar1; uVar2 = uVar2 + 1) {
    cocos2d::CCArray::objectAtIndex(*(CCArray **)&(this->PlayLayer_data).field_0x1d0,uVar2);
    CCCircleWave::updatePosition(0.0);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void PlayLayer::updateInfoLabel(PlayLayer *this)

{
  ulong uVar1;
  size_t sVar2;
  char cVar3;
  int iVar4;
  FMODAudioEngine *pFVar5;
  ulong uVar6;
  char *pcVar7;
  long *plVar8;
  GJGameLevel *pGVar9;
  code *pcVar10;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined1 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined1 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined1 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined1 local_21c;
  size_t local_218;
  ulong local_210;
  char *local_208;
  char local_200 [504];
  long local_8;
  
  plVar8 = *(long **)&this[1].CCNode_data.m_fScaleX;
  local_8 = ___stack_chk_guard;
  cVar3 = (**(code **)(*plVar8 + 0x150))(plVar8);
  if (cVar3 != '\0') {
    pGVar9 = (this->GJBaseGameLayer_data).m_level;
    local_208 = local_200;
    local_210 = 500;
    local_218 = 9;
    builtin_strncpy(local_200,"LevelID: ",9);
    iVar4 = (int)(BasicWriter<char> *)&local_218;
                    
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)(uint)((pGVar9->GJGameLevel_data).m_levelID.random -
                                  (pGVar9->GJGameLevel_data).m_levelID.seed));
    sVar2 = local_218;
    uVar6 = local_218 + 7;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nTime: ",7);
    local_274 = 0x20;
    local_278 = 0;
    local_270 = 0;
    local_26c = 0;
    local_268 = 0xffffffff;
    local_264 = 0;
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatDouble<double>
              ((BasicWriter<char> *)&local_218,
               (double)((float)(int)(*(double *)&this[1].CCObject_data * 100.0) / 100.0),
               (FormatSpec *)&local_278);
    sVar2 = local_218;
    uVar6 = local_218 + 10;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nAttempt: ",10);
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)(ulong)*(uint *)&(this->GJBaseGameLayer_data).field_0x2f54);
    sVar2 = local_218;
    uVar6 = local_218 + 7;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nTaps: ",7);
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)(uint)(this->GJBaseGameLayer_data).m_particleSystemLimit);
    sVar2 = local_218;
    uVar6 = local_218 + 0xb;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nTimeWarp: ",0xb);
    local_25c = 0x20;
    local_260 = 0;
    local_258 = 0;
    local_254 = 0;
    local_250 = 0xffffffff;
    local_24c = 0;
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatDouble<double>
              ((BasicWriter<char> *)&local_218,
               (double)(this->GJBaseGameLayer_data).m_gameState.m_timeWarp,(FormatSpec *)&local_260)
    ;
    sVar2 = local_218;
    uVar6 = local_218 + 10;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nGravity: ",10);
    local_248 = 0;
    local_244 = 0x20;
    local_240 = 0;
    local_23c = 0;
    local_238 = 0xffffffff;
    local_234 = 0;
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatDouble<double>
              ((BasicWriter<char> *)&local_218,
               (double)(float)(this->GJBaseGameLayer_data).m_unkdd0[9].CCObject_data.m_uReference,
               (FormatSpec *)&local_248);
    sVar2 = local_218;
    if (((this->GJBaseGameLayer_data).m_gameState.m_isDualMode != false) &&
       ((float)(this->GJBaseGameLayer_data).m_unkdd0[9].CCObject_data.m_uReference !=
        *(float *)((long)(this->GJBaseGameLayer_data).m_unkdd8.start + 0xb54))) {
      uVar6 = local_218 + 3;
      pcVar7 = local_208;
      if (local_210 < uVar6) {
        local_210 = local_210 + (local_210 >> 1);
        if (local_210 < uVar6) {
          local_210 = uVar6;
        }
        pcVar7 = operator.new[](local_210);
        if (local_218 != 0) {
          memmove(pcVar7,local_208,local_218);
        }
        if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
          operator.delete[](local_208);
        }
      }
      local_208 = pcVar7;
      (local_208 + sVar2)[0] = ' ';
      (local_208 + sVar2)[1] = '/';
      local_208[sVar2 + 2] = ' ';
      local_230 = 0;
      local_22c = 0x20;
      local_228 = 0;
      local_224 = 0;
      local_220 = 0xffffffff;
      local_21c = 0;
      local_218 = uVar6;
      fmt::BasicWriter<char>::FormatDouble<double>
                ((BasicWriter<char> *)&local_218,
                 (double)*(float *)((long)(this->GJBaseGameLayer_data).m_unkdd8.start + 0xb54),
                 (FormatSpec *)&local_230);
    }
    sVar2 = local_218;
    uVar6 = local_218 + 9;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nActive: ",9);
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)(ulong)(uint)(this->GJBaseGameLayer_data).m_coinsCollected);
    sVar2 = local_218;
    uVar6 = local_218 + 0xc;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nGradients: ",0xc);
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)&(this->GJBaseGameLayer_data).m_solidCollisionObjects.last);
    sVar2 = local_218;
    uVar6 = local_218 + 0xc;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2,"\nParticles: ",0xc);
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)&(this->GJBaseGameLayer_data).m_particleCountToParticleString.
                                      start);
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 0xd;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"-- Audio --\n",0xc);
    uVar6 = sVar2 + 0x14;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      local_218 = uVar1;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 0xd,"Songs: ",7);
    local_218 = uVar6;
    pFVar5 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)0x20);
    uVar6 = FMODAudioEngine::countActiveMusic(pFVar5);
    fmt::BasicWriter<char>::FormatInt<>(iVar4,(IntFormatSpec *)(uVar6 & 0xffffffff));
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 6;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"SFX: ",5);
    local_218 = uVar1;
    pFVar5 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)0x20);
    uVar6 = FMODAudioEngine::countActiveEffects(pFVar5);
    fmt::BasicWriter<char>::FormatInt<>(iVar4,(IntFormatSpec *)(uVar6 & 0xffffffff));
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 0xc;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"-- Perf --\n",0xb);
    uVar6 = sVar2 + 0x12;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      local_218 = uVar1;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 0xc,"Move: ",6);
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects2.start + 7))
    ;
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 9;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"Rotate: ",8);
    local_218 = uVar1;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects2.last + 7));
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 8;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"Scale: ",7);
    local_218 = uVar1;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects2.last + 3));
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 9;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"Follow: ",8);
    local_218 = uVar1;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects2.capacity +
                                     3));
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 0xc;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"-- Area --\n",0xb);
    uVar6 = sVar2 + 0x12;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      local_218 = uVar1;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 0xc,"Move: ",6);
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects1.last + 7));
    sVar2 = local_218;
    uVar6 = local_218 + 3;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    (local_208 + sVar2)[0] = ' ';
    (local_208 + sVar2)[1] = '/';
    local_208[sVar2 + 2] = ' ';
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_dynamicSaveObjects.capacity +
                                     7));
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 9;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"Rotate: ",8);
    local_218 = uVar1;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects1.capacity +
                                     7));
    sVar2 = local_218;
    uVar6 = local_218 + 3;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    (local_208 + sVar2)[0] = ' ';
    (local_208 + sVar2)[1] = '/';
    local_208[sVar2 + 2] = ' ';
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects1.start + 7))
    ;
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 8;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"Scale: ",7);
    local_218 = uVar1;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects1.capacity +
                                     3));
    sVar2 = local_218;
    uVar6 = local_218 + 3;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    (local_208 + sVar2)[0] = ' ';
    (local_208 + sVar2)[1] = '/';
    local_208[sVar2 + 2] = ' ';
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects1.start + 3))
    ;
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    uVar1 = sVar2 + 8;
    pcVar7 = local_208;
    if (local_210 < uVar1) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar1) {
        local_210 = uVar1;
      }
      local_218 = uVar6;
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    builtin_strncpy(local_208 + sVar2 + 1,"ColOp: ",7);
    local_218 = uVar1;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects2.start + 3))
    ;
    sVar2 = local_218;
    uVar6 = local_218 + 3;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    (local_208 + sVar2)[0] = ' ';
    (local_208 + sVar2)[1] = '/';
    local_208[sVar2 + 2] = ' ';
    local_218 = uVar6;
    fmt::BasicWriter<char>::FormatInt<>
              (iVar4,(IntFormatSpec *)
                     (ulong)*(uint *)((long)&(this->PlayLayer_data).m_activeSaveObjects1.last + 3));
    sVar2 = local_218;
    uVar6 = local_218 + 1;
    pcVar7 = local_208;
    if (local_210 < uVar6) {
      local_210 = local_210 + (local_210 >> 1);
      if (local_210 < uVar6) {
        local_210 = uVar6;
      }
      pcVar7 = operator.new[](local_210);
      if (local_218 != 0) {
        memmove(pcVar7,local_208,local_218);
      }
      if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
        operator.delete[](local_208);
      }
    }
    local_208 = pcVar7;
    local_208[sVar2] = '\n';
    plVar8 = *(long **)&this[1].CCNode_data.m_fScaleX;
    uVar1 = sVar2 + 2;
    pcVar10 = *(code **)(*plVar8 + 0x390);
    local_218 = uVar6;
    if (local_210 < uVar1) {
      fmt::internal::Array<char,500ul>::grow((Array<char,500ul> *)&local_218,uVar1);
    }
    local_208[uVar6] = '\0';
    (*pcVar10)(plVar8,local_208);
    if ((local_208 != local_200) && (local_208 != (char *)0x0)) {
      operator.delete[](local_208);
    }
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}






void PlayLayer::updateProgressbar(PlayLayer *this)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  CCString *this_00;
  undefined8 uVar5;
  GameToolbox *this_01;
  uint uVar6;
  int *piVar7;
  long *plVar8;
  code *pcVar9;
  float fVar10;
  float fVar11;
  double dVar12;
  float fVar13;
  CCRect local_18;
  long local_8;
  
  local_8 = ___stack_chk_guard;
  if (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0')
  goto LAB_006cf010;
  fVar10 = (float)getCurrentPercent(this);
  fVar13 = *(float *)((long)&(this->PlayLayer_data).m_currentTime + 3);
  if (fVar10 <= 0.01) {
    if (fVar13 * 0.0001 < fVar13) {
      fVar11 = fVar13 * 0.0001;
      if (fVar10 <= 0.01) goto LAB_006cf068;
      fVar13 = fVar13 * (fVar10 / 100.0);
    }
  }
  else {
    fVar11 = fVar13 * (fVar10 / 100.0);
    if (fVar11 < fVar13) {
LAB_006cf068:
      fVar13 = fVar11;
    }
  }
  plVar8 = *(long **)((long)&(this->PlayLayer_data).m_pauseTime + 3);
  pcVar9 = *(code **)(*plVar8 + 0x460);
  cocos2d::CCRect::CCRect
            (&local_18,0.0,0.0,fVar13,*(float *)((long)&(this->PlayLayer_data).m_currentTime + 7));
  (*pcVar9)(plVar8,&local_18);
  if (*(char *)((long)&(this->PlayLayer_data).m_attemptTime + 3) == '\0') {
    uVar6 = (uint)fVar10;
    this_01 = (GameToolbox *)0x64;
    if ((int)uVar6 < 100) {
      uVar1 = uVar6;
      if ((int)uVar6 < 0) {
        uVar1 = 0;
      }
      this_01 = (GameToolbox *)(ulong)uVar1;
    }
    GameToolbox::intToString(this_01,uVar6);
                    
    FUN_00e15fd4(&local_18,"%",1);
    plVar8 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
    (**(code **)(*plVar8 + 0x390))(plVar8,local_18._0_8_);
    if ((undefined8 *)(local_18._0_8_ + -0x18) != &DAT_0134b6b0) {
      piVar7 = (int *)(local_18._0_8_ + -8);
      do {
        iVar2 = *piVar7;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar7,0x10);
        if (bVar4) {
          *piVar7 = iVar2 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (iVar2 < 1) {
        operator.delete((undefined8 *)(local_18._0_8_ + -0x18));
      }
    }
  }
  else {
    if (fVar10 < 0.0) {
      dVar12 = 0.0;
    }
    else if (100.0 <= fVar10) {
      dVar12 = 100.0;
    }
    else {
      dVar12 = 0.0;
      if (0.0 <= fVar10) {
        dVar12 = (double)fVar10;
      }
    }
    plVar8 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
    pcVar9 = *(code **)(*plVar8 + 0x390);
    this_00 = (CCString *)cocos2d::CCString::createWithFormat("%.2f%%",dVar12);
    uVar5 = cocos2d::CCString::getCString(this_00);
    (*pcVar9)(plVar8,uVar5);
  }
LAB_006cf010:
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}




void
PlayLayer::updateScreenRotation
          (PlayLayer *this,int param_1,bool param_2,bool param_3,float param_4,int param_5,
          float param_6,int param_7,int param_8)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)param_1;
  fVar2 = fVar1;
  if (param_2) {
    fVar2 = fVar1 + (this->GJBaseGameLayer_data).m_gameState.m_targetCameraAngle;
  }
  if (param_3) {
    GJBaseGameLayer::convertToClosestDirection(fVar2,180.0);
  }
  if (fVar2 != (this->GJBaseGameLayer_data).m_gameState.m_targetCameraAngle) {
    *(undefined1 *)((long)&(this->GJBaseGameLayer_data).m_audioEffectsLayer + 4) = 1;
  }
  GJBaseGameLayer::updateScreenRotation
            ((GJBaseGameLayer *)this,fVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}




void PlayLayer::updateTestModeLabel(PlayLayer *this)

{
  char cVar1;
  long *plVar2;
  
  plVar2 = *(long **)&(this->PlayLayer_data).field_0x170;
  if (plVar2 != (long *)0x0) {
    if ((this->PlayLayer_data).field_0x16e == '\0') {
      (**(code **)(*plVar2 + 0x148))
                (plVar2,*(undefined1 *)&(this->GJBaseGameLayer_data).m_halfCameraWidth);
      cVar1 = (this->GJBaseGameLayer_data).m_ignoreDamage;
    }
    else {
      (**(code **)(*plVar2 + 0x148))(plVar2);
      cVar1 = (this->GJBaseGameLayer_data).m_ignoreDamage;
    }
    if (cVar1 != '\0') {
      plVar2 = *(long **)&(this->PlayLayer_data).field_0x170;
      (**(code **)(*plVar2 + 0x390))(plVar2,"Ignore Damage");
      return;
    }
    if ((this->PlayLayer_data).field_0x16e != '\0') {
      plVar2 = *(long **)&(this->PlayLayer_data).field_0x170;
      (**(code **)(*plVar2 + 0x390))(plVar2,"Used Ignore Damage");
      return;
    }
    if (*(char *)&(this->GJBaseGameLayer_data).m_halfCameraWidth != '\0') {
      plVar2 = *(long **)&(this->PlayLayer_data).field_0x170;
      (**(code **)(*plVar2 + 0x390))(plVar2,"Testmode");
      return;
    }
  }
  return;
}







void PlayLayer::updateTimeLabel(PlayLayer *this,int param_1,int param_2,bool param_3)

{
  int iVar1;
  bool bVar2;
  CCPoint CVar3;
  char cVar4;
  size_t sVar5;
  long lVar6;
  CCString *this_00;
  char *__s;
  int *piVar7;
  long *plVar8;
  long lVar9;
  code *pcVar10;
  undefined1 *local_20;
  float local_18;
  CCPoint local_10;
  long local_8;
  
  plVar8 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
  local_8 = ___stack_chk_guard;
  cVar4 = (**(code **)(*plVar8 + 0x150))(plVar8);
  if ((cVar4 != '\0') &&
     (*(char *)((long)&(this->GJBaseGameLayer_data).m_unclaimedParticles + 6) != '\0')) {
    local_20 = &DAT_0134b6c8;
    if (param_3) {
      this_00 = (CCString *)
                cocos2d::CCString::createWithFormat
                          ("%i.%02d",(GameToolbox *)(ulong)(uint)param_1,(ulong)(uint)param_2);
      __s = (char *)cocos2d::CCString::getCString(this_00);
      sVar5 = strlen(__s);
      FUN_00e1798c(&local_20,__s,sVar5);
    }
    else {
                    
      GameToolbox::intToString((GameToolbox *)(ulong)(uint)param_1,param_1);
      CVar3 = local_10;
      sVar5 = strlen((char *)local_10);
                    
      FUN_00e1798c(&local_20,CVar3,sVar5);
      if ((char *)((long)local_10 + -0x18) != (char *)&DAT_0134b6b0) {
        piVar7 = (int *)((long)local_10 + -8);
        do {
          iVar1 = *piVar7;
          cVar4 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(piVar7,0x10);
          if (bVar2) {
            *piVar7 = iVar1 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        if (iVar1 < 1) {
          operator.delete((char *)((long)local_10 + -0x18));
        }
      }
    }
    plVar8 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
                    
    (**(code **)(*plVar8 + 0x390))(plVar8,local_20);
    cocos2d::CCDirector::sharedDirector();
    cocos2d::CCDirector::getWinSize();
    plVar8 = *(long **)((long)&(this->PlayLayer_data).m_unk38d0 + 3);
    lVar9 = *(long *)(local_20 + -0x18);
    pcVar10 = *(code **)(*plVar8 + 0xb8);
    lVar6 = (**(code **)(*plVar8 + 0xc0))(plVar8);
    cocos2d::CCPoint::CCPoint
              (&local_10,local_18 * 0.5 - (float)(ulong)(lVar9 * 5),*(float *)(lVar6 + 4));
    (*pcVar10)(plVar8,&local_10);
    if ((undefined8 *)(local_20 + -0x18) != &DAT_0134b6b0) {
      piVar7 = (int *)(local_20 + -8);
      do {
        iVar1 = *piVar7;
        cVar4 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(piVar7,0x10);
        if (bVar2) {
          *piVar7 = iVar1 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (iVar1 < 1) {
        operator.delete(local_20 + -0x18);
      }
    }
  }
  if (local_8 != ___stack_chk_guard) {
                    
    __stack_chk_fail();
  }
  return;
}




void PlayLayer::updateTimeWarp(PlayLayer *this,float param_1)

{
  if (*(char *)&(this->GJBaseGameLayer_data).m_nonEffectObjectsSizes.start != '\0') {
    param_1 = 1.0;
  }
  GJBaseGameLayer::updateTimeWarp((GJBaseGameLayer *)this,param_1);
  return;
}





void PlayLayer::updateVerifyDamage(PlayLayer *this)

{
  float *pfVar1;
  long lVar2;
  CCNode *pCVar3;
  long *plVar4;
  code *pcVar5;
  float fVar6;
  CCPoint CStack_10;
  long local_8;
  
  plVar4 = *(long **)((long)&(this->PlayLayer_data).m_statusLabel + 3);
  local_8 = ___stack_chk_guard;
  if ((plVar4 != (long *)0x0) &&
     (*(char *)((long)&(this->PlayLayer_data).m_speedObjects + 3) == '\0')) {
    if ((this->PlayLayer_data).field_0x16e != '\0') {
      *(undefined1 *)((long)&(this->PlayLayer_data).m_speedObjects + 3) = 1;
    }
    pCVar3 = (this->GJBaseGameLayer_data).m_unkdd0;
    pcVar5 = *(code **)(*plVar4 + 0x548);
    pfVar1 = (float *)(**(code **)(pCVar3->CCCopying + 0xc0))(pCVar3);
    pCVar3 = (this->GJBaseGameLayer_data).m_unkdd0;
    fVar6 = *pfVar1;
    lVar2 = (**(code **)(pCVar3->CCCopying + 0xc0))(pCVar3);
    cocos2d::CCPoint::CCPoint(&CStack_10,fVar6,*(float *)(lVar2 + 4));
    (*pcVar5)(plVar4,&CStack_10);
    (**(code **)(this->CCCopying + 0x528))
              (this,*(undefined8 *)((long)&(this->PlayLayer_data).m_statusLabel + 3));
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}





void PlayLayer::updateVisibility(PlayLayer *this,float param_1)

{
  undefined1 *this_00;
  undefined1 *puVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  char cVar10;
  undefined3 uVar11;
  undefined4 uVar12;
  int iVar13;
  _ccColor3B *p_Var14;
  undefined8 *puVar15;
  CCDirector *this_01;
  GameObject **ppGVar16;
  long lVar17;
  CCPoint *pCVar18;
  undefined2 *puVar19;
  undefined8 uVar20;
  long lVar21;
  FMODAudioEngine *this_02;
  uchar uVar22;
  unordered_map_node<> *puVar23;
  ulong uVar24;
  CCNode *pCVar25;
  long lVar26;
  undefined8 *puVar27;
  ulong uVar28;
  ulong uVar29;
  undefined8 *puVar30;
  int iVar31;
  void *pvVar32;
  code *pcVar33;
  int iVar34;
  GJEffectManager *this_03;
  long lVar35;
  int iVar36;
  EffectGameObject *this_04;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  undefined5 uStack_4d;
  undefined8 local_48;
  byte local_40;
  byte local_3f;
  byte local_3e;
  undefined2 local_38;
  undefined1 uStack_36;
  undefined5 uStack_35;
  undefined1 local_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined5 uStack_2d;
  float local_28;
  float local_20;
  CCPoint local_18;
  CCPoint local_10;
  long local_8;
  
  _cameraRight = (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.x +
                 *(float *)((long)&(this->GJBaseGameLayer_data).m_activeObjects.capacity + 4);
  local_8 = ___stack_chk_guard;
  GJBaseGameLayer::preUpdateVisibility(param_1);
  GJEffectManager::processColors
            ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4);
  this_03 = (GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4;
  uVar12 = GJEffectManager::activeColorForIndex(this_03,0x3ed);
  uStack_2f = (undefined1)((uint)uVar12 >> 8);
  local_30 = (undefined1)uVar12;
  uStack_2e = (undefined1)((uint)uVar12 >> 0x10);
  GJEffectManager::calculateLightBGColor(this_03,CONCAT53(uStack_2d,(int3)uVar12));
  cocos2d::CCDirector::sharedDirector();
  cocos2d::CCDirector::getWinSize();
  puVar23 = (this->GJBaseGameLayer_data).m_labelObjects.listptr;
  p_Var14 = (_ccColor3B *)(*(code *)puVar23->next[0x13].value.second.start)(puVar23);
  uVar11 = GameToolbox::transformColor(p_Var14,0.0,-0.3,0.4);
  uVar12 = GJEffectManager::activeColorForIndex
                     ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,0x3ef);
  local_48._1_1_ = (undefined1)((uint)uVar12 >> 8);
  local_48._2_1_ = (undefined1)((uint)uVar12 >> 0x10);
  local_48._0_1_ = (undefined1)uVar12;
  uVar12 = GJEffectManager::activeColorForIndex
                     ((GJEffectManager *)(this->GJBaseGameLayer_data).m_gameBlendingLayerT4,1000);
  local_3f = (byte)((uint)uVar12 >> 8);
  local_3e = (byte)((uint)uVar12 >> 0x10);
  local_40 = (byte)uVar12;
  uVar12 = GameToolbox::transformColor(&local_40,0.0,-0.2,0.2);
  *(char *)&(this->GJBaseGameLayer_data).m_replayRandSeed = (char)uVar12;
  *(char *)((long)&(this->GJBaseGameLayer_data).m_replayRandSeed + 1) = (char)((uint)uVar12 >> 8);
  *(char *)((long)&(this->GJBaseGameLayer_data).m_replayRandSeed + 2) = (char)((uint)uVar12 >> 0x10)
  ;
  puVar15 = *(undefined8 **)&this[1].CCNode_data.m_sTransform.b;
  puVar27 = *(undefined8 **)&this[1].CCNode_data.m_sTransform.d;
  if (puVar15 != puVar27) {
    puVar30 = puVar15 + 1;
    uVar24 = (ulong)((long)puVar27 - (long)puVar30) >> 3;
    uVar28 = (uVar24 - 1 >> 1) + 1;
    if (2 < uVar24) {
      uVar29 = 0;
      puVar30 = puVar15;
      do {
        puVar30[1] = 0;
        *puVar30 = 0;
        uVar29 = uVar29 + 1;
        puVar30 = puVar30 + 2;
      } while (uVar29 < uVar28);
      puVar15 = puVar15 + uVar28 * 2;
      if (uVar28 * 2 - (uVar24 + 1) == 0) goto LAB_006ce26c;
      puVar30 = puVar15 + 1;
    }
    *puVar15 = 0;
    if ((puVar27 != puVar30) && (puVar15[1] = 0, puVar27 != puVar15 + 2)) {
      puVar15[2] = 0;
    }
  }
LAB_006ce26c:
  fVar42 = local_28 * 0.5 + -75.0;
  fVar41 = fVar42 + 110.0;
  this_01 = (CCDirector *)cocos2d::CCDirector::sharedDirector();
  fVar37 = (float)cocos2d::CCDirector::getScreenRight(this_01);
  fVar37 = (fVar37 - fVar41) - 90.0;
  puVar15 = &local_48;
  if (150.0 <= (float)((uint)local_40 + (uint)local_3f + (uint)local_3e)) {
    puVar15 = &DAT_00fa3590;
  }
  local_38 = *(undefined2 *)puVar15;
  uStack_36 = *(undefined1 *)((long)puVar15 + 2);
  cVar10 = *(char *)&(this->GJBaseGameLayer_data).m_unkdd0[7].CCNode_data.m_pParent;
  bVar7 = GJBaseGameLayer::isFlipping((GJBaseGameLayer *)this);
  if (*(char *)((long)&(this->PlayLayer_data).m_unk3918.x + 3) == '\0') {
    fVar38 = *(float *)(*(long *)&(this->GJBaseGameLayer_data).m_recordInputs + 0x244);
  }
  else {
    this_02 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)(ulong)bVar7);
    fVar38 = (float)FMODAudioEngine::getMeteringValue(this_02);
  }
  if (*(char *)&(this->GJBaseGameLayer_data).m_endPortal == '\0') {
    fVar43 = fVar38;
    if (*(char *)((long)&(this->PlayLayer_data).m_orbs + 3) == '\0') goto LAB_006ce35c;
LAB_006cee90:
    fVar38 = 0.5;
    fVar43 = fVar38;
  }
  else {
    if (*(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) == '\0') {
      fVar38 = 0.5;
    }
    else if (*(char *)((long)&(this->PlayLayer_data).m_orbs + 3) != '\0') goto LAB_006cee90;
    fVar43 = fVar38;
    if (*(char *)((long)&(this->GJBaseGameLayer_data).m_endPortal + 1) == '\0') {
      fVar43 = 0.5;
    }
  }
LAB_006ce35c:
  uVar3 = (this->GJBaseGameLayer_data).m_coinsCollected;
  ppGVar16 = (this->GJBaseGameLayer_data).m_unkdd8.start;
  (this->GJBaseGameLayer_data).m_unkdd0[8].CCNode_data.m_sAdditionalTransform.c = fVar43;
  lVar26 = *(long *)((long)&(this->PlayLayer_data).m_keyColors.last + 3);
  *(float *)((long)ppGVar16 + 0xa7c) = fVar43;
  if (0 < (int)uVar3) {
    this_00 = &(this->PlayLayer_data).field_0x1b4;
    lVar35 = 0;
    iVar34 = 0;
LAB_006ce540:
    do {
      this_04 = *(EffectGameObject **)
                 ((long)&((this->GJBaseGameLayer_data).m_unk32c8)->CCCopying + lVar35);
      iVar13 = (this_04->GameObject_data).m_mainColorKeyIndex;
      if (iVar13 < 1) {
        GameObject::updateMainColor((GameObject *)this_04);
        GameObject::updateSecondaryColor((GameObject *)this_04);
      }
      else {
        uVar28 = (ulong)iVar13;
        if ((1L << (uVar28 & 0x1f) &
            *(ulong *)(*(long *)&this[1].CCNode_data.m_sTransform.b + (uVar28 >> 5) * 8)) == 0) {
          lVar17 = *(long *)&this[1].CCNode_data.m_obAnchorPointInPoints.y;
          puVar19 = (undefined2 *)
                    GameObject::colorForMode
                              ((GameObject *)this_04,(this_04->GameObject_data).m_activeMainColorID,
                               true);
          *(undefined2 *)(lVar17 + uVar28 * 3) = *puVar19;
          *(undefined1 *)(lVar17 + uVar28 * 3 + 2) = *(undefined1 *)(puVar19 + 1);
          iVar13 = (this_04->GameObject_data).m_mainColorKeyIndex;
          lVar21 = *(long *)&this[1].CCNode_data.m_sAdditionalTransform.b;
          uVar12 = GameObject::opacityModForMode
                             ((GameObject *)this_04,(this_04->GameObject_data).m_activeMainColorID,
                              true);
          uVar28 = (ulong)(this_04->GameObject_data).m_mainColorKeyIndex;
          lVar17 = *(long *)&this[1].CCNode_data.m_sTransform.b;
          *(undefined4 *)(lVar21 + (long)iVar13 * 4) = uVar12;
          *(ulong *)(lVar17 + (uVar28 >> 5) * 8) =
               *(ulong *)(lVar17 + (uVar28 >> 5) * 8) | 1L << (uVar28 & 0x1f);
        }
        (**(code **)(this_04->CCCopying + 0x620))
                  (this_04,*(long *)&this[1].CCNode_data.m_obAnchorPointInPoints.y + uVar28 * 3);
        ((this_04->GameObject_data).m_baseColor)->m_opacity =
             *(float *)(*(long *)&this[1].CCNode_data.m_sAdditionalTransform.b +
                       (long)(this_04->GameObject_data).m_mainColorKeyIndex * 4);
        cVar8 = GameObject::hasSecondaryColor((GameObject *)this_04);
        if (cVar8 != '\0') {
          uVar28 = (ulong)(this_04->GameObject_data).m_detailColorKeyIndex;
          if ((1L << (uVar28 & 0x1f) &
              *(ulong *)(*(long *)&this[1].CCNode_data.m_sTransform.b + (uVar28 >> 5) * 8)) == 0) {
            lVar17 = *(long *)&this[1].CCNode_data.m_obAnchorPointInPoints.y;
            puVar19 = (undefined2 *)
                      GameObject::colorForMode
                                ((GameObject *)this_04,
                                 (this_04->GameObject_data).m_activeDetailColorID,false);
            *(undefined2 *)(lVar17 + uVar28 * 3) = *puVar19;
            *(undefined1 *)(lVar17 + uVar28 * 3 + 2) = *(undefined1 *)(puVar19 + 1);
            iVar13 = (this_04->GameObject_data).m_detailColorKeyIndex;
            lVar21 = *(long *)&this[1].CCNode_data.m_sAdditionalTransform.b;
            uVar12 = GameObject::opacityModForMode
                               ((GameObject *)this_04,
                                (this_04->GameObject_data).m_activeDetailColorID,false);
            uVar28 = (ulong)(this_04->GameObject_data).m_detailColorKeyIndex;
            lVar17 = *(long *)&this[1].CCNode_data.m_sTransform.b;
            *(undefined4 *)(lVar21 + (long)iVar13 * 4) = uVar12;
            *(ulong *)(lVar17 + (uVar28 >> 5) * 8) =
                 *(ulong *)(lVar17 + (uVar28 >> 5) * 8) | 1L << (uVar28 & 0x1f);
          }
          (**(code **)(this_04->CCCopying + 0x628))
                    (this_04,*(long *)&this[1].CCNode_data.m_obAnchorPointInPoints.y + uVar28 * 3);
          ((this_04->GameObject_data).m_detailColor)->m_opacity =
               *(float *)(*(long *)&this[1].CCNode_data.m_sAdditionalTransform.b +
                         (long)(this_04->GameObject_data).m_detailColorKeyIndex * 4);
        }
      }
      if ((lVar26 != 0) && ((this_04->GameObject_data).m_isActivated != false)) {
        puVar1 = (undefined1 *)((long)&(this->PlayLayer_data).m_unk3920.x + 3);
        lVar17 = FUN_006c955c(puVar1,(this_04->GameObject_data).m_activeMainColorID);
        cVar8 = GameObject::hasSecondaryColor((GameObject *)this_04);
        if (((cVar8 != '\0') &&
            (lVar21 = FUN_006c955c(puVar1,(this_04->GameObject_data).m_activeDetailColorID),
            lVar21 != 0)) || (lVar17 != 0)) {
          (**(code **)(this_04->CCCopying + 0x4f0))(this_04,0);
          GameObject::addColorSpriteToParent((GameObject *)this_04,false);
        }
      }
      (**(code **)(this_04->CCCopying + 0x508))(this_04);
      (**(code **)(this_04->CCCopying + 0x540))(&local_10,this_04);
      cocos2d::CCPoint::operator=((CCPoint *)this_00,(CCPoint *)&local_10);
      iVar13 = (int)(this_04->GameObject_data).m_enterType;
      if ((iVar13 != -1) ||
         ((iVar31 = (int)(this_04->GameObject_data).m_exitType, iVar31 == -1 &&
          ((this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.x +
           *(float *)&(this->GJBaseGameLayer_data).m_lightBGColor <
           *(float *)&(this->PlayLayer_data).field_0x1b4)))) {
        bVar4 = true;
        iVar36 = (this->GJBaseGameLayer_data).m_gameState.m_enterChannelMap.start
                 [(int)(this_04->GameObject_data).m_enterChannel];
        iVar31 = iVar13;
      }
      else {
        bVar4 = false;
        iVar36 = (this->GJBaseGameLayer_data).m_gameState.m_exitChannelMap.start
                 [(int)(this_04->GameObject_data).m_enterChannel];
      }
      if ((this_04->GameObject_data).m_isUIObject != false) {
        iVar31 = -0xe;
        iVar36 = -0xe;
      }
      cVar8 = (**(code **)(this_04->CCCopying + 0x6b0))(this_04);
      if (cVar8 != '\0') {
        (**(code **)(this_04->CCCopying + 0x728))
                  ((float)(this->GJBaseGameLayer_data).m_gameState.m_totalTime,this_04,0xffffffff);
      }
      cVar8 = (**(code **)(this_04->CCCopying + 0x6b8))(this_04);
      if (cVar8 != '\0') {
        EnhancedGameObject::updateRotateAction((EnhancedGameObject *)this_04,param_1);
      }
      if ((this_04->GameObject_data).m_unk367 == false) {
        iVar13 = (**(code **)(this_04->CCCopying + 0x6f8))(this_04);
        if (iVar13 != 0x1e) goto LAB_006ce458;
LAB_006ce66c:
        pCVar25 = (this->GJBaseGameLayer_data).m_hoverNode;
        lVar17 = (**(code **)(pCVar25->CCCopying + 0xc0))(pCVar25);
        EffectGameObject::updateInteractiveHover(this_04,*(float *)(lVar17 + 4));
        iVar13 = (this_04->GameObject_data).m_objectID;
      }
      else {
        AnimatedGameObject::updateChildSpriteColor
                  ((AnimatedGameObject *)this_04,CONCAT53(uStack_4d,uVar11));
        iVar13 = (**(code **)(this_04->CCCopying + 0x6f8))(this_04);
        if (iVar13 == 0x1e) goto LAB_006ce66c;
LAB_006ce458:
        iVar13 = (this_04->GameObject_data).m_objectID;
      }
      if (iVar13 == 0x8f) {
        (**(code **)(this_04->CCCopying + 0x5d0))
                  (this_04,&(this->GJBaseGameLayer_data).m_replayRandSeed);
      }
      if ((this_04->GameObject_data).m_unk3F8 != false) {
LAB_006ce52c:
        iVar34 = iVar34 + 1;
        lVar35 = lVar35 + 8;
        if ((int)(this->GJBaseGameLayer_data).m_coinsCollected <= iVar34) break;
        goto LAB_006ce540;
      }
      if (((this_04->GameObject_data).m_usesAudioScale != false) &&
         ((this_04->GameObject_data).m_hasNoAudioScale == false)) {
        if ((this_04->GameObject_data).m_customAudioScale == false) {
          (**(code **)(this_04->CCCopying + 0x5a0))(fVar38,this_04);
        }
        else {
          fVar43 = (this_04->GameObject_data).m_minAudioScale;
          (**(code **)(this_04->CCCopying + 0x5a0))
                    (fVar43 + ((this_04->GameObject_data).m_maxAudioScale - fVar43) * (fVar38 - 0.1)
                     ,this_04);
        }
      }
      if ((this_04->GameObject_data).m_glowColorIsLBG != false) {
        if ((this_04->GameObject_data).m_customGlowColor == false) {
          (**(code **)(this_04->CCCopying + 0x5d0))
                    (this_04,&(this->GJBaseGameLayer_data).m_replayRandSeed);
        }
        else {
          (**(code **)(this_04->CCCopying + 0x5d0))(this_04,&local_48);
        }
      }
      if ((this_04->GameObject_data).m_isInvisibleBlock == false) {
        cVar8 = GameObject::ignoreFade((GameObject *)this_04);
        if (((cVar8 != '\0') || (iVar36 == -0xe)) ||
           (((this_04->GameObject_data).m_intrinsicDontFade != false &&
            (((((this_04->GameObject_data).m_isSolidColorBlock == false ||
               ((this_04->GameObject_data).m_baseOrDetailBlending == false)) && (iVar31 + 2U < 2))
             && (iVar36 == -2)))))) {
          (**(code **)(this_04->CCCopying + 0x380))(this_04,0xffffffff);
          goto joined_r0x006ce898;
        }
        if (iVar36 == -0xf) goto LAB_006ce89c;
        cocos2d::CCPoint::CCPoint(&local_18,(CCPoint *)this_00);
        fVar43 = (this_04->GameObject_data).m_fadeMargin;
        if (bVar4 == false) {
          local_18.x = local_18.x + fVar43;
        }
        else {
          local_18.x = local_18.x - fVar43;
        }
        pcVar33 = *(code **)(this_04->CCCopying + 0x380);
        cocos2d::CCPoint::CCPoint(&local_10,(CCPoint *)&local_18);
        fVar43 = (float)getRelativeModNew((PlayLayer *)0x428c0000,0,this,&local_10,0,bVar4);
        (*pcVar33)(this_04,(int)(fVar43 * 255.0));
LAB_006ce508:
        applyEnterEffect(this,(GameObject *)this_04,iVar36,bVar4);
      }
      else {
        if (cVar10 == '\0') {
          (**(code **)(this_04->CCCopying + 0x540))(&local_18,this_04);
          fVar43 = (this_04->GameObject_data).m_fadeMargin;
          if (local_18.x <= (float)(this->GJBaseGameLayer_data).m_activeObjectsIndex) {
            local_18.x = local_18.x + fVar43;
          }
          else {
            local_18.x = local_18.x - fVar43;
          }
          cocos2d::CCPoint::CCPoint(&local_10,(CCPoint *)&local_18);
          fVar43 = (float)getRelativeMod((PlayLayer *)0x3ca3d70a,0x3c6a0ea1,0,this,&local_10);
          fVar39 = (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition2.x;
          fVar43 = fVar43 * 255.0;
          if (local_18.x <= fVar41 + fVar39) {
            fVar40 = (fVar42 + fVar39) - local_18.x;
            fVar39 = fVar42 - 30.0;
            if (fVar42 - 30.0 < 1.0) goto LAB_006cecf8;
LAB_006ce7f8:
            fVar40 = fVar40 / fVar39;
            if (1.0 <= fVar40) goto code_r0x006ce80c;
LAB_006ced0c:
            if (0.0 < fVar40) {
              fVar39 = (fVar40 * 0.95 + 0.05) * 255.0;
            }
            else {
              fVar39 = 12.75;
              fVar40 = 0.0;
            }
          }
          else {
            fVar40 = (local_18.x - fVar39) - fVar41;
            fVar39 = fVar37;
            if (1.0 <= fVar37) goto LAB_006ce7f8;
LAB_006cecf8:
            fVar40 = fVar40 / 1.0;
            if (fVar40 < 1.0) goto LAB_006ced0c;
code_r0x006ce80c:
            fVar40 = 1.0;
            fVar39 = 255.0;
          }
          if (fVar39 <= fVar43) {
            uVar2 = (undefined1)(int)fVar39;
          }
          else {
            uVar2 = (undefined1)(int)fVar43;
          }
          (**(code **)(this_04->CCCopying + 0x380))(this_04,uVar2);
          fVar39 = (fVar40 * 0.85 + 0.15) * 255.0;
          if (fVar39 <= fVar43) {
            uVar22 = (uchar)(int)fVar39;
          }
          else {
            uVar22 = (uchar)(int)fVar43;
          }
          GameObject::setGlowOpacity((GameObject *)this_04,uVar22);
          bVar9 = (**(code **)(this_04->CCCopying + 0x370))(this_04);
          if (0.8 < (float)bVar9 / 255.0) {
            uVar20._0_4_ = (this->GJBaseGameLayer_data).m_replayRandSeed;
            uVar20._4_4_ = (this->GJBaseGameLayer_data).m_unk32ec;
            uVar12 = GJEffectManager::getMixedColor
                               ((1.0 - ((float)bVar9 / 255.0 - 0.8) / 0.2) * 0.3 + 0.7,uVar20,
                                CONCAT53(uStack_35,CONCAT12(uStack_36,local_38)));
            local_10.x._1_1_ = (undefined1)((uint)uVar12 >> 8);
            local_10.x._0_1_ = (undefined1)uVar12;
            local_10.x._2_1_ = (undefined1)((uint)uVar12 >> 0x10);
            (**(code **)(this_04->CCCopying + 0x5d0))(this_04,&local_10);
          }
          else {
            (**(code **)(this_04->CCCopying + 0x5d0))
                      (this_04,&(this->GJBaseGameLayer_data).m_replayRandSeed);
          }
        }
        else {
          (**(code **)(this_04->CCCopying + 0x5d0))
                    (this_04,&(this->GJBaseGameLayer_data).m_replayRandSeed);
          (**(code **)(this_04->CCCopying + 0x380))(this_04,0xffffffff);
          GameObject::setGlowOpacity((GameObject *)this_04,0xff);
        }
joined_r0x006ce898:
        if (iVar36 != -0xf) goto LAB_006ce508;
LAB_006ce89c:
        cVar8 = GameObject::ignoreEnter((GameObject *)this_04);
        if (cVar8 != '\0') goto LAB_006ce508;
        applyCustomEnterEffect(this,(GameObject *)this_04,bVar4);
      }
      if (bVar7 == 0) {
        if (*(char *)&(this->GJBaseGameLayer_data).m_cameraWidth != '\0') {
          (**(code **)(this_04->CCCopying + 0x4c8))(this_04,(this_04->GameObject_data).m_startFlipX)
          ;
          (**(code **)(this_04->CCCopying + 0x4d0))(this_04,(this_04->GameObject_data).m_startFlipY)
          ;
          (**(code **)(this_04->CCCopying + 0x158))
                    ((this_04->GameObject_data).m_startRotationX,this_04);
          pcVar33 = *(code **)(this_04->CCCopying + 0xb8);
          uVar20 = (**(code **)(this_04->CCCopying + 0xc0))(this_04);
          (*pcVar33)(this_04,uVar20);
        }
        goto LAB_006ce52c;
      }
      fVar43 = (this->GJBaseGameLayer_data).m_gameState.m_levelFlipping;
      if (*(float *)&(this->GJBaseGameLayer_data).m_calculateTargetHeightOffset == -1.0) {
        fVar43 = 1.0 - fVar43;
      }
      cocos2d::CCDirector::sharedDirector();
      cocos2d::CCDirector::getWinSize();
      pCVar18 = (CCPoint *)(**(code **)(this_04->CCCopying + 0xc0))(this_04);
      cocos2d::CCPoint::CCPoint(&local_18,pCVar18);
      pcVar33 = *(code **)(this_04->CCCopying + 0xb8);
      cocos2d::CCPoint::CCPoint
                (&local_10,
                 local_18.x +
                 fVar43 * (local_20 / (this->GJBaseGameLayer_data).m_gameState.m_cameraZoom -
                          (local_18.x - (this->GJBaseGameLayer_data).m_gameState.m_cameraPosition.x)
                          * 2.0),local_18.y);
      (*pcVar33)(this_04,&local_10);
      fVar43 = (float)(**(code **)(this_04->CCCopying + 0x160))(this_04);
      fVar43 = ABS(fVar43);
      bVar4 = fVar43 == 270.0;
      bVar5 = fVar43 == 90.0;
      bVar6 = (int)fVar43 % 0x5a == 0;
      if (*(float *)&(this->GJBaseGameLayer_data).m_calculateTargetHeightOffset == 1.0) {
        fVar43 = (this->GJBaseGameLayer_data).m_gameState.m_levelFlipping;
        if (0.5 <= fVar43) goto LAB_006ce9cc;
        if (((this->GJBaseGameLayer_data).m_gameState.m_unkBool11 != false) &&
           (iVar13 = 1, fVar43 <= 0.5)) {
          if (bVar4 || bVar5) goto LAB_006ceec0;
LAB_006ced6c:
          (**(code **)(this_04->CCCopying + 0x4c8))
                    (this_04,(uint)(this_04->GameObject_data).m_startFlipX * iVar13 != 0);
          goto LAB_006ced8c;
        }
        goto LAB_006ce52c;
      }
      fVar43 = (this->GJBaseGameLayer_data).m_gameState.m_levelFlipping;
      if (0.5 < fVar43) {
        if (((this->GJBaseGameLayer_data).m_gameState.m_unkBool11 != false) && (0.5 <= fVar43)) {
          iVar13 = -1;
          if (!bVar4 && !bVar5) goto LAB_006ced6c;
LAB_006ceec0:
          (**(code **)(this_04->CCCopying + 0x4d0))
                    (this_04,iVar13 * (uint)(this_04->GameObject_data).m_startFlipY != 0);
LAB_006ced8c:
          if (!bVar6) {
            (**(code **)(this_04->CCCopying + 0x158))
                      ((float)iVar13 * (this_04->GameObject_data).m_startRotationX,this_04);
          }
        }
        goto LAB_006ce52c;
      }
LAB_006ce9cc:
      if (bVar4 || bVar5) {
        (**(code **)(this_04->CCCopying + 0x4d0))
                  (this_04,(this_04->GameObject_data).m_startFlipY ^ 1);
      }
      else {
        (**(code **)(this_04->CCCopying + 0x4c8))
                  (this_04,(this_04->GameObject_data).m_startFlipX ^ 1);
      }
      if (bVar6) goto LAB_006ce52c;
      iVar34 = iVar34 + 1;
      lVar35 = lVar35 + 8;
      (**(code **)(this_04->CCCopying + 0x158))
                (-(this_04->GameObject_data).m_startRotationX,this_04);
    } while (iVar34 < (int)(this->GJBaseGameLayer_data).m_coinsCollected);
  }
  GJBaseGameLayer::updateEnterEffects((GJBaseGameLayer *)this,param_1);
  GJBaseGameLayer::processAreaVisualActions((GJBaseGameLayer *)this,param_1);
  GJBaseGameLayer::updateParticles((GJBaseGameLayer *)this,param_1);
  puVar15 = *(undefined8 **)((long)&(this->PlayLayer_data).m_keyColors.start + 3);
  *(undefined1 *)&(this->GJBaseGameLayer_data).m_cameraWidth = 0;
  while (puVar15 != (void *)0x0) {
    pvVar32 = (void *)*puVar15;
    operator.delete(puVar15);
    puVar15 = pvVar32;
  }
  memset(*(void **)((long)&(this->PlayLayer_data).m_unk3920.x + 3),0,
         *(long *)((long)&(this->PlayLayer_data).m_colorKeyDict + 3) << 3);
  *(undefined8 *)((long)&(this->PlayLayer_data).m_keyColors.last + 3) = 0;
  *(undefined8 *)((long)&(this->PlayLayer_data).m_keyColors.start + 3) = 0;
  cVar10 = shouldDebugDraw(this);
  if (cVar10 != '\0') {
    (**(code **)(this->CCCopying + 0x508))(this);
  }
  if (local_8 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}






void PlayLayer::~PlayLayer(PlayLayer *this)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  GJGameLevel *this_00;
  CCObject *pCVar5;
  GameManager *this_01;
  long lVar6;
  PlayLayer *this_02;
  FMODAudioEngine *this_03;
  long *plVar7;
  undefined8 *puVar8;
  void *pvVar9;
  int *piVar10;
  long *plVar11;
  
  lVar4 = ___stack_chk_guard;
  this->CCCopying = (CCCopying *)vftable;
  this->CCTouchDelegate = (CCTouchDelegate *)&PTR_~PlayLayer_01248b68;
  this->CCAccelerometerDelegate = (CCAccelerometerDelegate *)&DAT_01248bd8;
  this->CCKeypadDelegate = (CCKeypadDelegate *)&PTR_keyBackClicked_01248bf0;
  this->CCKeyboardDelegate = (CCKeyboardDelegate *)&PTR_keyDown_01248c10;
  this->CCMouseDelegate = (CCMouseDelegate *)&PTR_rightKeyDown_01248c30;
  this->TriggerEffectDelegate = (TriggerEffectDelegate *)&PTR_toggleGroupTriggered_01248c58;
  *(undefined **)((long)&(this->PlayLayer_data).m_unk3788 + 3) = &DAT_01248c88;
  *(undefined **)&(this->PlayLayer_data).field_0xc0 = &DAT_01248ca0;
  *(undefined **)((long)&(this->PlayLayer_data).m_currentCheckpoint + 3) = &DAT_01248cb8;
  PlatformToolbox::showCursor();
  this_00 = (this->GJBaseGameLayer_data).m_level;
  if (this_00 != (GJGameLevel *)0x0) {
    cocos2d::CCObject::release((CCObject *)this_00);
  }
  pCVar5 = *(CCObject **)((long)&(this->PlayLayer_data).m_blendingColors.resize + 3);
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = (CCObject *)(this->GJBaseGameLayer_data).m_unkdd8.last;
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = *(CCObject **)&(this->PlayLayer_data).field_0x230;
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = (CCObject *)(this->GJBaseGameLayer_data).m_unkdd8.start;
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = *(CCObject **)((long)&(this->PlayLayer_data).m_lastAttemptPercent + 3);
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = *(CCObject **)((long)&(this->PlayLayer_data).m_blendingColors.factor + 3);
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = *(CCObject **)&this[1].CCNode_data.m_fSkewY;
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = *(CCObject **)&(this->PlayLayer_data).field_0x1d0;
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = *(CCObject **)((long)&(this->PlayLayer_data).m_blendingColors.single + 3);
  if (pCVar5 != (CCObject *)0x0) {
    cocos2d::CCObject::release(pCVar5);
  }
  pCVar5 = *(CCObject **)((long)&(this->PlayLayer_data).m_unk38b0 + 3);
  this_01 = (GameManager *)0x0;
  if (pCVar5 != (CCObject *)0x0) {
    this_01 = (GameManager *)cocos2d::CCObject::release(pCVar5);
  }
  lVar6 = GameManager::sharedState(this_01);
  this_02 = *(PlayLayer **)(lVar6 + 0x1d8);
  if (this == this_02) {
    this_02 = (PlayLayer *)GameManager::sharedState((GameManager *)this_02);
    (this_02->GJBaseGameLayer_data).m_gameState.m_unkPoint5.x = 0.0;
    (this_02->GJBaseGameLayer_data).m_gameState.m_unkPoint5.y = 0.0;
  }
  this_03 = (FMODAudioEngine *)FMODAudioEngine::sharedEngine((FMODAudioEngine *)this_02);
  FMODAudioEngine::disableMetering(this_03);
  plVar7 = (long *)cocos2d::CCDirector::sharedDirector();
  lVar6 = (**(code **)(*plVar7 + 0xc0))();
  pvVar9 = *(void **)&this[1].CCNode_data.m_sTransform.b;
  *(undefined1 *)(lVar6 + 0x5c) = 0;
  if (pvVar9 != (void *)0x0) {
    operator.delete(pvVar9);
  }
  pvVar9 = *(void **)&this[1].CCNode_data.m_sAdditionalTransform.b;
  if (pvVar9 != (void *)0x0) {
    operator.delete(pvVar9);
  }
  pvVar9 = *(void **)&this[1].CCNode_data.m_obAnchorPointInPoints.y;
  if (pvVar9 != (void *)0x0) {
    operator.delete(pvVar9);
  }
  std::_Hashtable<>::~_Hashtable((_Hashtable<> *)((long)&(this->PlayLayer_data).m_unk3920.x + 3));
  pvVar9 = *(void **)((long)&(this->PlayLayer_data).m_totalGravityEffects + 3);
  if (pvVar9 != (void *)0x0) {
    operator.delete(pvVar9);
  }
  pvVar9 = *(void **)((long)&(this->PlayLayer_data).m_progressBar + 3);
  if (pvVar9 != (void *)0x0) {
    operator.delete(pvVar9);
  }
  pvVar9 = *(void **)((long)&(this->PlayLayer_data).m_attemptLabel + 3);
  if (pvVar9 != (void *)0x0) {
    operator.delete(pvVar9);
  }
  pvVar9 = *(void **)((long)&(this->PlayLayer_data).m_collectibles + 3);
  if (pvVar9 != (void *)0x0) {
    operator.delete(pvVar9);
  }
  plVar7 = *(long **)&(this->PlayLayer_data).field_0xe0;
  plVar11 = *(long **)((long)&(this->PlayLayer_data).m_enterEffectPosition.y + 3);
  if (plVar11 != plVar7) {
    do {
      while( true ) {
        puVar8 = (undefined8 *)(*plVar7 + -0x18);
        if (puVar8 != &DAT_0134b6b0) break;
LAB_006d385c:
        plVar7 = plVar7 + 1;
        if (plVar11 == plVar7) goto LAB_006d38b4;
      }
      piVar10 = (int *)(*plVar7 + -8);
      do {
        iVar1 = *piVar10;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar10,0x10);
        if (bVar3) {
          *piVar10 = iVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (0 < iVar1) goto LAB_006d385c;
      plVar7 = plVar7 + 1;
      operator.delete(puVar8);
    } while (plVar11 != plVar7);
LAB_006d38b4:
    plVar11 = *(long **)&(this->PlayLayer_data).field_0xe0;
  }
  if (plVar11 != (long *)0x0) {
    operator.delete(plVar11);
  }
  GJBaseGameLayer::~GJBaseGameLayer((GJBaseGameLayer *)this);
  if (lVar4 == ___stack_chk_guard) {
    return;
  }
                    
  __stack_chk_fail();
}




void PlayLayer::~PlayLayer(PlayLayer *this)

{
  ~PlayLayer((PlayLayer *)((long)&this[-1].PlayLayer_data.m_blendingColors.start + 3));
  return;
}




void PlayLayer::~PlayLayer(PlayLayer *this)

{
  ~PlayLayer(this);
  operator.delete(this);
  return;
}




void PlayLayer::~PlayLayer(PlayLayer *this)

{
  ~PlayLayer((PlayLayer *)((long)&this[-1].PlayLayer_data.m_blendingColors.start + 3));
  return;
}

