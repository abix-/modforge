// Address: 0x140147ec0
// Ghidra name: FUN_140147ec0
// ============ 0x140147ec0 FUN_140147ec0 (size=630) ============


longlong FUN_140147ec0(longlong param_1,float param_2)



{

  uint uVar1;

  double dVar2;

  char cVar3;

  undefined4 uVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  float local_res18;

  float local_res1c;

  undefined8 local_res20;

  undefined1 *puVar8;

  undefined8 local_58;

  undefined1 local_50 [56];

  

  lVar5 = 0;

  cVar3 = FUN_1401489c0();

  if (cVar3 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return 0;

  }

  puVar8 = local_50;

  local_res18 = (float)*(int *)(param_1 + 8) * DAT_14039ca34;

  dVar2 = (double)param_2;

  local_res1c = (float)*(int *)(param_1 + 0xc) * DAT_14039ca34;

  FUN_1401d3430(*(int *)(param_1 + 8),*(int *)(param_1 + 0xc),dVar2,&local_res18,puVar8,&local_58,

                &local_res20);

  uVar1 = *(uint *)(param_1 + 4);

  if ((uVar1 == 0) ||

     (((((uVar1 & 0xf0000000) != 0x10000000 || ((uVar1 & 0xff00) != 0x2000)) ||

       ((uVar1 & 0xf0000) != 0x60000)) &&

      ((uVar1 != 0x13000801 || (cVar3 = FUN_140148960(param_1), cVar3 == '\0')))))) {

    lVar7 = FUN_140145bb0(param_1,0x16762004);

    if (lVar7 == 0) {

      return 0;

    }

    lVar6 = FUN_1401d30e0(lVar7,dVar2,1,0,(ulonglong)puVar8 & 0xffffffff00000000,local_50,local_58,

                          local_res20,&local_res18);

    if (lVar6 != 0) {

      lVar5 = FUN_140145220(lVar6,*(undefined4 *)(param_1 + 4),*(undefined8 *)(param_1 + 0x48),

                            *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x34));

      FUN_140146010(lVar6);

    }

    FUN_140146010(lVar7);

  }

  else {

    lVar5 = FUN_1401d30e0(param_1,dVar2,1,0,(ulonglong)puVar8 & 0xffffffff00000000,local_50,local_58

                          ,local_res20,&local_res18);

  }

  if ((lVar5 != 0) &&

     (cVar3 = FUN_140174fc0(*(undefined4 *)(param_1 + 0x34),"SDL.surface.rotation"), cVar3 != '\0'))

  {

    lVar7 = FUN_140174c40(*(undefined4 *)(param_1 + 0x34),"SDL.surface.rotation",0);

    uVar4 = FUN_140146bc0(lVar5);

    FUN_1401752f0(uVar4,"SDL.surface.rotation",(float)lVar7 - param_2);

  }

  return lVar5;

}




