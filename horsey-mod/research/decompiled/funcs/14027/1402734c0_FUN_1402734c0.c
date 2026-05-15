// Address: 0x1402734c0
// Ghidra name: FUN_1402734c0
// ============ 0x1402734c0 FUN_1402734c0 (size=1319) ============


void FUN_1402734c0(undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4,

                  undefined8 param_5)



{

  byte bVar1;

  uint uVar2;

  longlong lVar3;

  ulonglong uVar4;

  short sVar5;

  ulonglong uVar6;

  uint uVar7;

  short sVar8;

  undefined8 uVar9;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  

  bVar1 = param_4[7];

  if (*(byte *)(param_3 + 0x8b) != bVar1) {

    FUN_14015ad00(param_5,param_1,2,bVar1 >> 4 & 1);

    FUN_14015ad00(param_5,param_1,0,bVar1 >> 5 & 1);

    FUN_14015ad00(param_5,param_1,1,bVar1 >> 6 & 1);

    FUN_14015ad00(param_5,param_1,3,bVar1 >> 7);

    switch(param_4[7] & 0xf) {

    case 0:

      uVar9 = 1;

      break;

    case 1:

      uVar9 = 3;

      break;

    case 2:

      uVar9 = 2;

      break;

    case 3:

      uVar9 = 6;

      break;

    case 4:

      uVar9 = 4;

      break;

    case 5:

      uVar9 = 0xc;

      break;

    case 6:

      uVar9 = 8;

      break;

    case 7:

      uVar9 = 9;

      break;

    default:

      uVar9 = 0;

    }

    FUN_14015ae90(param_5,param_1,0,uVar9);

  }

  bVar1 = param_4[8];

  if (*(byte *)(param_3 + 0x8c) != bVar1) {

    FUN_14015ad00(param_5,param_1,9,bVar1 & 1);

    FUN_14015ad00(param_5,param_1,10,bVar1 >> 1 & 1);

    FUN_14015ad00(param_5,param_1,4,bVar1 >> 4 & 1);

    FUN_14015ad00(param_5,param_1,6,bVar1 >> 5 & 1);

    FUN_14015ad00(param_5,param_1,7,bVar1 >> 6 & 1);

    FUN_14015ad00(param_5,param_1,8,bVar1 >> 7);

  }

  bVar1 = param_4[9];

  if (*(byte *)(param_3 + 0x8d) != bVar1) {

    FUN_14015ad00(param_5,param_1,5,bVar1 & 1);

    FUN_14015ad00(param_5,param_1,0xb,bVar1 >> 1 & 1);

    FUN_14015ad00(param_5,param_1,0xc,bVar1 >> 2 & 1);

    FUN_14015ad00(param_5,param_1,0xd,bVar1 >> 4 & 1);

    FUN_14015ad00(param_5,param_1,0xe,bVar1 >> 5 & 1);

    FUN_14015ad00(param_5,param_1,0xf,bVar1 >> 6 & 1);

    FUN_14015ad00(param_5,param_1,0x10,bVar1 >> 7);

  }

  sVar5 = 0x7fff;

  if ((param_4[4] == 0) && ((param_4[8] & 4) != 0)) {

    sVar8 = 0x7fff;

  }

  else {

    sVar8 = (ushort)param_4[4] * 0x101 + -0x8000;

  }

  FUN_14015aab0(param_5,param_1,4,sVar8);

  if ((param_4[5] != 0) || ((param_4[8] & 8) == 0)) {

    sVar5 = (ushort)param_4[5] * 0x101 + -0x8000;

  }

  FUN_14015aab0(param_5,param_1,5,sVar5);

  FUN_14015aab0(param_5,param_1,0,(ushort)*param_4 * 0x101 + -0x8000);

  FUN_14015aab0(param_5,param_1,1,(ushort)param_4[1] * 0x101 + -0x8000);

  FUN_14015aab0(param_5,param_1,2,(ushort)param_4[2] * 0x101 + -0x8000);

  FUN_14015aab0(param_5,param_1,3,(ushort)param_4[3] * 0x101 + -0x8000);

  if (*(char *)(param_3 + 0x23) != '\0') {

    if (*(char *)(param_3 + 0x11) == '\0') {

      uVar7 = *(uint *)(param_4 + 0x1b);

      lVar3 = (ulonglong)(uVar7 - *(int *)(param_3 + 0x80)) + *(longlong *)(param_3 + 0x78);

      *(longlong *)(param_3 + 0x78) = lVar3;

      uVar6 = (ulonglong)(lVar3 * 1000) / 3;

    }

    else {

      uVar7 = (uint)*(ushort *)(param_4 + 0x1b);

      uVar2 = uVar7 - *(int *)(param_3 + 0x80);

      if (uVar7 <= *(uint *)(param_3 + 0x80)) {

        uVar2 = uVar2 + 0x10000;

      }

      lVar3 = (ulonglong)uVar2 + *(longlong *)(param_3 + 0x78);

      *(longlong *)(param_3 + 0x78) = lVar3;

      uVar6 = lVar3 * 1000;

    }

    *(uint *)(param_3 + 0x80) = uVar7;

    local_28 = FUN_140272bc0(param_3,0,*(undefined2 *)(param_4 + 0xf));

    local_24 = FUN_140272bc0(local_28,1,*(undefined2 *)(param_4 + 0x11));

    uVar4 = 2;

    local_20 = FUN_140272bc0(local_24,2,*(undefined2 *)(param_4 + 0x13));

    FUN_14015afd0(param_5,param_1,uVar4 & 0xffffffff,uVar6,&local_28,3);

    local_28 = FUN_140272bc0(param_3,3,*(undefined2 *)(param_4 + 0x15));

    local_24 = FUN_140272bc0(local_28,4,*(undefined2 *)(param_4 + 0x17));

    local_20 = FUN_140272bc0(local_24,5,*(undefined2 *)(param_4 + 0x19));

    FUN_14015afd0(param_5,param_1,1,uVar6,&local_28,3);

  }

  return;

}




