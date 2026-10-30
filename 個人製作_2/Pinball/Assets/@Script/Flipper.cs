using UnityEngine;
using UnityEngine.InputSystem;

[RequireComponent(typeof(HingeJoint))]
public class Flipper : MonoBehaviour
{
    [SerializeField] Key key = Key.LeftArrow;
    [SerializeField] float restAngle = 0f;
    [SerializeField] float pressedAngle = 50f;

    HingeJoint hinge;

    void Awake() => hinge = GetComponent<HingeJoint>();

    void FixedUpdate()
    {
        var spring = hinge.spring;
        bool pressed = Keyboard.current != null && Keyboard.current[key].isPressed;
        if(pressed ) { Debug.Log("pressed");}

        spring.targetPosition = pressed ? pressedAngle : restAngle;
        hinge.spring = spring;
    }
}