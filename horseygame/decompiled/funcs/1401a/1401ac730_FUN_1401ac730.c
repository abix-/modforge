// Address: 0x1401ac730
// Ghidra name: FUN_1401ac730
// ============ 0x1401ac730 FUN_1401ac730 (size=838) ============


undefined8 FUN_1401ac730(longlong param_1,undefined4 *param_2)



{

  int iVar1;

  size_t sVar2;

  longlong lVar3;

  undefined8 uVar4;

  longlong lVar5;

  char *pcVar6;

  undefined4 local_res8 [4];

  longlong *local_res18;

  longlong *local_res20;

  longlong *local_38;

  longlong *local_30;

  

  pcVar6 = *(char **)(param_1 + 0x70);

  local_res20 = (longlong *)0x0;

  local_38 = (longlong *)0x0;

  local_res18 = (longlong *)0x0;

  local_30 = (longlong *)0x0;

  local_res8[0] = 0;

  sVar2 = strlen(pcVar6);

  lVar3 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,pcVar6,sVar2 + 1);

  if (lVar3 != 0) {

    iVar1 = (*DAT_1403fcde8)(&local_res20,1);

    if (iVar1 < 0) {

      pcVar6 = "MFCreateAttributes failed";

    }

    else {

      iVar1 = (**(code **)(*local_res20 + 0xc0))(local_res20,&DAT_14033cbc0,&DAT_14033cbe0);

      if (iVar1 < 0) {

        pcVar6 = "IMFAttributes_SetGUID(srctype) failed";

      }

      else {

        iVar1 = (**(code **)(*local_res20 + 200))(local_res20,&DAT_14033cbd0,lVar3);

        if (iVar1 < 0) {

          pcVar6 = "IMFAttributes_SetString(symlink) failed";

        }

        else {

          iVar1 = (*DAT_1403fcdc8)(local_res20,&local_38);

          if (iVar1 < 0) {

            pcVar6 = "MFCreateDeviceSource failed";

          }

          else {

            (**(code **)(*local_res20 + 0x10))();

            FUN_1401841e0(lVar3);

            local_res20 = (longlong *)0x0;

            lVar3 = 0;

            iVar1 = (*DAT_1403fce08)(local_38,0,&local_30);

            if (iVar1 < 0) {

              pcVar6 = "MFCreateSourceReaderFromMediaSource failed";

            }

            else {

              iVar1 = (*DAT_1403fcdf0)(&local_res18);

              if (iVar1 < 0) {

                pcVar6 = "MFCreateMediaType failed";

              }

              else {

                iVar1 = (**(code **)(*local_res18 + 0xc0))

                                  (local_res18,&DAT_14033cb10,&DAT_14033cba0);

                if (iVar1 < 0) {

                  pcVar6 = "IMFMediaType_SetGUID(major_type) failed";

                }

                else {

                  uVar4 = FUN_1401acd90(*param_2);

                  iVar1 = (**(code **)(*local_res18 + 0xc0))(local_res18,&DAT_14033cb20,uVar4);

                  if (iVar1 < 0) {

                    pcVar6 = "IMFMediaType_SetGUID(subtype) failed";

                  }

                  else {

                    iVar1 = (**(code **)(*local_res18 + 0xb0))

                                      (local_res18,&DAT_14033cb80,

                                       (longlong)(int)param_2[2] << 0x20 | (longlong)(int)param_2[3]

                                      );

                    if (iVar1 < 0) {

                      pcVar6 = "MFSetAttributeSize(frame_size) failed";

                    }

                    else {

                      iVar1 = (**(code **)(*local_res18 + 0xb0))

                                        (local_res18,&DAT_14033cb90,

                                         (longlong)(int)param_2[4] << 0x20 |

                                         (longlong)(int)param_2[5]);

                      if (iVar1 < 0) {

                        pcVar6 = "MFSetAttributeRatio(frame_rate) failed";

                      }

                      else {

                        iVar1 = (**(code **)(*local_30 + 0x38))(local_30,0xfffffffc,0,local_res18);

                        if (iVar1 < 0) {

                          pcVar6 = "IMFSourceReader_SetCurrentMediaType failed";

                        }

                        else {

                          iVar1 = FUN_1401abe00(local_res18,local_res8);

                          if (-1 < iVar1) {

                            (**(code **)(*local_res18 + 0x10))();

                            local_res18 = (longlong *)0x0;

                            lVar5 = FUN_1401841a0(1,0x18);

                            *(longlong *)(param_1 + 0x1d0) = lVar5;

                            lVar3 = 0;

                            if (lVar5 != 0) {

                              *(undefined4 *)(lVar5 + 0x10) = local_res8[0];

                              **(undefined8 **)(param_1 + 0x1d0) = local_30;

                              (**(code **)(*local_38 + 0x10))();

                              FUN_140131470(param_1,1);

                              return 1;

                            }

                            goto LAB_1401ac7aa;

                          }

                          pcVar6 = "GetDefaultStride failed";

                        }

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

    FUN_1401a9ef0(pcVar6,iVar1);

  }

LAB_1401ac7aa:

  if (local_30 != (longlong *)0x0) {

    (**(code **)(*local_30 + 0x10))();

  }

  if (local_38 != (longlong *)0x0) {

    (**(code **)(*local_38 + 0x60))();

    (**(code **)(*local_38 + 0x10))();

  }

  if (local_res18 != (longlong *)0x0) {

    (**(code **)(*local_res18 + 0x10))();

  }

  if (local_res20 != (longlong *)0x0) {

    (**(code **)(*local_res20 + 0x10))();

  }

  FUN_1401841e0(lVar3);

  return 0;

}




