// Address: 0x14014ff60
// Ghidra name: FUN_14014ff60
// ============ 0x14014ff60 FUN_14014ff60 (size=404) ============


ulonglong FUN_14014ff60(longlong param_1,float param_2,undefined4 param_3,undefined8 param_4)



{

  float fVar1;

  char cVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  int iVar6;

  ulonglong uVar7;

  undefined1 local_res8 [8];

  undefined8 local_res20;

  undefined1 local_48;

  undefined1 local_47;

  undefined1 local_46 [62];

  

  local_res20 = param_4;

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,2), cVar2 == '\0')))) {

    uVar7 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      uVar7 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return uVar7 & 0xffffffffffffff00;

    }

    if ((*(longlong *)(param_1 + 0x2d0) != 0) ||

       (uVar7 = FUN_140149a70(param_1), (char)uVar7 != '\0')) {

      bVar3 = FUN_14014e440(param_1,&local_47,&local_48,local_res8,local_46);

      bVar4 = FUN_1401550f0(*(undefined8 *)(param_1 + 0x2d0),local_47,local_48,local_res8[0]);

      bVar5 = FUN_140154f80(*(undefined8 *)(param_1 + 0x2d0),local_46[0]);

      fVar1 = DAT_140303750;

      bVar3 = bVar5 & bVar4 & bVar3 & 1;

      while ((bVar3 != 0 && (iVar6 = FUN_14012ed20(&local_res20,0), iVar6 != 0))) {

        bVar4 = FUN_140149c10(param_1,param_2,param_3,iVar6);

        param_2 = param_2 + fVar1;

        bVar3 = bVar3 & bVar4;

      }

      return (ulonglong)bVar3;

    }

  }

  return uVar7 & 0xffffffffffffff00;

}




