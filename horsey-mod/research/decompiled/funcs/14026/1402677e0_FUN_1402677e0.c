// Address: 0x1402677e0
// Ghidra name: FUN_1402677e0
// ============ 0x1402677e0 FUN_1402677e0 (size=811) ============


void FUN_1402677e0(undefined8 param_1,char *param_2,int param_3)



{

  ulonglong uVar1;

  char cVar2;

  byte bVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  longlong lVar7;

  undefined8 uVar8;

  ulonglong uVar9;

  short sVar10;

  ulonglong local_res20;

  char local_48;

  byte local_47;

  char local_46;

  ulonglong local_40;

  

  local_res20 = 0;

  cVar4 = '\x01';

  sVar10 = 0;

  if (param_3 < 5) {

    return;

  }

  local_48 = *param_2;

  local_47 = param_2[1];

  local_46 = param_2[2];

  iVar5 = FUN_140265180(&local_40,param_2 + 3,param_3 + -3);

  bVar3 = local_47;

  iVar5 = iVar5 + 3;

  lVar7 = FUN_1402652e0(param_1,local_47 & 7);

  if ((char)bVar3 < '\0') {

    cVar2 = *(char *)(lVar7 + 0x14);

    if ((bVar3 & 0x40) == 0) {

      if (local_48 != cVar2) {

        FUN_14012e2e0(7,"GIP: Received out of sequence message type %02x, expected %02x",local_48,

                      cVar2);

        FUN_1402653c0(lVar7,&local_48);

        return;

      }

      iVar6 = FUN_140265180(&local_res20,param_2 + iVar5,param_3 - iVar5);

      if (local_res20 != *(uint *)(lVar7 + 0x20)) {

        FUN_14012e2e0(7,"GIP: Received out of sequence fragment, (claimed %I64u, expected %d)",

                      local_res20);

        sVar10 = *(short *)(lVar7 + 0x16) - *(short *)(lVar7 + 0x20);

        local_40 = (ulonglong)*(uint *)(lVar7 + 0x20);

        goto LAB_140267ae5;

      }

      uVar9 = (ulonglong)*(ushort *)(lVar7 + 0x16);

      uVar1 = local_40 + local_res20;

      if (uVar9 < uVar1) {

        FUN_14012e2e0(7,"GIP: Received too long fragment, %I64u exceeds %d",uVar1,uVar9);

        FUN_1402653c0(lVar7,&local_48);

        return;

      }

      sVar10 = (*(ushort *)(lVar7 + 0x16) - (short)local_40) - (short)local_res20;

      if (local_40 == 0) {

        cVar4 = FUN_140266c10(lVar7,&local_48,*(longlong *)(lVar7 + 0x18),uVar9);

        if (*(longlong *)(lVar7 + 0x18) != 0) {

          FUN_1401841e0();

          *(undefined8 *)(lVar7 + 0x18) = 0;

        }

        *(uint *)(lVar7 + 0x20) = (uint)uVar1 & 0xffff;

        *(undefined1 *)(lVar7 + 0x14) = 0;

        uVar8 = FUN_140149350();

        *(undefined8 *)(lVar7 + 0x28) = uVar8;

        local_40 = uVar1;

      }

      else {

        FUN_1402f8e20(local_res20 + *(longlong *)(lVar7 + 0x18),param_2 + (iVar5 + iVar6));

        *(uint *)(lVar7 + 0x20) = (uint)uVar1 & 0xffff;

        uVar8 = FUN_140149350();

        *(undefined8 *)(lVar7 + 0x28) = uVar8;

        local_40 = uVar1;

      }

    }

    else {

      if ((cVar2 != '\0') && (*(longlong *)(lVar7 + 0x18) != 0)) {

        FUN_1401841e0();

        *(undefined8 *)(lVar7 + 0x18) = 0;

      }

      iVar6 = FUN_140265180(&local_res20,param_2 + iVar5,param_3 - iVar5);

      if (0x4000 < local_res20) {

        return;

      }

      param_3 = param_3 - (iVar5 + iVar6);

      *(char *)(lVar7 + 0x14) = local_48;

      *(short *)(lVar7 + 0x16) = (short)local_res20;

      if ((ulonglong)(longlong)param_3 < local_40) {

        FUN_14012e2e0(7,"GIP: Received fragment that claims to be %I64u bytes, expected %i",local_40

                      ,param_3);

        return;

      }

      if (local_res20 < local_40) {

        FUN_14012e2e0(7,"GIP: Received too long fragment, %I64u bytes, exceeds %d",local_40,

                      local_res20 & 0xffff);

        return;

      }

      uVar8 = FUN_1401841f0(local_res20 & 0xffff);

      *(undefined8 *)(lVar7 + 0x18) = uVar8;

      FUN_1402f8e20(uVar8,param_2 + (iVar5 + iVar6),local_40);

      sVar10 = *(short *)(lVar7 + 0x16) - (short)local_40;

      *(int *)(lVar7 + 0x20) = (int)local_40;

      uVar8 = FUN_140149350();

      *(undefined8 *)(lVar7 + 0x28) = uVar8;

    }

  }

  else {

    uVar1 = (longlong)iVar5 + local_40;

    if ((ulonglong)(longlong)param_3 < uVar1) {

      FUN_14012e2e0(7,

                    "GIP: Received message with erroneous length (claimed %I64u, actual %d), discarding"

                    ,uVar1,param_3);

      return;

    }

    cVar4 = FUN_140266c10(lVar7,&local_48,param_2 + iVar5,param_3 - iVar5);

  }

  if (cVar4 == '\0') {

    return;

  }

  if ((bVar3 & 0x10) == 0) {

    return;

  }

  local_40 = local_40 & 0xffffffff;

LAB_140267ae5:

  FUN_1402650d0(param_1,&local_48,local_40,sVar10);

  return;

}




