// Address: 0x140215880
// Ghidra name: FUN_140215880
// ============ 0x140215880 FUN_140215880 (size=1226) ============


undefined1 FUN_140215880(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  undefined1 uVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  HANDLE pvVar7;

  int *piVar8;

  undefined4 uVar9;

  uint uVar10;

  char *pcVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  float fVar15;

  double dVar16;

  ulonglong local_res8;

  uint local_res10 [2];

  uint local_res18 [2];

  uint local_res20 [2];

  undefined4 local_78 [2];

  longlong local_70;

  longlong *local_68;

  undefined8 uStack_60;

  longlong *local_58;

  longlong local_50;

  int local_48;

  uint local_44;

  int local_40;

  

  lVar1 = *(longlong *)(param_1 + 200);

  plVar2 = *(longlong **)(lVar1 + 0x10);

  pvVar7 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);

  *(HANDLE *)(lVar1 + 0x28) = pvVar7;

  if (*(longlong *)(*(longlong *)(param_1 + 200) + 0x28) == 0) {

    uVar3 = FUN_1401a9ed0("WASAPI can\'t create an event handle");

    return uVar3;

  }

  uVar12 = 0;

  uVar14 = 0;

  local_70 = 0;

  iVar5 = (**(code **)(*plVar2 + 0x40))(plVar2,&local_70);

  if (iVar5 < 0) {

    uVar3 = FUN_1401a9ef0("WASAPI can\'t determine mix format",iVar5);

  }

  else {

    *(longlong *)(*(longlong *)(param_1 + 200) + 8) = local_70;

    local_44 = (uint)*(byte *)(local_70 + 2);

    iVar6 = FUN_1401a92d0();

    piVar8 = (int *)FUN_14015de30(*(undefined4 *)(param_1 + 0x60));

    iVar5 = *piVar8;

    while (iVar5 != 0) {

      piVar8 = piVar8 + 1;

      if (iVar5 == iVar6) {

        local_48 = iVar5;

        if (iVar5 != 0) {

          local_50 = 0;

          iVar5 = (**(code **)(*plVar2 + 0x48))(plVar2,&local_50,0);

          if (iVar5 < 0) {

            uVar3 = FUN_1401a9ef0("WASAPI can\'t determine minimum device period",iVar5);

            return uVar3;

          }

          if (*(int *)(param_1 + 0x68) != *(int *)(local_70 + 4)) {

            *(int *)(local_70 + 4) = *(int *)(param_1 + 0x68);

            uVar12 = 0x88000000;

            *(uint *)(local_70 + 8) =

                 (uint)(*(ushort *)(local_70 + 0xe) >> 3) * (uint)*(ushort *)(local_70 + 2) *

                 *(int *)(local_70 + 4);

          }

          local_40 = *(int *)(local_70 + 4);

          if ((*(char *)(param_1 + 0x94) != '\0') &&

             (*(char *)(*(longlong *)(param_1 + 200) + 0x46) != '\0')) {

            uVar12 = uVar12 | 0x20000;

          }

          local_58 = (longlong *)0x0;

          iVar5 = (**(code **)*plVar2)(plVar2,&DAT_1403539f0,&local_58);

          if (-1 < iVar5) {

            uStack_60 = 0;

            local_68 = (longlong *)0x10;

            cVar4 = FUN_140142940("SDL_AUDIO_DEVICE_RAW_STREAM",0);

            uVar9 = uStack_60._4_4_;

            if (cVar4 != '\0') {

              uVar9 = 1;

            }

            uStack_60 = CONCAT44(uVar9,(undefined4)uStack_60);

            iVar5 = (**(code **)(*local_58 + 0x80))(local_58,&local_68);

            if (iVar5 < 0) {

              FUN_14012e2e0(4,"IAudioClient2_SetClientProperties failed: 0x%lx",iVar5);

            }

            (**(code **)(*local_58 + 0x10))();

          }

          local_68 = (longlong *)0x0;

          iVar5 = (**(code **)*plVar2)(plVar2,&DAT_140353a00,&local_68);

          if (iVar5 < 0) {

LAB_140215bc3:

            iVar5 = (**(code **)(*plVar2 + 0x18))(plVar2,0,uVar12 | 0x40000,0,0,local_70,0);

            if (iVar5 < 0) {

              pcVar11 = "WASAPI can\'t initialize audio client";

              goto LAB_140215b8d;

            }

          }

          else {

            local_78[0] = 0;

            local_res8 = local_res8 & 0xffffffff00000000;

            local_res10[0] = 0;

            local_res18[0] = 0;

            iVar5 = (**(code **)(*local_68 + 0x90))

                              (local_68,local_70,local_78,&local_res8,local_res10,local_res18);

            if (iVar5 < 0) {

LAB_140215bb6:

              (**(code **)(*local_68 + 0x10))();

              goto LAB_140215bc3;

            }

            dVar16 = (double)thunk_FUN_1402e1d50((double)*(int *)(param_1 + 0x84) /

                                                 (double)(local_res8 & 0xffffffff));

            uVar10 = (int)(longlong)dVar16 * (int)local_res8;

            uVar13 = local_res10[0];

            if ((local_res10[0] <= uVar10) && (uVar13 = uVar10, local_res18[0] < uVar10)) {

              uVar13 = local_res18[0];

            }

            iVar5 = (**(code **)(*local_68 + 0xa0))(local_68,uVar12 | 0x40000,uVar13,local_70,0);

            if (iVar5 < 0) goto LAB_140215bb6;

            (**(code **)(*local_68 + 0x10))();

            uVar14 = uVar13;

          }

          iVar5 = (**(code **)(*plVar2 + 0x68))

                            (plVar2,*(undefined8 *)(*(longlong *)(param_1 + 200) + 0x28));

          if (iVar5 < 0) {

            pcVar11 = "WASAPI can\'t set event handle";

          }

          else {

            local_res20[0] = 0;

            iVar5 = (**(code **)(*plVar2 + 0x20))(plVar2,local_res20);

            if (iVar5 < 0) {

              pcVar11 = "WASAPI can\'t determine buffer size";

            }

            else {

              if ((int)uVar14 < 1) {

                fVar15 = (float)thunk_FUN_1402e33f0((((float)local_50 / DAT_14030dc08) *

                                                    (float)local_40) / DAT_14039ca60);

                uVar14 = (uint)fVar15;

              }

              if ((int)local_res20[0] < (int)uVar14) {

                uVar14 = local_res20[0];

              }

              cVar4 = FUN_14015d7a0(param_1,&local_48,uVar14);

              if (cVar4 == '\0') {

                return 0;

              }

              local_res8 = 0;

              *(uint *)(*(longlong *)(param_1 + 200) + 0x3c) =

                   (*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100);

              if (*(char *)(param_1 + 0x94) == '\0') {

                iVar5 = (**(code **)(*plVar2 + 0x70))(plVar2,&DAT_1403539c0,&local_res8);

                if (iVar5 < 0) {

                  pcVar11 = "WASAPI can\'t get render client service";

                }

                else {

                  *(ulonglong *)(*(longlong *)(param_1 + 200) + 0x18) = local_res8;

                  iVar5 = (**(code **)(*plVar2 + 0x50))(plVar2);

                  if (-1 < iVar5) {

                    return 1;

                  }

                  pcVar11 = "WASAPI can\'t start playback";

                }

              }

              else {

                iVar5 = (**(code **)(*plVar2 + 0x70))(plVar2,&DAT_1403539d0);

                if (iVar5 < 0) {

                  pcVar11 = "WASAPI can\'t get capture client service";

                }

                else {

                  *(ulonglong *)(*(longlong *)(param_1 + 200) + 0x20) = local_res8;

                  iVar5 = (**(code **)(*plVar2 + 0x50))(plVar2);

                  if (-1 < iVar5) {

                    FUN_140214ff0(param_1);

                    return 1;

                  }

                  pcVar11 = "WASAPI can\'t start capture";

                }

              }

            }

          }

LAB_140215b8d:

          uVar3 = FUN_1401a9ef0(pcVar11,iVar5);

          return uVar3;

        }

        break;

      }

      iVar5 = *piVar8;

    }

    uVar3 = FUN_14012e850("%s: Unsupported audio format","wasapi");

  }

  return uVar3;

}




