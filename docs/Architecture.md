# Ballast.Api

`PiSubmarine.Ballast.Api` defines the ballast-position control boundary.

## Responsibility

An `IController` implementation is responsible for:

- accepting a validated target ballast position in the range `[0, 1]`
- reporting the currently configured target ballast position

The intent of this boundary is to drive the inner ballast loop only.

`0.0` means zero water mass.
`1.0` means maximum ballast mass.

## Non-responsibilities

`IController` does not define:

- depth-hold logic
- target-depth control
- ticking mechanics
- motor wiring
- ballast telemetry transport

If a concrete controller requires periodic updates, it may additionally implement `Time::ITickable`, but that remains outside this API boundary.
