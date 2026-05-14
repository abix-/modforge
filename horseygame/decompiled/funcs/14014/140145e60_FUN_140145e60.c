// Address: 0x140145e60
// Ghidra name: FUN_140145e60
// ============ 0x140145e60 FUN_140145e60 (size=427) ============


uint * FUN_140145e60(int param_1,int param_2,int param_3)



{

  char cVar1;

  uint *puVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined8 local_res20;

  undefined4 *puVar5;

  uint in_stack_ffffffffffffffc0;

  undefined4 local_18 [4];

  

  if (param_1 < 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","width");

    return (uint *)0x0;

  }

  if (param_2 < 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","height");

    return (uint *)0x0;

  }

  if (param_3 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","format");

    return (uint *)0x0;

  }

  puVar5 = local_18;

  cVar1 = FUN_140144680(param_3,param_1,param_2,&local_res20,puVar5,

                        in_stack_ffffffffffffffc0 & 0xffffff00);

  if (((cVar1 != '\0') && (puVar2 = (uint *)FUN_1401841f0(0x128), puVar2 != (uint *)0x0)) &&

     (cVar1 = FUN_140146ca0(puVar2,param_1,param_2,param_3,(ulonglong)puVar5 & 0xffffffff00000000,0,

                            0,local_18[0],0), cVar1 != '\0')) {

    if (puVar2[2] == 0) {

      return puVar2;

    }

    if (puVar2[3] == 0) {

      return puVar2;

    }

    if (param_3 == 0x47504a4d) {

      return puVar2;

    }

    *puVar2 = *puVar2 & 0xfffffffe;

    cVar1 = FUN_140142940("SDL_SURFACE_MALLOC",0);

    if (cVar1 == '\0') {

      *puVar2 = *puVar2 | 8;

      uVar4 = FUN_14017fc90();

      lVar3 = FUN_140190080(uVar4,local_res20);

    }

    else {

      lVar3 = FUN_1401841f0(local_res20);

    }

    *(longlong *)(puVar2 + 6) = lVar3;

    if (lVar3 != 0) {

      FUN_1402f94c0(lVar3,0,local_res20);

      return puVar2;

    }

    FUN_140146010(puVar2);

  }

  return (uint *)0x0;

}




