// Address: 0x1401acdd0
// Ghidra name: FUN_1401acdd0
// ============ 0x1401acdd0 FUN_1401acdd0 (size=225) ============


ulonglong FUN_1401acdd0(longlong param_1,undefined4 param_2)



{

  undefined1 uVar1;

  byte bVar2;

  ulonglong uVar3;

  undefined8 *puVar4;

  undefined1 local_268 [608];

  

  bVar2 = 0;

  uVar3 = FUN_1401749e0(param_2,"SDL.gpu.device.create.shaders.spirv",0);

  if ((((char)uVar3 != '\0') && (*(longlong *)(param_1 + 0x210) != 0)) &&

     (uVar3 = FUN_140174130(0), (char)uVar3 != '\0')) {

    puVar4 = (undefined8 *)FUN_1401841a0(1,0xcb0);

    if (puVar4 != (undefined8 *)0x0) {

      uVar1 = FUN_1401749e0(param_2,"SDL.gpu.device.create.debugmode",0);

      *(undefined1 *)((longlong)puVar4 + 0x57c) = uVar1;

      uVar1 = FUN_1401749e0(param_2,"SDL.gpu.device.create.preferlowpower",0);

      *(undefined1 *)((longlong)puVar4 + 0x57d) = uVar1;

      bVar2 = FUN_1401bbf50(puVar4,local_268,param_2);

      if (bVar2 != 0) {

        (*(code *)puVar4[0x129])(*puVar4,0);

      }

      FUN_1401841e0(puVar4);

    }

    FUN_1401741d0();

    return (ulonglong)bVar2;

  }

  return uVar3 & 0xffffffffffffff00;

}




