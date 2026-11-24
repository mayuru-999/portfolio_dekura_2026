using UnityEngine;
using UnityEngine.InputSystem;

[RequireComponent(typeof(HingeJoint))]
public class Flipper : MonoBehaviour
{
    [SerializeField] Key key = Key.LeftArrow;
    [SerializeField] float springPower = 2000f;
    [SerializeField] float restAngle = 0f;
    [SerializeField] float pressedAngle = 50f;

    HingeJoint hinge;
    JointSpring hingeSpring;

    private void Awake()
    {
        hinge = GetComponent<HingeJoint>();
        hingeSpring = hinge.spring;

        hingeSpring.spring = springPower;
        hinge.spring = hingeSpring;
    }

    private void FixedUpdate()
    {
        var spring = hinge.spring;
        bool pressed = Keyboard.current != null && Keyboard.current[key].isPressed;

        spring.targetPosition = pressed ? pressedAngle : restAngle;
        hinge.spring = spring;
    }
}