// Address: 0x140216540
// Ghidra name: FUN_140216540
// ============ 0x140216540 FUN_140216540 (size=764) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_140216540(longlong param_1)



{

  bool bVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  HWND pHVar8;

  int *piVar9;

  int *piVar10;

  undefined4 uVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  undefined4 uVar14;

  undefined2 local_58;

  short local_56;

  int local_54;

  int local_50;

  ushort local_4c;

  ushort local_4a;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  

  lVar5 = FUN_1401841a0(1,0x30);

  *(longlong *)(param_1 + 200) = lVar5;

  piVar9 = (int *)0x0;

  if (lVar5 == 0) {

LAB_14021681c:

    uVar7 = (ulonglong)piVar9 & 0xffffffffffffff00;

  }

  else {

    if (DAT_1403fdaf0 == '\0') {

      uVar6 = *(undefined8 *)(param_1 + 0x58);

    }

    else {

      uVar6 = FUN_140289c90(param_1);

    }

    if (*(char *)(param_1 + 0x94) == '\0') {

      iVar2 = (*DAT_1403fdb00)(uVar6);

      if (iVar2 != 0) {

        uVar7 = FUN_140216c30("DirectSoundCreate8",iVar2);

        return uVar7;

      }

      pHVar8 = GetDesktopWindow();

      iVar2 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 200) + 0x30))

                        ((longlong *)**(undefined8 **)(param_1 + 200),pHVar8,1);

      if (iVar2 != 0) {

        uVar7 = FUN_140216c30("DirectSound SetCooperativeLevel",iVar2);

        return uVar7;

      }

    }

    else {

      iVar2 = (*DAT_1403fdb10)(uVar6,*(longlong *)(param_1 + 200) + 0x10);

      if (iVar2 != 0) {

        uVar7 = FUN_140216c30("DirectSoundCaptureCreate8",iVar2);

        return uVar7;

      }

    }

    bVar1 = false;

    piVar9 = (int *)FUN_14015de30(*(undefined4 *)(param_1 + 0x60));

    iVar2 = *piVar9;

    piVar10 = piVar9;

    if (iVar2 != 0) {

      do {

        if ((((iVar2 == 8) || (iVar2 == 0x8010)) || (iVar2 == 0x8020)) || (iVar2 == 0x8120)) {

          iVar3 = *(int *)(param_1 + 0x68);

          *(int *)(param_1 + 0x60) = iVar2;

          bVar1 = true;

          if (100000 < iVar3) {

            iVar3 = 100000;

          }

          *(int *)(param_1 + 0x68) = iVar3;

          FUN_14015fd50(param_1);

          iVar2 = *(int *)(param_1 + 0x6c) * 8;

          if (iVar2 - 4U < 0xffffffc) {

            iVar3 = *(int *)(param_1 + 100);

            uVar4 = *(uint *)(param_1 + 0x60) & 0x100;

            local_38 = 0;

            local_48 = 0;

            uStack_40 = 0;

            local_4a = (ushort)*(uint *)(param_1 + 0x60);

            if (iVar3 < 3) {

              local_58 = 3;

              if (uVar4 == 0) {

                local_58 = 1;

              }

            }

            else {

              local_58 = 0xfffe;

              uVar11 = _DAT_140353d38;

              uVar12 = _UNK_140353d3c;

              uVar13 = _UNK_140353d40;

              uVar14 = _UNK_140353d44;

              if (uVar4 != 0) {

                uVar11 = _DAT_140353d48;

                uVar12 = _UNK_140353d4c;

                uVar13 = _UNK_140353d50;

                uVar14 = _UNK_140353d54;

              }

              local_48 = (ulonglong)CONCAT22(local_4a,0x16) & 0xffffffff00ffffff;

              uStack_40 = CONCAT44(uVar12,uVar11);

              local_38 = CONCAT44(uVar14,uVar13);

              switch(iVar3) {

              case 3:

                local_48 = CONCAT44(7,(undefined4)local_48);

                break;

              case 4:

                local_48 = CONCAT44(0x33,(undefined4)local_48);

                break;

              case 5:

                local_48 = CONCAT44(0x37,(undefined4)local_48);

                break;

              case 6:

                local_48 = CONCAT44(0x3f,(undefined4)local_48);

                break;

              case 7:

                local_48 = CONCAT44(0x13f,(undefined4)local_48);

                break;

              case 8:

                local_48 = CONCAT44(0x63f,(undefined4)local_48);

              }

            }

            local_54 = *(int *)(param_1 + 0x68);

            local_4a = local_4a & 0xff;

            local_56 = (short)iVar3;

            local_4c = (local_4a >> 3) * local_56;

            local_50 = (uint)local_4c * local_54;

            if (*(char *)(param_1 + 0x94) == '\0') {

              piVar9 = (int *)FUN_140215f20(param_1,iVar2,&local_58);

            }

            else {

              piVar9 = (int *)FUN_140215e60();

            }

            bVar1 = true;

            if ((char)piVar9 != '\0') {

              *(undefined4 *)(*(longlong *)(param_1 + 200) + 0x20) = 8;

              return 1;

            }

          }

          else {

            piVar9 = (int *)FUN_14012e850("Sound buffer size must be between %d and %d",1,0x1ffffff)

            ;

          }

        }

        iVar2 = piVar10[1];

        piVar10 = piVar10 + 1;

      } while (iVar2 != 0);

      if (bVar1) goto LAB_14021681c;

    }

    uVar7 = FUN_14012e850("%s: Unsupported audio format","directsound");

  }

  return uVar7;

}




