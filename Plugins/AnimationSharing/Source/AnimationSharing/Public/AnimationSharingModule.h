// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Modules/ModuleManager.h"
#include "UObject/GCObject.h"
#include "Engine/World.h"

class UAnimationSharingManager;
class UAnimationSharingSetup;

class ANIMATIONSHARING_API FAnimSharingModule : public FDefaultModuleImpl, public FGCObject
{
public:
	// Begin IModuleInterface overrides
	virtual void StartupModule() override;
	// End IModuleInterface overrides

	// Begin FGCObject overrides
	virtual void AddReferencedObjects( FReferenceCollector& Collector ) override;
	// End FGCObject overrides

	FORCEINLINE static UAnimationSharingManager* Get(const UWorld* World)
	{
		return WorldAnimSharingManagers.FindRef(World);
	}

	/** Creates an animation sharing manager for the given UWorld (must be a Game World) */
	static bool CreateAnimationSharingManager(UWorld* InWorld, const UAnimationSharingSetup* Setup);
private:	
	static void OnWorldCleanup(UWorld* World, bool bSessionEnded, bool bCleanupResources);
	static TMap<const UWorld*, UAnimationSharingManager*> WorldAnimSharingManagers;
};
