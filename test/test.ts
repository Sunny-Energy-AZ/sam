import { SAM } from "../src/index";
test("My Greeter", () => {
  expect(new SAM()).toBe("Hello Carl");
});
