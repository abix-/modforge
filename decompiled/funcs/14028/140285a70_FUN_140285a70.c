// Address: 0x140285a70
// Ghidra name: FUN_140285a70
// ============ 0x140285a70 FUN_140285a70 (size=638) ============


undefined8 FUN_140285a70(longlong param_1,longlong param_2)



{

  int *piVar1;

  byte bVar2;

  uint uVar3;

  longlong *plVar4;

  int iVar5;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined8 local_2c;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  

  piVar1 = (int *)(*(longlong *)(param_2 + 0x148) +

                  ((longlong)*(int *)(*(longlong *)(param_2 + 0x148) + 0xc48) + 6) * 0xc);

  uVar3 = *(uint *)(param_1 + 0x18);

  if ((uVar3 & 0xc) == 0) {

    if ((uVar3 & 0x10) == 0) {

      if ((uVar3 & 3) == 0) {

        return 1;

      }

      piVar1[1] = 1;

      *(undefined1 *)(piVar1 + 2) = *(undefined1 *)(param_2 + 0x44);

      iVar5 = memcmp((void *)(param_1 + 4),&DAT_140350a40,0x10);

      if (iVar5 == 0) {

        *piVar1 = 0;

      }

      else {

        iVar5 = memcmp((void *)(param_1 + 4),&DAT_140350a50,0x10);

        if (iVar5 == 0) {

          *piVar1 = 4;

        }

        else {

          iVar5 = memcmp((void *)(param_1 + 4),&DAT_140350a60,0x10);

          if (iVar5 == 0) {

            *piVar1 = 8;

          }

          else {

            iVar5 = memcmp((void *)(param_1 + 4),&DAT_140350a70,0x10);

            if (iVar5 == 0) {

              *piVar1 = 0xc;

            }

            else {

              iVar5 = memcmp((void *)(param_1 + 4),&DAT_140350a80,0x10);

              if (iVar5 == 0) {

                *piVar1 = 0x10;

              }

              else {

                iVar5 = memcmp((void *)(param_1 + 4),&DAT_140350a90,0x10);

                if (iVar5 == 0) {

                  *piVar1 = 0x14;

                }

                else {

                  iVar5 = memcmp((void *)(param_1 + 4),&DAT_140350aa0,0x10);

                  if (iVar5 != 0) {

                    return 1;

                  }

                  *piVar1 = *(int *)(*(longlong *)(param_2 + 0x148) + 0xc4c) * 4 + 0x18;

                  piVar1 = (int *)(*(longlong *)(param_2 + 0x148) + 0xc4c);

                  *piVar1 = *piVar1 + 1;

                }

              }

            }

          }

        }

      }

      local_18 = *(undefined4 *)(param_1 + 0x18);

      local_20 = 0x18;

      local_1c = 0x10;

      local_14 = 2;

      local_10 = 0xffff8000;

      local_c = 0x7fff;

      plVar4 = *(longlong **)(*(longlong *)(param_2 + 0x148) + 0x10);

      iVar5 = (**(code **)(*plVar4 + 0x30))(plVar4,4,&local_20);

      if (iVar5 < 0) {

        return 1;

      }

      local_30 = *(undefined4 *)(param_1 + 0x18);

      local_38 = 0x14;

      local_34 = 0x10;

      local_2c = 2;

      plVar4 = *(longlong **)(*(longlong *)(param_2 + 0x148) + 0x10);

      iVar5 = (**(code **)(*plVar4 + 0x30))(plVar4,5,&local_38);

      if (iVar5 < 0) {

        return 1;

      }

      *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + 1;

    }

    else {

      piVar1[1] = 2;

      bVar2 = *(byte *)(param_2 + 0x60);

      *(byte *)(piVar1 + 2) = bVar2;

      *piVar1 = (uint)bVar2 * 4 + 0x20;

      *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;

    }

  }

  else {

    piVar1[1] = 0;

    bVar2 = *(byte *)(param_2 + 0x70);

    *(byte *)(piVar1 + 2) = bVar2;

    *piVar1 = bVar2 + 0x30;

    *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + 1;

  }

  piVar1 = (int *)(*(longlong *)(param_2 + 0x148) + 0xc48);

  *piVar1 = *piVar1 + 1;

  if (*(int *)(*(longlong *)(param_2 + 0x148) + 0xc48) != 0x100) {

    return 1;

  }

  return 0;

}




