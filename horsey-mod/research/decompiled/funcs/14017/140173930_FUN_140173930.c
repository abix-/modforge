// Address: 0x140173930
// Ghidra name: FUN_140173930
// ============ 0x140173930 FUN_140173930 (size=267) ============


undefined8

FUN_140173930(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  char cVar1;

  undefined4 uVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  undefined4 local_28;

  undefined4 local_24;

  int local_20;

  int local_1c;

  

  FUN_14016ebe0(param_2,&local_24,&local_28);

  uVar2 = FUN_14016ea50(param_2);

  puVar3 = (undefined8 *)FUN_140174d30(uVar2,"SDL.internal.window.texturedata",0);

  if ((puVar3 == (undefined8 *)0x0) || (puVar3[1] == 0)) {

    uVar4 = FUN_14012e850("No window texture data");

    return uVar4;

  }

  cVar1 = FUN_140185b30(local_24,local_28,param_4,param_3,&local_20);

  if (cVar1 == '\0') {

    return 1;

  }

  cVar1 = FUN_140156430(puVar3[1],&local_20,

                        (longlong)(local_20 * *(int *)((longlong)puVar3 + 0x1c)) +

                        (longlong)(*(int *)(puVar3 + 3) * local_1c) + puVar3[2]);

  if ((cVar1 != '\0') && (cVar1 = FUN_140153570(*puVar3,puVar3[1],0,0), cVar1 != '\0')) {

    FUN_1401512a0(*puVar3);

    return 1;

  }

  return 0;

}




